#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>

class point2D
{
private:
	sf::Vector2f point;
public:
	point2D();
	point2D(sf::Vector2f position);
	point2D(unsigned int x, unsigned int y);

	int getX();
	int getY();
	sf::Vector2f getPosition();

	void setPosition(sf::Vector2f position);
	void setX(unsigned int x);
	void setY(unsigned int y);

};

