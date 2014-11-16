#include "WhatWayGame.h"

WhatWayGame::WhatWayGame()
{
	testTri = Triangle(20, 40, 20, 20, ST7735_RED); 
}

void WhatWayGame::Start()
{
}

void WhatWayGame::Update()
{

}

void WhatWayGame::Render(Adafruit_ST7735 *tftDisplay)
{
	testTri.Render(tftDisplay); 
}

void WhatWayGame::Exit()
{

}