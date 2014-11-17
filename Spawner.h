#pragma once
#define DISPLAY_WIDTH 128
#define DISPLAY_HEIGHT 160
#define OFFSET 15
#define TRISIZE 10 

#include "Triangle.h"
enum SpawnType
{
	SPWN_ARROW,
	SPWN_LINE,
	SPWN_DIAGONAL,
	SPWN_CIRCLE
};

enum SpawnRotation
{
	SPWN_RIGHT,
	SPWN_LEFT,
	SPWN_UP,
	SPWN_DOWN
};

class Spawner
{

private:
	Triangle rightSpawn; 
	Triangle spawned[5];
	uint8_t spawnedSize; 

	void SpawnArrow(TriDirection correctDirection, uint8_t size, uint16_t posX, uint16_t posY);
	void SpawnCircle(TriDirection correctDirection, uint8_t size, uint16_t posX, uint16_t posY);
	void SpawnDiagonal(TriDirection correctDirection, uint8_t size, uint16_t posX, uint16_t posY);
	void SpawnLine(TriDirection correctDirection, uint8_t size, uint16_t posX, uint16_t posY);

	void UpdateValue(Triangle *tri, uint16_t posX, uint16_t posY, TriDirection dir); 

public:
	Spawner() : spawnedSize(0)
	{
		// FILL ARRAY.
		for (uint8_t i = 0; i < 5; i++)
		{
			spawned[i] = Triangle(); 
		}
		rightSpawn = Triangle(); 
	};
	~Spawner() {};

	void Update(); 
	void Render(Adafruit_ST7735 *tftDisplay);
	void Spawn(uint8_t amount, SpawnType spwnType, TriDirection correctDirection);
	
	
};

