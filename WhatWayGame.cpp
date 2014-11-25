#include "WhatWayGame.h"

WhatWayGame::WhatWayGame()
{
	spawner = Spawner();
	input = Input();
	sound = Sound();
	correct = 0;
	currentSpawnSize = 1;
	gameState = GAME_STATE_START;
	totalScore = 0;
	time = 0;
	highScore = 0;
	
}

void WhatWayGame::Start()
{
	InitDisplay();
	initSD();
	highScore = ReadSDScore();
	tft.setRotation(2);
	tft.fillScreen(WW_COLOR_DARKBLUE);
	DrawGUI();
	UpdateHighScore(highScore);
}

void WhatWayGame::Update()
{
	switch (gameState)
	{
	case GAME_STATE_START:
		correct = 0;
		currentSpawnSize = 1;
		totalScore = 0;
		spawner.RandomSpawn(currentSpawnSize);
		time = millis();
		gameState = GAME_STATE_INGAME;
		break;
	case GAME_STATE_INGAME:

		currentDir = input.GetDirectionOnce();

		if (currentDir == GLB_NONE) break;
		timeDelay = millis() - time;
		if (currentDir == spawner.currentRightDirection && timeDelay < 2000)
		{
			correct++;
			if (timeDelay < 700)
			{
				if (totalScore < 254)
					totalScore += 1;
			}

			UpdateScore(totalScore);

			if (correct > 5)
			{
				if (currentSpawnSize < 5)
					currentSpawnSize += 2;
				correct = 0;
			}

			spawner.RandomSpawn(currentSpawnSize);
			time = millis();

			sound.PlayPositiveSound(); 
		}
		else
		{
			if (totalScore > highScore)
			{
				highScore = totalScore;
				UpdateHighScore(highScore);

				SaveToSd(highScore); 
				
			}

			UpdateScore(0);
			spawner.Clear(&tft);
			gameState = GAME_STATE_GAMEOVER;
			tft.setCursor(10, DISPLAY_HEIGHT / 2 - 10);
			tft.setTextColor(WW_COLOR_WHITE);
			tft.setTextSize(2);
			tft.print("GAME OVER");
			tft.setTextSize(1);

			sound.PlayNegativeSound();

		}
		break;

	case GAME_STATE_GAMEOVER:

		if (input.ButtonClick())
		{
			tft.fillRect(10, DISPLAY_HEIGHT / 2 - 10, DISPLAY_WIDTH - 20, 20, WW_COLOR_DARKBLUE);
			gameState = GAME_STATE_START;
		}

		break;
	}
	sound.Update();
}

void WhatWayGame::Render()
{
	spawner.Render(&tft);
}

inline void WhatWayGame::UpdateScore(uint8_t score)
{
	tft.fillRect(50, 5, 50, 10, WW_COLOR_WHITE);
	tft.setCursor(50, 5);
	tft.setTextColor(WW_COLOR_DARKBLUE);
	tft.print(score);
}

inline void WhatWayGame::UpdateHighScore(uint8_t score)
{
	tft.fillRect(60, DISPLAY_HEIGHT - 11, 50, 10, WW_COLOR_WHITE);
	tft.setCursor(60, DISPLAY_HEIGHT - 11);
	tft.setTextColor(WW_COLOR_DARKBLUE);
	tft.print(score);
}

inline void WhatWayGame::DrawGUI()
{
	tft.fillRoundRect(0, -3, DISPLAY_WIDTH, 20, 7, WW_COLOR_WHITE);
	tft.fillRoundRect(0, DISPLAY_HEIGHT - 15, DISPLAY_WIDTH, 20, 7, WW_COLOR_WHITE);
	tft.setCursor(10, 5);
	tft.setTextColor(WW_COLOR_DARKBLUE);
	tft.print("Score:");
	tft.setCursor(10, DISPLAY_HEIGHT - 11);
	tft.print("HiScore:");
}

inline void WhatWayGame::InitDisplay()
{
	tft.initR(INITR_BLACKTAB);
	delay(500);
	tft.fillScreen(ST7735_BLACK);
}