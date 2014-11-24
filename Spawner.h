#pragma once
#define OFFSET 15
#include "GlobalValues.h"
#include <Arduino.h>
#include "Triangle.h"

enum SpawnType
{
	SPWN_ARROW,
	SPWN_LINE,
	SPWN_DIAGONAL,
	SPWN_CIRCLE
};


class Spawner
{

private:
	Triangle rightSpawn; 
	Triangle spawned[5];
	uint8_t spawnedSize; 
	boolean spawnSet;

	void SpawnArrow(GlobalDirection* correctDirection, uint8_t size, uint16_t posX, uint16_t posY);
	void SpawnCircle(GlobalDirection* correctDirection, uint8_t size, uint16_t posX, uint16_t posY);
	void SpawnDiagonal(GlobalDirection* correctDirection, uint8_t size, uint16_t posX, uint16_t posY);
	void SpawnLine(GlobalDirection* correctDirection, uint8_t size, uint16_t posX, uint16_t posY);
	void UpdateValue(Triangle *tri, uint16_t posX, uint16_t posY, GlobalDirection dir); 

public:
	Spawner() : spawnedSize(0)
	{
		// FILL ARRAY.
		for (uint8_t i = 0; i < 5; i++)
		{
			spawned[i] = Triangle(); 
		}
		rightSpawn = Triangle(); 
		spawnSet = false; 

		// This is so that the game is not always the same. 
		randomSeed(analogRead(A0));
	};
	~Spawner() {};

	GlobalDirection currentRightDirection;
	void Update(); 
	void Render(Adafruit_ST7735 *tftDisplay);
	void Spawn(uint8_t amount, SpawnType spwnType, GlobalDirection correctDirection);
	void Clear(Adafruit_ST7735 *tftDisplay);
	void RandomSpawn(uint8_t amount); 
	
};

