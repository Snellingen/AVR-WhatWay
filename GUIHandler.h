#pragma once
#include <Adafruit_ST7735.h>
#include "GlobalValues.h"


class GUIHandler
{
private:
	Adafruit_ST7735 *tft;


public:
	GUIHandler() {};
	GUIHandler(Adafruit_ST7735 *tftDisplay); 
	~GUIHandler();

	void Start(); 
	void Update();
	void DrawInGameGUI();

};

