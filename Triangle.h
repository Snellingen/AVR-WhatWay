#define TRI_DIRECTION_LEFT	0
#define TRI_DIRECTION_RIGHT	1
#define TRI_DIRECTION_UP	2
#define TRI_DIRECTION_DOWN	3

typedef struct
{
	uint16_t x;
	uint16_t y;
	uint16_t Width;
	uint16_t Height;
	uint16_t oldX;
	uint16_t oldY;
	boolean moved;
} Triangle;


void MoveTriangle(Triangle* tri, uint16_t distanceX, uint16_t distanceY)
{
	tri->oldX = tri->x;
	tri->oldY = tri->y;

	tri->x += distanceX;
	tri->y += distanceY;

	tri->moved = true;
}

void DrawTriangle(Triangle* tri, uint16_t color, boolean clearOld, Adafruit_ST7735 *tftDisplay)
{
	// If clearOld, clear the old triangle. 
	if (clearOld)
	{
		if(tri->moved)
		{
		tftDisplay->fillTriangle(
		tri->oldX,
		tri->oldY,
		tri->oldX + tri->Width / 2,
		tri->oldY + tri->Height,
		tri->oldX + tri->Width,
		tri->oldY,
		ST7735_BLACK);
		}

		// Draw the new triangle. 
		tftDisplay->fillTriangle(
			tri->x,
			tri->y,
			tri->x + tri->Width / 2,
			tri->y + tri->Height,
			tri->x + tri->Width,
			tri->y,
			color);
	}

	tri->moved = false;
}