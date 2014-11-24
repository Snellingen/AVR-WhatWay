#pragma once
#include <Arduino.h>
#include "Triangle.h"
#include "Spawner.h"
#include "Input.h"
#include "Sound.h"
//#include <SPI.h>
//#include <SD.h>
#include <Adafruit_GFX.h>				// Source: https://github.com/adafruit/Adafruit-GFX-Library
#include <Adafruit_ST7735.h>	        // Source: https://github.com/adafruit/Adafruit-ST7735-Library

#define GAME_STATE_INGAME 1
#define GAME_STATE_START 2
#define GAME_STATE_GAMEOVER 3

#define TFT_CS 10
#define TFT_DC 9
#define TFT_RST 8                     
#define SD_CS 4

class WhatWayGame
{

public:
	WhatWayGame();
	~WhatWayGame() {};

public: 
	void Start(boolean hasSD);
	void Update();
	void Render();
	inline void InitDisplay();
	inline void UpdateScore(uint16_t score);
	inline void UpdateHighScore(uint16_t score);
	inline void DrawGUI();


protected: 
	uint16_t CalculateScore(const uint16_t* timeDelay, const uint8_t* streak, const uint8_t* arrowCount);
	Spawner spawner;
	Input input; 
	Adafruit_ST7735 *tft;
	Sound sound; 
	uint8_t currentDir;

	uint8_t gameState;
	uint8_t streak;
	uint16_t totalScore;
	uint16_t highScore;
	uint8_t currentSpawnSize;
	uint8_t correct;

	boolean SDReady; 

	unsigned long time;  
 
};

