#include "Sound.h"


Sound::Sound()
{
	positiveMelody[0] = NOTE_DS3;
	positiveMelody[1] = NOTE_G3;
	positiveMelody[2] = NOTE_B3;

	negativeMelody[0] = NOTE_F2;
	negativeMelody[1] = NOTE_CS2;
	negativeMelody[2] = NOTE_A1;

	status = 0; 
	index = 0; 
	time = millis();
}


Sound::~Sound()
{
}

void Sound::PlayPositiveSound()
{
	if (status == 1) return;
	status = 1;
}

void Sound::PlayNegativeSound()
{
	if (status == 2)return;
	status = 2; 
}

void Sound::Update()
{


	if (status > 0)
	{
		if ( millis() - time < DLEAY_PER_TONE) return;
		if (index >= 3)
		{
			index = 0; 
			status = 0; 
			noTone(SPEAKER_PIN); 
			return;
		}
		if (status == 1) tone(SPEAKER_PIN, positiveMelody[index], 0.0004); 
		else if (status == 2) tone(SPEAKER_PIN, negativeMelody[index], 0.0004);
		index++; 
		time = millis(); 
	}



}