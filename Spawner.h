#pragma once

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
	Triangle spawned[5];
	uint8_t spawnedSize; 


public:
	Spawner() : spawnedSize(0){};
	~Spawner() {};

	void Update(); 
	void Render(); 
	void Spawn(uint8_t amount, SpawnType spwnType, SpawnRotation spwnRotation); 
	void SpawnArrow(SpawnRotation spwnRotation);
	void SpawnCircle(SpawnRotation spwnRotation);
	void SpawnDiagonal(SpawnRotation spwnRotation);
	void SpawnLine(SpawnRotation spwnRotation);
	
};

