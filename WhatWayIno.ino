#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <Adafruit_GFX.h>		// Source: https://github.com/adafruit/Adafruit-GFX-Library
#include <Adafruit_ST7735.h>	// Source: https://github.com/adafruit/Adafruit-ST7735-Library

#include "Triangle.h"

#define SD_CS	 4
#define TFT_CS	10
#define TFT_RST  8                      
#define TFT_DC	 9

Triangle testTriangle; 
int tx1, tx2, tx3, ty1, ty2, ty3; 

const int chipSelect = 4;
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void setup()
{
	Serial.begin(9600);
	Wire.begin();
	initDisplay(); 
	initSD();
	testTriangle.x = 0; 
	testTriangle.y = tft.height() / 3; 
	testTriangle.Height = 10;
	testTriangle.Width = 15;
	testTriangle.oldX = testTriangle.oldY = 0; 
	testTriangle.moved = false; 

	DrawTriangle(&testTriangle, ST7735_RED, testTriangle.moved, &tft);
}



void loop(void)
{
	MoveTriangle(&testTriangle, 3, 1); 
	if (testTriangle.x > tft.width())
	{
		testTriangle.x = 0;
		testTriangle.y = tft.width() / 3; 
	}
	DrawTriangle(&testTriangle, ST7735_RED, true, &tft); 
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