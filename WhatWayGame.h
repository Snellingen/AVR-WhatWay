#pragma once
#include <Arduino.h>
#include "Triangle.h"

class WhatWayGame
{

public:
	WhatWayGame();
	~WhatWayGame() {};

public: 
	void Start();
	void Update(); 
	void Render(Adafruit_ST7735 *tftDisplay);
	void Exit(); 

private: 
	Triangle testTri; 
};

