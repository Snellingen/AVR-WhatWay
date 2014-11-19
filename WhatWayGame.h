#pragma once
#include <Arduino.h>
#include "Triangle.h"
#include "Spawner.h"

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

private: 
	Spawner spawner;
	GUIHandler GUI;
	Adafruit_ST7735 *tft;
 
};

