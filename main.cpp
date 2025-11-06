#include <iostream>
#include <SFML/Graphics.hpp>
#include "statek.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	window.setFramerateLimit(60);
	Statek gracz(400.f, 570.f);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			gracz.moveLeft();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			gracz.moveRight();
		}
		gracz.update();
		window.clear(sf::Color::Black);
		gracz.draw(window);
		window.display();
	}
	return 0;
}