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
	Serial.begin(9600);
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
	Serial.print("Initializing SD card...");
	if (!SD.begin(SD_CS))
	{
		Serial.println("failed!");
		return;
	}
	Serial.println("OK!");
}