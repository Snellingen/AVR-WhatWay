#include "Input.h"


Input::Input()
{
	pinMode(INPUT, INPUT_X_PIN);
	pinMode(INPUT, INPUT_Y_PIN);
	pinMode(INPUT, INPUT_BTN_PIN);
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
	// I don't think there's any need to for debounce the button. 
	return digitalRead(INPUT_BTN_PIN) == HIGH; 
}

GlobalDirection Input::GetDirection()
{
	if (GetXAxis() > 900)
	{
		return GLB_LEFT;
	}
	if (GetXAxis() < 60)
	{
		return GLB_RIGHT;
	}
	if (GetYAxis() > 900)
	{
		return GLB_UP;
	}
	if (GetYAxis() < 60)
	{
		return GLB_DOWN; 
	}
	else return GLB_NONE; 
}
