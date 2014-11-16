#include "Spawner.h"

void Spawner::Spawn(uint8_t amount, SpawnType spwnType, TriDirection correctDirection)
{
	uint16_t posX = (DISPLAY_WIDTH / 2);
	uint16_t posY = (DISPLAY_HEIGHT / 2);  

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
	spawnedSize = 0; 
	for (uint8_t i = 0; i < size; i++)
	{
		if (randomNum == i)
		{
			rightSpawn.SetX(posX);
			rightSpawn.SetY(posY);
			rightSpawn.Width = rightSpawn.Height = TRISIZE; 
			rightSpawn.SetDirection(correctDirection); 
			rightSpawn.Color = ST7735_RED; 
			rightSpawn.HasMoved = true;

		}
		else
		{
			spawned[spawnedSize].SetX(posX);
			spawned[spawnedSize].SetY(posY);
			spawned[spawnedSize].Width = spawned[spawnedSize].Height = TRISIZE;
			spawned[spawnedSize].SetDirection(defaultRotation);
			spawned[spawnedSize].Color = ST7735_RED;
			spawned[spawnedSize].HasMoved = true; 

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

}
void Spawner::SpawnDiagonal(TriDirection correctDirection, uint8_t size, uint16_t posX, uint16_t posY)
{

}
void Spawner::SpawnLine(TriDirection correctDirection, uint8_t size, uint16_t posX, uint16_t posY)
{

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

