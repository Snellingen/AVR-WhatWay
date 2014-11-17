#include "WhatWayGame.h"

WhatWayGame::WhatWayGame()
{
	spawner = Spawner();
	tft = new Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
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
	tft->fillRoundRect(0, -5, DISPLAY_WIDTH, 20, 7, WW_COLOR_WHITE); 
	tft->fillRoundRect(0, DISPLAY_HEIGHT -15, DISPLAY_WIDTH, 20, 7, WW_COLOR_WHITE);

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