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

	inline void SpawnArrow(uint8_t* correctDirection, uint8_t size, uint16_t posX, uint16_t posY);
	inline void SpawnCircle(uint8_t* correctDirection, uint8_t size, uint16_t posX, uint16_t posY);
	inline void SpawnDiagonal(uint8_t* correctDirection, uint8_t size, uint16_t posX, uint16_t posY);
	inline void SpawnLine(uint8_t* correctDirection, uint8_t size, uint16_t posX, uint16_t posY);
	inline void UpdateValue(Triangle *tri, uint16_t posX, uint16_t posY, uint8_t dir); 

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

	uint8_t currentRightDirection;
	void Render(Adafruit_ST7735 *tftDisplay);
	void Spawn(uint8_t amount, SpawnType spwnType, uint8_t correctDirection);
	void Clear(Adafruit_ST7735 *tftDisplay);
	void RandomSpawn(uint8_t amount); 
	
};

