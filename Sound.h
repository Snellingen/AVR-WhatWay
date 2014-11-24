#pragma once
#define SPEAKER_PIN 5
#define DLEAY_PER_TONE 100 

#include "Tones.h"
#include <Arduino.h>

class Sound
{
protected:
	int positiveMelody[3];
	int negativeMelody[3];

	boolean posSound;
	boolean negSound; 
	boolean isPlaying; 
	uint8_t index;
	unsigned long time;

public:
	Sound();
	~Sound();

	void PlayPositiveSound();

	void PlayNegativeSound(); 

	void PlayMenuSound(); 
	
	void Update(); 

};
