#include "WhatWayGame.h"

WhatWayGame::WhatWayGame()
{
	tft = new Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
	spawner = Spawner();
	GUI = GUIHandler(tft); 
	input = Input(); 

	gameState = GAME_STATE_INGAME; 

	Serial.begin(9600); 
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
	case GAME_STATE_INGAME:
		
		spawner.RandomSpawn(3);

		/*Serial.print("X = "); 
		Serial.print(input.GetXAxis()); 
		Serial.print(" Y = "); 
		Serial.println(input.GetYAxis()); */

		GlobalDirection currentDirt = input.GetDirection(); 

	case GAME_STATE_MENU: 
		break; 
	default:
		break;
	}
	
	delay(200);
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