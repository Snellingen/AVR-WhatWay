#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <Adafruit_GFX.h>		// Source: https://github.com/adafruit/Adafruit-GFX-Library
#include <Adafruit_ST7735.h>	// Source: https://github.com/adafruit/Adafruit-ST7735-Library
#include "WhatWayGame.h"

#define SD_CS	 4
#define TFT_CS	10
#define TFT_RST  8                      
#define TFT_DC	 9

const int chipSelect = 4;
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

WhatWayGame game; 

void setup()
{
	Serial.begin(9600);
	Wire.begin();
	initDisplay(); 
	initSD();
	
	game = WhatWayGame(); 
	game.Start(); 
}

void loop(void)
{
	game.Update(); 
	game.Render(&tft); 
}

void initDisplay()
{
	tft.initR(INITR_BLACKTAB);
	delay(500);
	tft.fillScreen(ST7735_BLACK);
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