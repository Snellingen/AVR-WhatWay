#include "Input.h"


Input::Input()
{
	pinMode(INPUT, INPUT_X_PIN);
	pinMode(INPUT, INPUT_Y_PIN);
	pinMode(INPUT, INPUT_BTN_PIN);
	lastDir = GLB_NONE; 
}


Input::~Input()
{
}

uint16_t Input::GetXAxis()
{
	return GetAxis(INPUT_X_PIN); 
}

uint16_t Input::GetYAxis()
{
	return GetAxis(INPUT_Y_PIN); 
}

uint16_t Input::GetAxis(uint8_t pin)
{
	return analogRead(pin); 
}

boolean Input::ButtonClick()
{
	return digitalRead(INPUT_BTN_PIN) == LOW;
}

inline uint8_t Input::GetDirection()
{

	if (GetXAxis() > 900)
	{
		return GLB_LEFT;
	}
	if (GetXAxis() < 80)
	{
		return GLB_RIGHT;
	}
	if (GetYAxis() > 900)
	{
		return GLB_UP;
	}
	if (GetYAxis() < 80)
	{
		return GLB_DOWN; 
	}
	// This to reduce flickering between values. 
	else if (
		(GetXAxis() < 600 && GetXAxis() > 500) || 
		(GetYAxis() < 600 && GetYAxis() > 500))
		return GLB_NONE;
	else return lastDir; 
}

uint8_t Input::GetDirectionOnce()
{
	uint8_t currentDir = GetDirection(); 
	if (currentDir != lastDir)
	{
		lastDir = currentDir; 
		return currentDir; 
	}
	else
	{
		lastDir = currentDir; 
		return GLB_NONE;
	}
}
