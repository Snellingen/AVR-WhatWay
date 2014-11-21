#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <Adafruit_GFX.h>		// Source: https://github.com/adafruit/Adafruit-GFX-Library
#include <Adafruit_ST7735.h>	// Source: https://github.com/adafruit/Adafruit-ST7735-Library
#include "WhatWayGame.h"

#define SD_CS	 4

const int chipSelect = 4;
WhatWayGame game;  

void setup()
{
	Wire.begin();
	initSD();

	game = WhatWayGame(); 
	game.Start();
}

void loop(void)
{ 
	game.Update(); 
	game.Render(); 
}

void initSD()
{
	if (!SD.begin(SD_CS))
	{
		// FAIL
		return;
	}
	// OK
}