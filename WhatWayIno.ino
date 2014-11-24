#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <Adafruit_GFX.h>			// Source: https://github.com/adafruit/Adafruit-GFX-Library
#include <Adafruit_ST7735.h>	        // Source: https://github.com/adafruit/Adafruit-ST7735-Library
#include "WhatWayGame.h"

WhatWayGame game;  

void setup()
{
	Serial.begin(9600); 
	Wire.begin();
	delay(100); 

	////pinMode(10, OUTPUT);
	//if (!SD.begin(SD_CS))
	//{
	//	/*hasSD = false;*/
	//	Serial.println("Failed to initialize.");
	//	game = WhatWayGame();
	//	game.Start(false);
	//	return; 
	//}
	//Serial.println("Success!");

	game = WhatWayGame();
	game.Start(true);
}

void loop(void)
{ 
	game.Update(); 
	game.Render(); 
}
