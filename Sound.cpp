#include "Sound.h"


Sound::Sound()
{
	positiveMelody[0] = NOTE_D5;
	positiveMelody[1] = NOTE_FS5;
	positiveMelody[2] = NOTE_AS5;

	negativeMelody[0] = NOTE_AS5;
	negativeMelody[1] = NOTE_FS5;
	negativeMelody[2] = NOTE_D5;

	negSound = posSound =  isPlaying = false;
	index = 0; 
	time = millis();
}


Sound::~Sound()
{
}

void Sound::PlayPositiveSound()
{
	if (isPlaying)return;
	isPlaying = posSound = true;
}

void Sound::PlayNegativeSound()
{
	if (isPlaying)return;
	isPlaying = negSound = true;
}

void Sound::PlayMenuSound()
{
	tone(SPEAKER_PIN, NOTE_D4, 0.0005); 
}

void Sound::Update()
{

	if (posSound || negSound)
	{
		if ( millis() - time < DLEAY_PER_TONE) return;
		if (index >= 3)
		{
			index = 0; 
			isPlaying = posSound = negSound = false;
			noTone(SPEAKER_PIN); 
			return;
		}
		if (posSound) tone(SPEAKER_PIN, positiveMelody[index], 0.0004); 
		else  tone(SPEAKER_PIN, negativeMelody[index], 0.0004);
		index++; 
		time = millis(); 
	}



}