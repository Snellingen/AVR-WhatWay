#pragma once
#include <Arduino.h>
#include "GlobalValues.h"

#define INPUT_X_PIN A4
#define INPUT_Y_PIN A5

// REMEMBER TO PUT PULLDOWN 10K ON BUTTON CONNECTION
#define INPUT_BTN_PIN A3

class Input
{

public:
	Input();
	~Input();

	inline uint16_t GetXAxis(); 
	inline uint16_t GetYAxis();
	boolean ButtonClick(); 

	inline uint8_t GetDirection(); 
	uint8_t GetDirectionOnce();
	
private:
	uint16_t GetAxis(uint8_t pin);
	uint8_t lastDir; 

};

