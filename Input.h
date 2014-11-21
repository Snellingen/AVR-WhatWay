#pragma once
#include <Arduino.h>
#include "GlobalValues.h"

#define INPUT_X_PIN A5
#define INPUT_Y_PIN A4

// REMEMBER TO PUT PULLDOWN 10K ON BUTTON CONNECTION
#define INPUT_BTN_PIN A3




class Input
{

public:
	Input();
	~Input();

	uint16_t GetXAxis(); 
	uint16_t GetYAxis();
	boolean ButtonClick(); 

	GlobalDirection GetDirection(); 
	
private:
	uint16_t GetAxis(uint8_t pin);
};
