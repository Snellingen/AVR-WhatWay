#include "WhatWayGame.h"

WhatWayGame::WhatWayGame()
{
	spawner = Spawner();
}

void WhatWayGame::Start()
{
}

void WhatWayGame::Update()
{
	spawner.Spawn(5, SPWN_ARROW, TRI_LEFT);
	delay(200); 
}

void WhatWayGame::Render(Adafruit_ST7735 *tftDisplay)
{
	spawner.Render(tftDisplay);  
}

void WhatWayGame::Exit()
{

}