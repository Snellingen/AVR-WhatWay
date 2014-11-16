#pragma once
#include <Arduino.h>
class Object
{

public:
	uint16_t X;
	uint16_t Y;

protected:
	uint16_t lastX;
	uint16_t lastY;

	boolean HasMoved;

public:
	Object()
	{
		X = Y = lastX = lastY = 0; 
		HasMoved = false; 
	}
	Object(uint16_t x, uint16_t y) : X(x), Y(y), lastX(x), lastY(y), HasMoved(true){};
	~Object() {};

	virtual void Update() {}
	virtual void Render(Adafruit_ST7735 *tftDisplay) {}
	
};

