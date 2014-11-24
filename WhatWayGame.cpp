#include "WhatWayGame.h"

WhatWayGame::WhatWayGame()
{
	tft = new Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
	spawner = Spawner();
	GUI = GUIHandler(tft);
	input = Input();
	sound = Sound();
	correct = 0;
	currentSpawnSize = 1;
	gameState = GAME_STATE_START;
	totalScore = 0;
	highScore = 0; // GET FOR SD CARD
	time = 0; 
	streak = 0; 
}

void WhatWayGame::Start()
{
	InitDisplay();
	tft->setRotation(2);
	tft->fillScreen(WW_COLOR_DARKBLUE);
	GUI.DrawInGameGUI();
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
			}
			else streak = 0; 

			totalScore += CalculateScore(&timeDelay, &streak, &currentSpawnSize); 

			GUI.UpdateScore(totalScore); 

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
				GUI.UpdateHighScore(highScore);
			}

			GUI.UpdateScore(0);
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

uint16_t WhatWayGame::CalculateScore(const uint16_t *timeDelay, const uint16_t *streak, const uint8_t *arrowCount)
{
	// Capping timebonus to 10 so you don't get absurd amount of points when really fast.

	int timeBonus = 10 - ((*timeDelay) / 100); 
	return  (timeBonus < 0 ? 0 : timeBonus * (*streak) * (*arrowCount)) / 4;
}

void WhatWayGame::Render()
{
	spawner.Render(tft);
}

void WhatWayGame::Exit()
{

}

void WhatWayGame::InitDisplay()
{
	tft->initR(INITR_BLACKTAB);
	delay(500);
	tft->fillScreen(ST7735_BLACK);
}