#include "Spawner.h"

void Spawner::Spawn(uint8_t amount, SpawnType spwnType, TriDirection correctDirection)
{
	uint16_t posX = (DISPLAY_WIDTH / 2);
	uint16_t posY = (DISPLAY_HEIGHT / 2);  
	spawnedSize = 0;
	switch (spwnType)
	{
	case SPWN_ARROW:
		SpawnArrow(correctDirection, amount, posX, posY);
		break;
	case SPWN_DIAGONAL:
		SpawnDiagonal(correctDirection, amount, posX, posY);
		break; 
	case SPWN_LINE:
		SpawnLine(correctDirection, amount, posX, posY);
		break;
	case SPWN_CIRCLE:
		SpawnCircle(correctDirection, amount, posX, posY);
		break; 
	default:
		break;
	}
}
void Spawner::SpawnArrow(TriDirection correctDirection, uint8_t size, uint16_t posX, uint16_t posY)
{
	SpawnRotation flockRotation = (SpawnRotation) random(4);
	TriDirection defaultRotation = (TriDirection) random(4);


	switch (flockRotation)
	{
	case SPWN_RIGHT:
		posX -= OFFSET / 2 * size / 4;
		posY += OFFSET * size / 2; 
		break;
	case SPWN_LEFT:
		posX += OFFSET / 2 * size / 4;
		posY += OFFSET * size / 2;
		break;
	case SPWN_UP:
		posX += OFFSET * size / 2;
		posY += OFFSET / 2 * size / 4;
		break;
	case SPWN_DOWN:
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
			UpdateValue(&rightSpawn, posX, posY, correctDirection); 
		}
		else
		{
			UpdateValue(&spawned[spawnedSize], posX, posY, defaultRotation); 
			spawnedSize++; 
		}
			

		switch (flockRotation)
		{
			case SPWN_RIGHT:
				posX += i < (size / 2) ? OFFSET : -OFFSET; 
				posY -= OFFSET;
				break;
			case SPWN_LEFT:
				posX += i < (size / 2) ? -OFFSET : OFFSET; 
				posY -= OFFSET; 
				break;
			case SPWN_DOWN:
				posY += i < (size / 2) ? -OFFSET : OFFSET;
				posX -= OFFSET; 
				break;
			case SPWN_UP:
				posY += i < (size / 2) ? OFFSET : -OFFSET; 
				posX -= OFFSET; 
				break;
			default:
				break;
		}
	}
}
void Spawner::SpawnCircle(TriDirection correctDirection, uint8_t size, uint16_t posX, uint16_t posY)
{
	TriDirection defaultRotation = (TriDirection) random(4);
	uint8_t randomNum = random(size);

	for (uint8_t i = 0; i < size; i++)
	{
		float radius = (size * OFFSET) / PI; 
		float radians = ((2 * PI) / size) * i; 
		uint16_t x = posX + radius * sin(radians);
		uint16_t y = posY + radius * cos(radians); 
		
		if (randomNum == i)
		{
			UpdateValue(&rightSpawn, x, y, correctDirection);
		}
		else
		{
			UpdateValue(&spawned[spawnedSize], x, y, defaultRotation); 
			spawnedSize++;
		}
	}

}
void Spawner::SpawnDiagonal(TriDirection correctDirection, uint8_t size, uint16_t posX, uint16_t posY)
{
	SpawnRotation flockRotation = (SpawnRotation) random(4);
	TriDirection defaultRotation = (TriDirection) random(4);

	posX += flockRotation == SPWN_LEFT || flockRotation == SPWN_DOWN
		? -(OFFSET * size / 2)
		: OFFSET  * size / 2; 
	posY += (OFFSET * size / 2); 

	uint8_t randomNum = random(size);
	for (uint8_t i = 0; i < size; i++)
	{
		if (randomNum == i)
		{
			UpdateValue(&rightSpawn, posX, posY, correctDirection); 
		}
		else
		{
			UpdateValue(&spawned[spawnedSize], posX, posY, defaultRotation); 
			spawnedSize++;
		}
		posX += flockRotation == SPWN_LEFT || flockRotation == SPWN_DOWN
			? OFFSET : -OFFSET; 
		posY -= OFFSET; 
	}
}
void Spawner::SpawnLine(TriDirection correctDirection, uint8_t size, uint16_t posX, uint16_t posY)
{
	SpawnRotation flockRotation = (SpawnRotation) random(4);
	TriDirection defaultRotation = (TriDirection) random(4);

	if (flockRotation == SPWN_LEFT || flockRotation == SPWN_RIGHT)
	{
		posX -= (OFFSET * size / 2); 
	}
	else posY += (OFFSET * size / 2); 
	uint8_t randomNum = random(size);
	for (uint8_t i = 0; i < size; i++)
	{
		if (randomNum == i)
		{
			UpdateValue(&rightSpawn, posX, posY, correctDirection); 
		}
		else
		{
			UpdateValue(&spawned[spawnedSize], posX, posY, defaultRotation); 
			spawnedSize++; 
		}

		if (flockRotation == SPWN_LEFT || flockRotation == SPWN_RIGHT)
			posX += OFFSET;
		else posY -= OFFSET;
	}
}

void Spawner::Update()
{
	// ANIMATION? 
}
void Spawner::Render(Adafruit_ST7735 *tftDisplay)
{
	if (spawnedSize > 0)
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
	}

}

void Spawner::UpdateValue(Triangle *tri, uint16_t posX, uint16_t posY, TriDirection dir)
{
	tri->SetX(posX);
	tri->SetY(posY);
	tri->Width = rightSpawn.Height = TRISIZE;
	tri->SetDirection(dir);
	tri->Color = ST7735_RED;
	tri->HasMoved = true;
}

