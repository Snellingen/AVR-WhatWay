#pragma once
#include <Arduino.h>

#define WW_COLOR_WHITE 61342
#define WW_COLOR_BLUE 13531
#define WW_COLOR_DARKBLUE 10730
#define WW_COLOR_RED 57959
#define WW_COLOR_GREEN 30000
#define DISPLAY_WIDTH 128
#define DISPLAY_HEIGHT 160

// LES
#define GLB_LEFT 0
#define GLB_RIGHT 1
#define GLB_UP 2
#define GLB_DOWN 3
#define GLB_NONE 4

// THIS IS TO SAVE MEMORY SPACE
static uint16_t GLB_CurrentColor = WW_COLOR_WHITE; 
static uint16_t GLB_CurrentClearColor = WW_COLOR_DARKBLUE;
static uint8_t GLB_CurrentArrowWidth = 10; 
