#pragma once
#include <Adafruit_GFX.h>		// Source: https://github.com/adafruit/Adafruit-GFX-Library
#include <Adafruit_ST7735.h>	// Source: https://github.com/adafruit/Adafruit-ST7735-Library
#include "Object.h"

enum TriDirection
{
	TRI_LEFT,
	TRI_RIGHT,
	TRI_UP,
	TRI_DOWN
};

class Triangle : public Object
{

public: 
	uint16_t Width;
	uint16_t Height;
	uint16_t Color;
	uint16_t ClearColor; 
	void SetDirection(TriDirection dir) 
	{ 
		PrevDirection = Direction; 
		Direction = dir;
	}
	TriDirection GetDirection() { return Direction; }

private: 
	TriDirection Direction;
	TriDirection PrevDirection;

public:
	Triangle()
	{
		X = Y = Width = Height = 0; 
		Color = ST7735_MAGENTA;
		ClearColor = ST7735_BLACK; 
		Direction = TRI_LEFT;
	}
	Triangle(uint16_t x, uint16_t y, uint16_t width, uint16_t height, TriDirection dir, uint16_t color)
		: Width(width), Height(height), Color(color), Direction(dir), Object(x,y){}
	~Triangle() {};

	void Move(uint16_t dirX, uint16_t dirY);
	void Update(); 
	void Render(Adafruit_ST7735 *tftDisplay, boolean clear);
	void Clear(Adafruit_ST7735 *tftDisplay);
private: 
	void DrawTriangle(Adafruit_ST7735 *tftDisplay);

};

