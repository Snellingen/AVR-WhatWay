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
	// I don't think there's any need to for debounce the button. 
	Serial.print("Button Value: "); 
	Serial.println(analogRead(INPUT_BTN_PIN));

	return digitalRead(INPUT_BTN_PIN) == LOW;
}

GlobalDirection Input::GetDirection()
{
	/*Serial.print("X: ");
	Serial.print(GetXAxis());
	Serial.print(" Y: ");
	Serial.println(GetYAxis());

*/

	if (GetXAxis() > 1000)
	{
		return GLB_RIGHT;
	}
	if (GetXAxis() < 80)
	{
		return GLB_LEFT;
	}
	if (GetYAxis() > 1000)
	{
		return GLB_DOWN;
	}
	if (GetYAxis() < 80)
	{
		return GLB_UP; 
	}
	// This is so that we don't get flickering between values. 
	else if (
		(GetXAxis() < 600 && GetXAxis() > 500) || 
		(GetYAxis() < 600 && GetYAxis() > 500))
		return GLB_NONE;
	else return lastDir; 
}

GlobalDirection Input::GetDirectionOnce()
{
	GlobalDirection currentDir = GetDirection(); 
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
