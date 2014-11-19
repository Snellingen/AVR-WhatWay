#include "GUIHandler.h"


GUIHandler::GUIHandler(Adafruit_ST7735 *tftDisplay)
{
	tft = tftDisplay; 
}


GUIHandler::~GUIHandler()
{
}

void GUIHandler::Start()
{

}

void GUIHandler::Update()
{

}

void GUIHandler::DrawInGameGUI()
{
	tft->fillRoundRect(0, -5, DISPLAY_WIDTH, 20, 7, WW_COLOR_WHITE);
	tft->fillRoundRect(0, DISPLAY_HEIGHT - 15, DISPLAY_WIDTH, 20, 7, WW_COLOR_WHITE);
}
