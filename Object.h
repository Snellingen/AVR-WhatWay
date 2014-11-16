#pragma once
#include <Arduino.h>
class Object
{

protected:
	uint16_t lastX;
	uint16_t lastY;
	uint16_t X;
	uint16_t Y;


public:
	void SetX(uint16_t x) { lastX = X; X = x; };
	uint16_t GetX() { return X; }
	void SetY(uint16_t y) { lastY = Y; Y = y; }
	uint16_t GetY() { return Y; }
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

