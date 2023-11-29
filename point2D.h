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
	point2D(float x, float y);

	float getX();
	float getY();
	sf::Vector2f getPosition();

	void setPosition(sf::Vector2f position);
	void setX(float x);
	void setY(float y);

};

