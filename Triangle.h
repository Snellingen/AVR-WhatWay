#pragma once
#include <Adafruit_GFX.h>		// Source: https://github.com/adafruit/Adafruit-GFX-Library
#include <Adafruit_ST7735.h>	// Source: https://github.com/adafruit/Adafruit-ST7735-Library
#include "Object.h"
#include "GlobalValues.h"

class Triangle : public Object
{

public: 
	uint8_t* Width;
	uint8_t* Height;
	uint16_t* Color;
	uint16_t* ClearColor; 
	void SetDirection(uint8_t dir) 
	{ 
		PrevDirection = Direction; 
		Direction = dir;
	}
	uint8_t GetDirection() { return Direction; }

private: 
	uint8_t Direction;
	uint8_t PrevDirection;
	void DrawTriangle(Adafruit_ST7735 *tftDisplay);

public:
	Triangle()
	{
		X = DISPLAY_WIDTH / 2;
		Y = DISPLAY_HEIGHT / 2; 
		Width = Height = &GLB_CurrentArrowWidth; 
		Color = &GLB_CurrentColor;
		ClearColor = &GLB_CurrentClearColor; 

		Direction = GLB_LEFT;
	}
	Triangle(uint16_t x, uint16_t y, uint8_t dir)
		: Direction(dir), Object(x,y){}
	~Triangle() {};

	void Move(uint16_t dirX, uint16_t dirY);
	void Update(); 
	void Render(Adafruit_ST7735 *tftDisplay, boolean clear);
	void Clear(Adafruit_ST7735 *tftDisplay);

};

