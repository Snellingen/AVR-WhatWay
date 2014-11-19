#include "WhatWayGame.h"

WhatWayGame::WhatWayGame()
{
	tft = new Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
	spawner = Spawner();
	GUI = GUIHandler(tft); 
	
}

void WhatWayGame::Start()
{ 
	InitDisplay();

	tft->fillScreen(WW_COLOR_DARKBLUE); 
}

void WhatWayGame::Update()
{ 
	int spawn = random(3); 
	int dir = random(3); 
	spawner.Spawn(5, (SpawnType)spawn, (TriDirection)dir);
	spawn++; 
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