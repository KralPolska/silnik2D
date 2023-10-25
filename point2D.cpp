#include "point2D.h"
point2D::point2D()
{
	point = { 0.0f,0.0f };
}

point2D::point2D(sf::Vector2f position)
{
	point = position;
}

point2D::point2D(unsigned int x, unsigned int y)
{
	point.x = x;
	point.y = y;
}

int point2D::getX()
{
	return point.x;
}

int point2D::getY()
{
	return point.y;
}

sf::Vector2f point2D::getPosition()
{
	return point;
}

void point2D::setPosition(sf::Vector2f position)
{
	point = position;
}

void point2D::setX(unsigned int x)
{
	point.x = x;
}

void point2D::setY(unsigned int y)
{
	point.y = y;
}
