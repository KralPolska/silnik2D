#pragma once
#include "point2D.h"
#include <math.h>
class primitive
{
protected:
	point2D start;
	point2D end;
	sf::RenderWindow& window;
public:
	primitive(sf::RenderWindow& window);
	
	//rysowanie
	void drawLine(sf::Vector2f start, sf::Vector2f end, sf::Color color);
	void drawLine(sf::Vector2f start, sf::Vector2f end, sf::Color color, unsigned int thickness);

	void drawCircle(sf::Vector2f center, unsigned int radius, sf::Color color, unsigned int thickness);
	void drawFilledCircle(sf::Vector2f center, unsigned int radius, sf::Color color, unsigned int thickness);

	void drawRectangle(sf::Vector2f position, sf::Vector2f size, sf::Color color, unsigned int thickness);
	void drawFilledRectangle(sf::Vector2f position, sf::Vector2f size, sf::Color color, unsigned int thickness);

	void drawSquare(sf::Vector2f position, unsigned int size, sf::Color color, unsigned int thickness);
	void drawFilledSquare(sf::Vector2f position, unsigned int size, sf::Color color, unsigned int thickness);
	
};

class tPrimitive : public primitive {
public:
	using primitive::primitive;
	/*
	void translate(int newStart, int newEnd);
	void rotate(float angle);
	*/
};
