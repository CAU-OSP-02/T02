#include "Settings.hpp"



//Collide function

bool isCollide(Entity* a, Entity* b)
{
	return (b->xPos - a->xPos) * (b->xPos - a->xPos) + (b->yPos - a->yPos) * (b->yPos - a->yPos) < (b->R + a->R) * (b->R + a->R);
}




//Comstructor
Settings::Settings()
{
	cout << "[Game Settings]" << endl;

}

//Destructor
Settings::~Settings()
{

}


void Settings::runGame()
{

	// 
	// THESE ARE EXAMPLE CODES OF SETTING BACKGROUNDS & PLAYER
	//
	// - CANNOT USE IMMEDIATELY
	// - NEED TO BE CUSTOMIZED
	//


	srand(time(0));


	/* Audio & LoadAudio*/
	Audio* gameAudio = new Audio;
	gameAudio->bgSound.setVolume(50);
	gameAudio->bgSound.setLoop(true);
	gameAudio->bgSound.play();



	/* Font */

	//Font Setitng
	sf::Font font;
	if (!font.loadFromFile("content/font/NanumBarunpenR.TTF"))
		std::cout << "Can't find the font file" << std::endl;



	/* Texture & LoadImage */
	sf::Texture backgroundTexture;

	sf::Texture playerATexture; //Player A
	sf::Texture playerBTexture; //Player B

	backgroundTexture.loadFromFile("images/Background.jpg");
	backgroundTexture.setSmooth(true);


	// Background
	sf::Sprite background(backgroundTexture);


	// Animation
	Animation sPlayerA(playerATexture, 0, 0, 43, 43, 1, 0);		// Player A
	Animation sPlayerAMove(playerATexture, 0, 43, 43, 43, 2, 0);
	Animation sPlayerB(playerBTexture, 0, 0, 43, 43, 1, 0);		// Player B
	Animation sPlayerBMove(playerBTexture, 0, 43, 43, 43, 2, 0);


	//*************************************************************************************************************


	std::list<Entity*> entities; // GROUP of entity class's object


	// Create Asteroid object -- fixed number of Asteroid = 20
	for (int i = 0; i < 20; i++)
	{
		Asteroid* a = new Asteroid();
		a->settings(sAsteroid, rand() % screenW, rand() % screenH, rand() % 360, 25);
		entities.push_back(a);
	}



	// Create Player A & B
	Player* pA = new Player();
	pA->settings(sPlayerA, screenW / 2 + 300, screenH / 2, 0, 20);
	entities.push_back(pA);

	Player* pB = new Player();
	pB->settings(sPlayerB, screenW / 2 - 300, screenH / 2, 0, 20);
	entities.push_back(pB);


	//*************************************************************************************************************
}

