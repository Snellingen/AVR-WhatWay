#pragma once
#include <Adafruit_GFX.h>		// Source: https://github.com/adafruit/Adafruit-GFX-Library
#include <Adafruit_ST7735.h>	// Source: https://github.com/adafruit/Adafruit-ST7735-Library
#include "Object.h"
#include "GlobalValues.h"

class Triangle : public Object
{

public: 
	uint16_t Width;
	uint16_t Height;
	uint16_t Color;
	uint16_t ClearColor; 
	void SetDirection(GlobalDirection dir) 
	{ 
		PrevDirection = Direction; 
		Direction = dir;
	}
	GlobalDirection GetDirection() { return Direction; }

private: 
	GlobalDirection Direction;
	GlobalDirection PrevDirection;

public:
	Triangle()
	{
		X = DISPLAY_WIDTH / 2;
		Y = DISPLAY_HEIGHT / 2; 
		Width = Height = 0; 
		Color = WW_COLOR_WHITE;
		ClearColor = WW_COLOR_DARKBLUE; 
		Direction = GLB_LEFT;
	}
	Triangle(uint16_t x, uint16_t y, uint16_t width, uint16_t height, GlobalDirection dir, uint16_t color)
		: Width(width), Height(height), Color(color), Direction(dir), Object(x,y){}
	~Triangle() {};

	void Move(uint16_t dirX, uint16_t dirY);
	void Update(); 
	void Render(Adafruit_ST7735 *tftDisplay, boolean clear);
	void Clear(Adafruit_ST7735 *tftDisplay);
private: 
	void DrawTriangle(Adafruit_ST7735 *tftDisplay);

};

