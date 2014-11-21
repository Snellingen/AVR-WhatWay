#pragma once
#include <Arduino.h>
#include "Triangle.h"
#include "Spawner.h"
#include "Input.h"
#include "GUIHandler.h"
#include "Sound.h"

#define GAME_STATE_MENU 0
#define GAME_STATE_INGAME 1
#define GAME_STATE_START 2

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
	Spawner spawner;
	GUIHandler GUI;
	Input input; 
	Adafruit_ST7735 *tft;
	Sound sound; 

	uint8_t gameState;
	uint8_t currentSpawnSize;
	uint8_t correct; 
 
};

