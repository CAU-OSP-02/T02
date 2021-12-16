#include "Audio.hpp"


Audio::Audio()
{
	/*Check the audio file available*/
	
	if (!menuSoundBuffer.loadFromFile("content/audio/Menu.ogg"))
	{
		std::cout << "ERROR LOADING Menu SFX." << std::endl;
	}

	if (!resultSoundBuffer.loadFromFile("content/audio/Result.ogg"))
	{
		std::cout << "ERROR LOADING RESULT SFX." << std::endl;
	}


	/*Set the sound*/
	menuSound.setBuffer(menuSoundBuffer);
	resultSound.setBuffer(resultSoundBuffer);

}

Audio::~Audio()
{

}
