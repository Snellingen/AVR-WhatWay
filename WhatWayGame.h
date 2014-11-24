#pragma once
#include <Arduino.h>
#include "Triangle.h"
#include "Spawner.h"
#include "Input.h"
#include "GUIHandler.h"
#include "Sound.h"

#define GAME_STATE_INGAME 1
#define GAME_STATE_START 2
#define GAME_STATE_GAMEOVER 3

#define TFT_CS	10
#define TFT_RST  8                      
#define TFT_DC	 9

class WhatWayGame
{

public:
	WhatWayGame();
	~WhatWayGame() {};

public: 
	void Start();
	void Update();
	void Render();
	void Exit(); 
	void InitDisplay();


protected: 
	uint16_t CalculateScore(const uint16_t* timeDelay, const uint16_t* streak, const uint8_t* arrowCount);
	Spawner spawner;
	GUIHandler GUI;
	Input input; 
	Adafruit_ST7735 *tft;
	Sound sound; 

	uint8_t gameState;
	GlobalDirection currentDir;
	uint8_t currentSpawnSize;
	uint8_t correct;
	uint16_t streak; 

	uint16_t totalScore;
	uint16_t highScore; 

	unsigned long time;  
 
};

