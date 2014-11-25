#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <Adafruit_GFX.h>			// Source: https://github.com/adafruit/Adafruit-GFX-Library
#include <Adafruit_ST7735.h>	        // Source: https://github.com/adafruit/Adafruit-ST7735-Library
#include "WhatWayGame.h"
#include "GlobalValues.h"

WhatWayGame game;  

void setup()
{
	Wire.begin();
	delay(100); 
	game = WhatWayGame();
	game.Start();
}

void loop(void)
{ 
	game.Update(); 
	game.Render(); 
}
