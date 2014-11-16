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

void Triangle::Render(Adafruit_ST7735 *tftDisplay)
{
	/* In this method we only draw the rectangle if it has moved.
	 * We also only clear where the last triangle was instead of the whole frame,
	 * this is is because it is slow to write to the display, so we have to keep it to the minimum. 
	 */

	if (!HasMoved) return; 
	/* Clear old triangle */
	DrawTriangle(tftDisplay, lastX, lastY, Width, Height, ClearColor);
	/* Draw new triangle */
	DrawTriangle(tftDisplay, X, Y, Width, Height, Color);
	/* Set back the HasMoved flag because it has now been drawn.*/
	HasMoved = false; 
}

void Triangle::DrawTriangle(Adafruit_ST7735 *tftDisplay, uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color)
{
	switch (Direction)
	{
	case LEFT:
		tftDisplay->fillTriangle(x, y, x, y + h, x + w, y + h / 2 , color);
		break; 
	case RIGHT:
		tftDisplay->fillTriangle(x, y + h / 2, x + w, y + h, x + w, y, color);
		break; 
	case UP:
		tftDisplay->fillTriangle(x, y, x + w / 2, y + h, x + w, y, color);
		break; 
	case DOWN:
		tftDisplay->fillTriangle(x, y + h, x + w / 2, y, x + w, y + h, color);
		break; 
	default:
		break;
	}
	
}
