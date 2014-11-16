#include "WhatWayGame.h"

WhatWayGame::WhatWayGame()
{
	testTri1 = Triangle(0, 10, 10, 10, LEFT, ST7735_RED); 

}

void WhatWayGame::Start()
{
}

void WhatWayGame::Update()
{

}

void WhatWayGame::Render(Adafruit_ST7735 *tftDisplay)
{
	testTri1.Render(tftDisplay);
}

void WhatWayGame::Exit()
{

}