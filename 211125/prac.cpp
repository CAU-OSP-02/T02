#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(600, 480), "LUNAR LANDER");
	window.setFramerateLimit(60);

	Texture t1;
	Sprite background;
	t1.loadFromFile("background.jpg");
	background.setTexture(t1);
	background.setScale(Vector2f(1.5, 1.5));

	Texture t2;
	Sprite  lander;
	t2.loadFromFile("spaceship.png");
	lander.setTexture(t2);
	lander.setScale(Vector2f(0.1, 0.1));

	while (window.isOpen())
	{
		Event e;
		while (window.pollEvent(e)) {
			if (e.type == Event::Closed)
				window.close();
		}

		auto lander_pos = lander.getPosition();

		if (0<lander_pos.x<600)
		{
			if (Keyboard::isKeyPressed(Keyboard::Left))
				lander.move(-10.0, 0.0);
			if (Keyboard::isKeyPressed(Keyboard::Right))
				lander.move(10.0, 0.0);
			if (Keyboard::isKeyPressed(Keyboard::Up))
				lander.move(0.0, -10.0);
			if (Keyboard::isKeyPressed(Keyboard::Down))
				lander.move(0.0, 10.0);
		}


		Vector2i localPosition = Mouse::getPosition(window);

		window.clear();
		window.draw(background);
		window.draw(lander);
		window.display();
	}

	return 0;
}