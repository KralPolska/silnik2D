#include "primitive.h"

//Rysowanie

primitive::primitive(sf::RenderWindow& windowT) :window(windowT)
{
}

void primitive::drawLine(sf::Vector2f start, sf::Vector2f end, sf::Color color)
{
	sf::VertexArray line(sf::Lines, 2);
	line[0].position = start;
	line[0].color = color;
	line[1].position = end;
	line[1].color = color;

	window.draw(line);
}

void drawLine(sf::Vector2f start, sf::Vector2f end, sf::Color color, unsigned int thickness)
{
	short x = start.x;
	short y = start.y;
	short x2 = end.x;
	short y2 = end.y;

	float dxy = (y2 - y) / (x2 - x);
	float newY = 0.0f;
	for (int i = x; i <= x2; i++)
	{
		newY = dxy * (x2 - i) + y;
	}
}


void primitive::drawCircle(sf::Vector2f center, unsigned int radius, sf::Color color, unsigned int thickness)
{
	sf::CircleShape circle(radius);
	circle.setPosition(center.x - radius, center.y - radius);
	circle.setOutlineColor(color);
	circle.setOutlineThickness(thickness);
	window.draw(circle);
}

void primitive::drawFilledCircle(sf::Vector2f center, unsigned int radius, sf::Color color, unsigned int thickness)
{
	sf::CircleShape circle(radius);
	circle.setPosition(center.x - radius, center.y - radius);
	circle.setOutlineColor(color);
	circle.setFillColor(color);
	circle.setOutlineThickness(thickness);
	window.draw(circle);
}

void primitive::drawRectangle(sf::Vector2f position, sf::Vector2f size, sf::Color color, unsigned int thickness)
{
	sf::RectangleShape rectangle(size);
	rectangle.setPosition(position);
	rectangle.setOutlineColor(color);
	rectangle.setOutlineThickness(thickness);
	window.draw(rectangle);
}

void primitive::drawFilledRectangle(sf::Vector2f position, sf::Vector2f size, sf::Color color, unsigned int thickness)
{
	sf::RectangleShape rectangle(size);
	rectangle.setPosition(position);
	rectangle.setOutlineColor(color);
	rectangle.setFillColor(color);
	rectangle.setOutlineThickness(thickness);
	window.draw(rectangle);
}

void primitive::drawSquare(sf::Vector2f position, unsigned int size, sf::Color color, unsigned int thickness)
{
	sf::Vector2f side = { side.x = size,side.y = size };
	sf::RectangleShape square(side);
	square.setPosition(position);
	square.setOutlineColor(color);
	square.setOutlineThickness(thickness);
	window.draw(square);
}

void primitive::drawFilledSquare(sf::Vector2f position, unsigned int size, sf::Color color, unsigned int thickness)
{
	sf::Vector2f side = { side.x = size,side.y = size };
	sf::RectangleShape square(side);
	square.setPosition(position);
	square.setOutlineColor(color);
	square.setFillColor(color);
	square.setOutlineThickness(thickness);
	window.draw(square);
}

/*
void tPrimitive::translate(int newStart, int newEnd)
{
	start.setX(start.getX() + newStart);
	start.setY(start.getY() + newEnd);
}

void tPrimitive::rotate(float angle)
{

}
*/
