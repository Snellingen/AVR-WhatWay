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
	GlobalDirection currentDir;

	switch (gameState)
	{
	case GAME_STATE_START:
		correct = 0;
		currentSpawnSize = 1;
		spawner.RandomSpawn(currentSpawnSize);
		gameState = GAME_STATE_INGAME; 
		break;
	case GAME_STATE_INGAME:

		currentDir = input.GetDirection();
		if (currentDir == spawner.currentRightDirection)
		{
			correct++;
			sound.PlayPositiveSound(); 
			if (correct > 10)
			{
				spawner.RandomSpawn(currentSpawnSize);
				currentSpawnSize += 2;
				correct = 0;
			}
		}
		else if (currentDir != GLB_NONE)
		{
			sound.PlayNegativeSound(); 
		}

		break;
	case GAME_STATE_MENU:
		break;
	}

	sound.Update(); 
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