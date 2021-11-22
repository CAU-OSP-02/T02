#include "Animation.hpp"

//Constructor
Animation::Animation()
{
	Frame = 0.0f;
	frameSpeed = 0.0f;
}

//Destructor
Animation::~Animation()
{

}


Animation::Animation(sf::Texture& t, int x, int y, int w, int h, int count, float Speed)
{
	Frame = 0;
	frameSpeed = Speed;

	for (int i = 0; i < count; i++)
		frames.push_back(sf::IntRect(x + i * w, y, w, h));

	sprite.setTexture(t);
	sprite.setOrigin(w / 2, h / 2);
	sprite.setTextureRect(frames[0]);
}


void Animation::frameUpdate()
{
	Frame += frameSpeed;
	int n = frames.size();

	if (Frame >= n)
	{
		Frame -= n;
	}

	if (n > 0)
	{
		sprite.setTextureRect(frames[int(Frame)]);
	}


}


bool Animation::frameIsEnd()
{
	return Frame + frameSpeed >= frames.size();
}
