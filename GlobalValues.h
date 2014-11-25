#pragma once
#include <Arduino.h>
#include <SPI.h>
#include <SD.h>
#include <Adafruit_GFX.h>				// Source: https://github.com/adafruit/Adafruit-GFX-Library
#include <Adafruit_ST7735.h>	        // Source: https://github.com/adafruit/Adafruit-ST7735-Library

#define TFT_CS 10
#define TFT_DC 9
#define TFT_RST 8                     
#define SD_CS 4

#define WW_COLOR_WHITE 61342
#define WW_COLOR_BLUE 13531
#define WW_COLOR_DARKBLUE 10730
#define WW_COLOR_RED 57959
#define WW_COLOR_GREEN 30000
#define DISPLAY_WIDTH 128
#define DISPLAY_HEIGHT 160

// LES
#define GLB_LEFT 0
#define GLB_RIGHT 1
#define GLB_UP 2
#define GLB_DOWN 3
#define GLB_NONE 4

// THIS IS TO SAVE MEMORY SPACE
static uint16_t GLB_CurrentColor = WW_COLOR_WHITE;
static uint16_t GLB_CurrentClearColor = WW_COLOR_DARKBLUE;
static uint8_t GLB_CurrentArrowWidth = 10;
static Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

static void initSD()
{
	pinMode(10, OUTPUT);
	if (!SD.begin(SD_CS))
	{
		Serial.println("FAIL");
		return;
	}
	Serial.println("OK!");
}

static uint8_t ReadSDScore()
{
	uint8_t retScore = 0;
	File file = SD.open("s.txt");
	if (file)
	{
		if (file.available())
		{
			retScore = file.read();
		}
	}
	else
	{
		Serial.println("E");
	}
	file.close();
	return retScore;
}

static void SaveToSd(int score)
{
	SD.remove("s.txt");
	File file = SD.open("s.txt", FILE_WRITE);
	if (file)
	{
		file.write((char) score);
		file.close();
	}
	else
	{
		Serial.println("F");
	}
}
