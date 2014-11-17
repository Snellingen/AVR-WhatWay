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
	int spawn = random(3); 
	int dir = random(3); 
	spawner.Spawn(5, (SpawnType)spawn, (TriDirection)dir);
	spawn++; 
	delay(200); 
}

void WhatWayGame::Render(Adafruit_ST7735 *tftDisplay)
{
	spawner.Render(tftDisplay);  
}

void WhatWayGame::Exit()
{

}