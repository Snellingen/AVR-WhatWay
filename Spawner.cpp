#include "Spawner.h"

inline void Spawner::Spawn(uint8_t amount, uint8_t spwnType, uint8_t correctDirection)
{
	uint16_t posX = (DISPLAY_WIDTH / 2);
	uint16_t posY = (DISPLAY_HEIGHT / 2);
	currentRightDirection = correctDirection; 
	spawnedSize = 0;
	if (amount == 1)
	{
		UpdateValue(&rightSpawn, posX, posY, correctDirection);
		return;
	}
	if (amount > 5) amount = 5; 

	
	switch (spwnType)
	{
	case SPWN_ARROW:
		SpawnArrow(&correctDirection, amount, posX, posY);
		break;
	case SPWN_DIAGONAL:
		SpawnDiagonal(&correctDirection, amount, posX, posY);
		break;
	case SPWN_LINE:
		SpawnLine(&correctDirection, amount, posX, posY);
		break;
	case SPWN_CIRCLE:
		SpawnCircle(&correctDirection, amount, posX, posY);
		break;
	default:
		break;
	}
}
void Spawner::RandomSpawn(uint8_t amount)
{
	Spawn(amount, random(4), random(4));
}
inline void Spawner::SpawnArrow(uint8_t *correctDirection, uint8_t size, uint16_t posX, uint16_t posY)
{
	uint8_t flockRotation = (uint8_t) random(4);
	uint8_t defaultRotation = (uint8_t) random(4);


	switch (flockRotation)
	{
	case GLB_RIGHT:
		posX -= OFFSET / 2 * size / 4;
		posY += OFFSET * size / 2;
		break;
	case GLB_LEFT:
		posX += OFFSET / 2 * size / 4;
		posY += OFFSET * size / 2;
		break;
	case GLB_UP:
		posX += OFFSET * size / 2;
		posY += OFFSET / 2 * size / 4;
		break;
	case GLB_DOWN:
		posX += OFFSET * size / 2;
		posY -= OFFSET / 2 * size / 4;
		break;
	default:
		break;
	}

	uint8_t randomNum = random(size);
	for (uint8_t i = 0; i < size; i++)
	{
		if (randomNum == i)
		{
			UpdateValue(&rightSpawn, posX, posY, *correctDirection);
		}
		else
		{
			UpdateValue(&spawned[spawnedSize], posX, posY, defaultRotation);
			spawnedSize++;
		}

		switch (flockRotation)
		{
		case GLB_RIGHT:
			posX += i < (size / 2) ? OFFSET : -OFFSET;
			posY -= OFFSET;
			break;
		case GLB_LEFT:
			posX += i < (size / 2) ? -OFFSET : OFFSET;
			posY -= OFFSET;
			break;
		case GLB_DOWN:
			posY += i < (size / 2) ? -OFFSET : OFFSET;
			posX -= OFFSET;
			break;
		case GLB_UP:
			posY += i < (size / 2) ? OFFSET : -OFFSET;
			posX -= OFFSET;
			break;
		default:
			break;
		}
	}
}
inline void Spawner::SpawnCircle(uint8_t *correctDirection, uint8_t size, uint16_t posX, uint16_t posY)
{
	uint8_t defaultRotation = (uint8_t) random(4);
	uint8_t randomNum = random(size);

	for (uint8_t i = 0; i < size; i++)
	{
		float radius = (size * OFFSET) / PI;
		float radians = ((2 * PI) / size) * i;
		uint16_t x = posX + radius * sin(radians);
		uint16_t y = posY + radius * cos(radians);

		if (randomNum == i)
		{
			UpdateValue(&rightSpawn, x, y, *correctDirection);
		}
		else
		{
			UpdateValue(&spawned[spawnedSize], x, y, defaultRotation);
			spawnedSize++;
		}
	}

}
inline void Spawner::SpawnDiagonal(uint8_t *correctDirection, uint8_t size, uint16_t posX, uint16_t posY)
{
	uint8_t flockRotation = (uint8_t) random(4);
	uint8_t defaultRotation = (uint8_t) random(4);

	posX += flockRotation == GLB_LEFT || flockRotation == GLB_DOWN
		? -(OFFSET * size / 2)
		: OFFSET  * size / 2;
	posY += (OFFSET * size / 2);

	uint8_t randomNum = random(size);
	for (uint8_t i = 0; i < size; i++)
	{
		if (randomNum == i)
		{
			UpdateValue(&rightSpawn, posX, posY, *correctDirection);
		}
		else
		{
			UpdateValue(&spawned[spawnedSize], posX, posY, defaultRotation);
			spawnedSize++;
		}
		posX += flockRotation == GLB_LEFT || flockRotation == GLB_DOWN
			? OFFSET : -OFFSET;
		posY -= OFFSET;
	}
}
inline void Spawner::SpawnLine(uint8_t *correctDirection, uint8_t size, uint16_t posX, uint16_t posY)
{
	uint8_t flockRotation = (uint8_t) random(4);
	uint8_t defaultRotation = (uint8_t) random(4);

	if (flockRotation == GLB_LEFT || flockRotation == GLB_RIGHT)
	{
		posX -= (OFFSET * size / 2);
	}
	else posY += (OFFSET * size / 2);
	uint8_t randomNum = random(size);
	for (uint8_t i = 0; i < size; i++)
	{
		if (randomNum == i)
		{
			UpdateValue(&rightSpawn, posX, posY, *correctDirection);
		}
		else
		{
			UpdateValue(&spawned[spawnedSize], posX, posY, defaultRotation);
			spawnedSize++;
		}

		if (flockRotation == GLB_LEFT || flockRotation == GLB_RIGHT)
			posX += OFFSET;
		else posY -= OFFSET;
	}
}

void Spawner::Render(Adafruit_ST7735 *tftDisplay)
{
	if (spawnSet)
	{
		rightSpawn.Clear(tftDisplay);

		for (uint8_t i = 0; i < spawnedSize; i++)
		{
			spawned[i].Clear(tftDisplay);
		}

		rightSpawn.Render(tftDisplay, false);
		for (uint8_t i = 0; i < spawnedSize; i++)
		{
			spawned[i].Render(tftDisplay, false);
		}
		spawnSet = false; 
	}

}
inline void Spawner::UpdateValue(Triangle *tri, uint16_t posX, uint16_t posY, uint8_t dir)
{
	tri->SetX(posX);
	tri->SetY(posY);
	tri->SetDirection(dir);
	tri->HasMoved = true;
	spawnSet = true;

}
void Spawner::Clear(Adafruit_ST7735 *tftDisplay)
{
	rightSpawn.Clear(tftDisplay); 
	for (uint8_t i = 0; i < spawnedSize; i++)
	{
		spawned[i].Clear(tftDisplay); 
	}
}

