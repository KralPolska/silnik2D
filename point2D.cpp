#include "point2D.h"
point2D::point2D()
{
	point = { 0.0f,0.0f };
}

point2D::point2D(sf::Vector2f position)
{
	point = position;
}

point2D::point2D(float x, float y)
{
	point.x = x;
	point.y = y;
}

float point2D::getX()
{
	return point.x;
}

 float point2D::getY()
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

void point2D::setX(float x)
{
	point.x = x;
}

void point2D::setY(float y)
{
	point.y = y;
}
