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

void GUIHandler::UpdateScore(uint16_t score)
{
	tft->fillRect(50, 5, 50, 10, WW_COLOR_WHITE);
	tft->setCursor(50, 5);
	tft->setTextColor(WW_COLOR_DARKBLUE);
	tft->print(score); 
}

void GUIHandler::UpdateHighScore(uint16_t score)
{
	tft->fillRect(60, DISPLAY_HEIGHT - 11, 50, 10, WW_COLOR_WHITE);
	tft->setCursor(60, DISPLAY_HEIGHT - 11);
	tft->setTextColor(WW_COLOR_DARKBLUE);
	tft->print(score);
}

void GUIHandler::DrawInGameGUI()
{
	tft->fillRoundRect(0, -3, DISPLAY_WIDTH, 20, 7, WW_COLOR_WHITE);
	tft->fillRoundRect(0, DISPLAY_HEIGHT - 15, DISPLAY_WIDTH, 20, 7, WW_COLOR_WHITE);
	tft->setCursor(10, 5);
	tft->setTextColor(WW_COLOR_DARKBLUE); 
	tft->print("Score:");
	tft->setCursor(10, DISPLAY_HEIGHT - 11);
	tft->print("HiScore:");
}
