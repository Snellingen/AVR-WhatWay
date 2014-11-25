#pragma once
#include <Arduino.h>
#include "Triangle.h"
#include "Spawner.h"
#include "Input.h"
#include "Sound.h"

#define GAME_STATE_INGAME 1
#define GAME_STATE_START 2
#define GAME_STATE_GAMEOVER 3

class WhatWayGame
{

public:
	WhatWayGame();
	~WhatWayGame() {};

public: 
	void Start();
	void Update();
	void Render();
	inline void InitDisplay();
	inline void UpdateScore(uint8_t score);
	inline void UpdateHighScore(uint8_t score);
	inline void DrawGUI();


protected: 
	Spawner spawner;
	Input input; 
	Sound sound; 
	uint8_t currentDir;

	uint8_t gameState;
	uint8_t totalScore;
	uint8_t highScore;
	uint8_t currentSpawnSize;
	uint8_t correct;

	uint16_t timeDelay;
	unsigned long time;
 
};

