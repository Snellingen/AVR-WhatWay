#include "Triangle.h"

void Triangle::Move(uint16_t dirX, uint16_t dirY)
{
	{
		lastX = X;
		lastY = Y;

		X += dirX;
		X += dirY;

		HasMoved = true;
	}
}

void Triangle::Update()
{

}

void Triangle::Render(Adafruit_ST7735 *tftDisplay, boolean clear)
{
	/* In this method we only draw the rectangle if it has moved.
	 * We also only clear where the last triangle was instead of the whole frame,
	 * this is is because it is slow to write to the display, so we have to keep it to the minimum. 
	 */
	
	if (!HasMoved) return;
	/* Clear old triangle */
	if (clear) Clear(tftDisplay);
	/* Draw new triangle */
	DrawTriangle(tftDisplay);
	/* Set back the HasMoved flag because it has now been drawn.*/
	lastX = X; 
	lastY = Y; 
	PrevDirection = Direction; 
	HasMoved = false; 
}

void Triangle::Clear(Adafruit_ST7735 *tftDisplay)
{
	// I'm using rectangle to fill so that I don't have to calculate diagonal lines. 
	tftDisplay->fillRect(lastX -1, lastY -1, Width + 4, Height + 4, ClearColor); 
}

void Triangle::DrawTriangle(Adafruit_ST7735 *tftDisplay)
{
	switch (Direction)
	{
	case GLB_LEFT:
		tftDisplay->fillTriangle(X, Y, X, Y + Height, X + Width, Y + Height / 2 , Color);
		break; 
	case GLB_RIGHT:
		tftDisplay->fillTriangle(X, Y + Height / 2, X + Width, Y + Height, X + Width, Y, Color);
		break; 
	case GLB_DOWN:
		tftDisplay->fillTriangle(X, Y, X + Width / 2, Y + Height, X + Width, Y, Color);
		break; 
	case GLB_UP:
		tftDisplay->fillTriangle(X, Y + Height, X + Width / 2, Y, X + Width, Y + Height, Color);
		break; 
	default:
		break;
	}
	
}
