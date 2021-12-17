#include <SFML/Graphics.hpp>

using namespace sf;

int main() {
	RenderWindow window(VideoMode(480, 480), "Window!");

	while (window.isOpen()) {
		Event e;
		while (window.pollEvent(e)) {
			if (e.type == Event::Closed) window.close();
		}

		window.clear(Color::White);
		window.display();
	}

	return 0;
}