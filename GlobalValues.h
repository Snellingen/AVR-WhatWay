#pragma once
#include <Arduino.h>

#define WW_COLOR_WHITE 61342
#define WW_COLOR_BLUE 13531
#define WW_COLOR_DARKBLUE 10730
#define WW_COLOR_RED 57959
#define WW_COLOR_GREEN 30000
#define DISPLAY_WIDTH 128
#define DISPLAY_HEIGHT 160

// THIS IS TO SAVE MEMORY SPACE
static uint16_t GLB_CurrentColor = WW_COLOR_WHITE; 
static uint16_t GLB_CurrentClearColor = WW_COLOR_DARKBLUE;
static uint8_t GLB_CurrentArrowWidth = 10; 

enum GlobalDirection
{
	GLB_LEFT,
	GLB_RIGHT,
	GLB_UP,
	GLB_DOWN,
	GLB_NONE
};

