#include "WhatWayGame.h"

WhatWayGame::WhatWayGame()
{
	tft = new Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
	spawner = Spawner();
	input = Input();
	sound = Sound();
	correct = 0;
	currentSpawnSize = 1;
	gameState = GAME_STATE_START;
	totalScore = 0;
	time = 0;
	streak = 0;
	highScore = 0;
	
}

void WhatWayGame::Start(boolean hasSD)
{
	InitDisplay();
	tft->setRotation(2);
	tft->fillScreen(WW_COLOR_DARKBLUE);
	DrawGUI();
	UpdateHighScore(highScore);
	SDReady = hasSD;

	/*if (SDReady)
	{
		File scoreFile = SD.open("score.txt");
		if (scoreFile)
		{
			if (scoreFile.available())
			{
				highScore = scoreFile.read();
			}
			scoreFile.close();
		}
		else
		{
			Serial.println("Failed to open score.txt (1), rewrite.");

			scoreFile = SD.open("score.txt", FILE_WRITE);
			if (scoreFile)
			{
				scoreFile.print((char) highScore);
				scoreFile.close();
			}
		}
	}*/
}

void WhatWayGame::Update()
{
	switch (gameState)
	{
	case GAME_STATE_START:
		correct = 0;
		currentSpawnSize = 1;
		streak = 0;
		totalScore = 0;
		spawner.RandomSpawn(currentSpawnSize);
		time = millis();
		gameState = GAME_STATE_INGAME;
		break;
	case GAME_STATE_INGAME:

		currentDir = input.GetDirectionOnce();

		if (currentDir == GLB_NONE) break;

		if (currentDir == spawner.currentRightDirection)
		{
			correct++;
			sound.PlayPositiveSound();
			uint16_t timeDelay = millis() - time;
			if (timeDelay < 1000)
			{
				streak++;
				if (streak >= 200) streak = 200;
			}
			else streak = 0;

			totalScore += CalculateScore(&timeDelay, &streak, &currentSpawnSize);

			UpdateScore(totalScore);

			if (correct > 10)
			{
				currentSpawnSize += 2;
				correct = 0;
			}

			spawner.RandomSpawn(currentSpawnSize);
			time = millis();
		}
		else
		{
			if (totalScore > highScore)
			{
				highScore = totalScore;
				UpdateHighScore(highScore);

				/*if (SDReady)
				{
					File scoreFile = SD.open("score.txt", FILE_WRITE);
					if (scoreFile)
					{
						scoreFile.print((char) highScore);
						scoreFile.close();
					}
					else
					{
						Serial.println("Failed open score.txt (write score).");
					}
				}*/
			}

			UpdateScore(0);
			sound.PlayNegativeSound();
			spawner.Clear(tft);
			gameState = GAME_STATE_GAMEOVER;

			/*
				Even if this is not in the GAME_STATE_GAMEOVER
				I still draw it on this state instead of the game over state.
				This is because I only want it drawn once without using any extra variables.
				*/
			tft->setCursor(10, DISPLAY_HEIGHT / 2 - 10);
			tft->setTextColor(WW_COLOR_WHITE);
			tft->setTextSize(2);
			tft->print("GAME OVER");
			tft->setTextSize(1);
			tft->setCursor(20, DISPLAY_HEIGHT / 2 + 10);
			tft->print("Score: ");
			tft->print(totalScore);
			tft->setTextSize(1);
		}
		break;

	case GAME_STATE_GAMEOVER:

		if (input.ButtonClick())
		{
			tft->fillRect(10, DISPLAY_HEIGHT / 2 - 10, DISPLAY_WIDTH - 20, 20, WW_COLOR_DARKBLUE);
			tft->fillRect(20, DISPLAY_HEIGHT / 2 + 10, DISPLAY_WIDTH - 40, 10, WW_COLOR_DARKBLUE);
			gameState = GAME_STATE_START;
		}

		break;
	}
	sound.Update();
}

inline uint16_t WhatWayGame::CalculateScore(const uint16_t *timeDelay, const uint8_t *streak, const uint8_t *arrowCount)
{
	// Capping timebonus to 10 so you don't get absurd amount of points when really fast.

	int timeBonus = 10 - ((*timeDelay) / 100);
	return  (timeBonus < 0 ? 0 : timeBonus * (*streak) * (*arrowCount)) / 4;
}

void WhatWayGame::Render()
{
	spawner.Render(tft);
}

inline void WhatWayGame::UpdateScore(uint16_t score)
{
	tft->fillRect(50, 5, 50, 10, WW_COLOR_WHITE);
	tft->setCursor(50, 5);
	tft->setTextColor(WW_COLOR_DARKBLUE);
	tft->print(score);
}

inline void WhatWayGame::UpdateHighScore(uint16_t score)
{
	tft->fillRect(60, DISPLAY_HEIGHT - 11, 50, 10, WW_COLOR_WHITE);
	tft->setCursor(60, DISPLAY_HEIGHT - 11);
	tft->setTextColor(WW_COLOR_DARKBLUE);
	tft->print(score);
}

inline void WhatWayGame::DrawGUI()
{
	tft->fillRoundRect(0, -3, DISPLAY_WIDTH, 20, 7, WW_COLOR_WHITE);
	tft->fillRoundRect(0, DISPLAY_HEIGHT - 15, DISPLAY_WIDTH, 20, 7, WW_COLOR_WHITE);
	tft->setCursor(10, 5);
	tft->setTextColor(WW_COLOR_DARKBLUE);
	tft->print("Score:");
	tft->setCursor(10, DISPLAY_HEIGHT - 11);
	tft->print("HiScore:");
}

inline void WhatWayGame::InitDisplay()
{
	tft->initR(INITR_BLACKTAB);
	delay(500);
	tft->fillScreen(ST7735_BLACK);
}