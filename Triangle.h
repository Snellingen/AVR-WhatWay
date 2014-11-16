#pragma once
#include <Adafruit_GFX.h>		// Source: https://github.com/adafruit/Adafruit-GFX-Library
#include <Adafruit_ST7735.h>	// Source: https://github.com/adafruit/Adafruit-ST7735-Library
#include "Object.h"

class Triangle : Object
{

public: 
	uint16_t Width;
	uint16_t Height;
	uint16_t Color;
	uint16_t ClearColor; 

public:
	Triangle()
	{
		X = Y = Width = Height = 0; 
		Color = ST7735_MAGENTA;
		ClearColor = ST7735_BLACK; 
	}
	Triangle(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint16_t color)
		: Width(width), Height(height), Color(color), Object(x,y){}
	~Triangle() {};

	void Move(uint16_t dirX, uint16_t dirY);
	void Update(); 
	void Render(Adafruit_ST7735 *tftDisplay);

private: 
	void DrawTriangle(Adafruit_ST7735 *tftDisplay, uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color);

};

