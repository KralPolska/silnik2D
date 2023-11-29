#include "primitive.h"
#include <cmath>
#include <iostream>

#define PI 3.14159273

primitive::primitive(sf::RenderWindow& windowT) :window(windowT)
{
	this->farRight = 0;
	this->farLeft = 0;
	this->farBottom = 0;
	this->farTop = 0;
	this->moving = false;
	this->selected = false;
	this->prevPos = { 0,0 };
}

void primitive_rectangle::updateEdge()
{
	this->farRight = point.getX() + rectangle.getSize().x + rectangle.getOutlineThickness();
	this->farLeft = point.getX() - rectangle.getOutlineThickness();
	this->farBottom = point.getY() + rectangle.getSize().y + rectangle.getOutlineThickness();
	this->farTop = point.getY() - rectangle.getOutlineThickness();
}

void primitive_rectangle::drawRectangle(sf::Color color, unsigned int thickness)
{
	rectangle.setPosition(point.getPosition());
	rectangle.setFillColor({ 0,0,0,0 });
	rectangle.setOutlineColor(color);
	rectangle.setOutlineThickness(thickness);
	window.draw(rectangle);
}

void primitive_rectangle::drawFilledRectangle(sf::Color color, unsigned int thickness)
{
	rectangle.setPosition(point.getPosition());
	rectangle.setOutlineColor(color);
	rectangle.setFillColor(color);
	rectangle.setOutlineThickness(thickness);
	window.draw(rectangle);
}

void primitive_rectangle::drawTexturedRectangle(sf::Texture texture)
{
	rectangle.setPosition(point.getPosition());
	rectangle.setTexture(&texture);
	rectangle.setTextureRect({ 0,0, getSizeX(), getSizeY() });
	window.draw(rectangle);
}

void primitive_rectangle::draw()
{
	rectangle.setOutlineThickness(0);
	rectangle.setPosition(point.getPosition());
	texture.setPosition(point.getPosition());
	if (std::round(prevPos.getX()) == std::round(point.getX()) && std::round(prevPos.getY()) == std::round(point.getY()))
		moving = false;
	else
		moving = true;
	window.draw(rectangle);
	window.draw(texture);
}

void primitive_rectangle::setPosition(sf::Vector2f position)
{
	point.setPosition(position);
	prevPos.setPosition(position);
}

void primitive_rectangle::setPosition(float x, float y)
{
	point.setPosition({ x,y });
	prevPos.setPosition({ x,y });
}

void primitive_rectangle::setPosition(float xy)
{
	point.setPosition({ xy,xy });
	prevPos.setPosition({ xy,xy });
}

sf::Vector2f primitive_rectangle::getPosition()
{
	return rectangle.getPosition();
}

void primitive_rectangle::resize(sf::Vector2f newSize)
{
	rectangle.setSize({ rectangle.getSize().x + newSize.x,rectangle.getSize().y + newSize.y });
}

void primitive_rectangle::resize(float sizeX, float sizeY)
{
	rectangle.setSize({ rectangle.getSize().x + sizeX,rectangle.getSize().y + sizeY });
}

void primitive_rectangle::setSize(sf::Vector2f newSize)
{
	rectangle.setSize(newSize);
}

void primitive_rectangle::setSize(float sizeX, float sizeY)
{
	rectangle.setSize({ sizeX,sizeY });
}

sf::Vector2f primitive_rectangle::getSize()
{
	return rectangle.getSize();
}

int primitive_rectangle::getSizeX()
{
	return (int)rectangle.getSize().x;
}

int primitive_rectangle::getSizeY()
{
	return (int)rectangle.getSize().x;
}

void primitive_rectangle::translate(float x, float y, float dt)
{
	if (!selected)
		return;

	updateEdge();

	moving = true;

	if (farRight + x * dt < window.getSize().x && farLeft >= 0)
		point.setX(std::round(point.getX() + x * dt));

	if (farBottom + y * dt < window.getSize().y && farTop >= 0)
		point.setY(std::round(point.getY() + y * dt));

	if (point.getX() < 0)
		point.setX(0);

	if (point.getY() < 0)
		point.setY(0);

	prevPos = point.getPosition();
}

void primitive_rectangle::translate(sf::Vector2f translation, float dt)
{
	if (!selected)
		return;

	updateEdge();

	moving = true;

	if (farRight + translation.x * dt < window.getSize().x && farLeft > 0)
		point.setX(point.getX() + translation.x * dt);

	if (farBottom + translation.y * dt < window.getSize().y && farTop > 0)
		point.setY(point.getY() + translation.y * dt);

	if (point.getX() < 0)
		point.setX(0);

	if (point.getY() < 0)
		point.setY(0);

	prevPos = point.getPosition();
}

void primitive_rectangle::translate(float xy, float dt)
{
	if (!selected)
		return;

	updateEdge();

	moving = true;

	if (farRight + xy * dt < window.getSize().x && farLeft > 0)
		point.setX(point.getX() + xy * dt);

	if (farBottom + xy * dt < window.getSize().y && farTop > 0)
		point.setY(point.getY() + xy * dt);

	if (point.getX() < 0)
		point.setX(0);

	if (point.getY() < 0)
		point.setY(0);

	prevPos = point.getPosition();
}

void primitive_rectangle::rotate(float angle)
{
	rectangle.rotate(angle);
}

float primitive_rectangle::getRotaion()
{
	return rectangle.getRotation();
}

void primitive_rectangle::setScale(float scale)
{
	if (rectangle.getScale().x != scale || rectangle.getScale().y != scale)
		rectangle.setScale(scale, scale);
}

void primitive_rectangle::scale(float scale)
{
	rectangle.scale(scale,scale);
}

void primitive_rectangle::scale(float scaleX, float scaleY)
{
	rectangle.scale(scaleX, scaleY);
}

void primitive_rectangle::scale(sf::Vector2f scale)
{
	rectangle.scale(scale);
}
sf::Vector2f primitive_rectangle::getScale()
{
	return rectangle.getScale();
}

void primitive_rectangle::setTexture(sf::Texture* texture)
{
	if(rectangle.getTexture() != texture)
		rectangle.setTexture(texture);
}

void primitive_rectangle::setTextureRect(sf::IntRect rect)
{
	if(rectangle.getTextureRect() != rect)
		rectangle.setTextureRect(rect);
}

void primitive_rectangle::setColor(sf::Color color)
{
	if(this->texture.getColor()!=color)
		this->texture.setColor(color);
}

void primitive_rectangle::isPressed(sf::Vector2i mousePos)
{
	if ((mousePos.x >= farLeft && mousePos.x <= farRight)
		&& (mousePos.y >= farTop && mousePos.y <= farBottom))
	{
		selected = !selected;
		if (!selected)
			std::cout << "deselected\n";
		else
			std::cout << "selected\n";
	}
}

////////////////////////////////////// Square
////////////////////////////////////// Square
////////////////////////////////////// Square
void primitive_square::updateEdge()
{
	farRight = point.getX() + square.getSize().x + square.getOutlineThickness();
	farLeft = point.getX() - square.getOutlineThickness();
	farBottom = point.getY() + square.getSize().y + square.getOutlineThickness();
	farTop = point.getY() - square.getOutlineThickness();
}

void primitive_square::drawSquare(sf::Color color, unsigned int thickness)
{
	square.setPosition(point.getPosition());
	square.setFillColor({ 0,0,0,0 });
	square.setOutlineColor(color);
	square.setOutlineThickness(thickness);
	window.draw(square);
}

void primitive_square::drawFilledSquare(sf::Color color, unsigned int thickness)
{
	square.setPosition(point.getPosition());
	square.setOutlineColor(color);
	square.setFillColor(color);
	square.setOutlineThickness(thickness);
	window.draw(square);
}

void primitive_square::drawTexturedSquare(sf::Texture texture)
{
	square.setPosition(point.getPosition());
	square.setTexture(&texture);
	square.setTextureRect({ 0,0, getSizeX(), getSizeY() });
	window.draw(square);
}

void primitive_square::draw()
{
	square.setOutlineThickness(0);
	square.setPosition(point.getPosition());
	this->texture.setPosition(point.getPosition());
	if (std::round(prevPos.getX()) == std::round(point.getX()) && std::round(prevPos.getY()) == std::round(point.getY()))
		moving = false;
	else
		moving = true;

	window.draw(square);
	window.draw(this->texture);
}

void primitive_square::setPosition(sf::Vector2f position)
{
	point.setPosition(position);
	this->texture.setPosition(point.getPosition());
}

void primitive_square::setPosition(float x, float y)
{
	point.setPosition({ x,y });
	this->texture.setPosition(point.getPosition());
}

void primitive_square::setPosition(float xy)
{
	point.setPosition({ xy,xy });
	this->texture.setPosition(point.getPosition());
}

sf::Vector2f primitive_square::getPosition()
{
	return square.getPosition();
}

void primitive_square::resize(float newSize)
{
	square.setSize({ square.getSize().x + newSize,square.getSize().y + newSize });
}

void primitive_square::setSize(float newSize)
{
	square.setSize({ newSize,newSize });
}

float primitive_square::getSize()
{
	return square.getSize().x;
}

int primitive_square::getSizeX()
{
	return (int)square.getSize().x;
}

int primitive_square::getSizeY()
{
	return (int)square.getSize().x;
}

void primitive_square::translate(float x, float y, float dt)
{
	if (!selected)
		return;

	updateEdge();

	moving = true;

	if (farRight + x * dt < window.getSize().x && farLeft >= 0)
		point.setX(std::round(point.getX() + x * dt));

	if (farBottom + y * dt < window.getSize().y && farTop >= 0)
		point.setY(std::round(point.getY() + y * dt));

	if (point.getX() < 0)
		point.setX(0);

	if (point.getY() < 0)
		point.setY(0);

	prevPos = point.getPosition();
}

void primitive_square::translate(sf::Vector2f translation, float dt)
{
	if (!selected)
		return;

	updateEdge();

	moving = true;

	if (farRight + translation.x * dt < window.getSize().x && farLeft > 0)
		point.setX(point.getX() + translation.x * dt);

	if (farBottom + translation.y * dt < window.getSize().y && farTop > 0)
		point.setY(point.getY() + translation.y * dt);

	if (point.getX() < 0)
		point.setX(0);

	if (point.getY() < 0)
		point.setY(0);

	prevPos = point.getPosition();
}

void primitive_square::translate(float xy, float dt)
{
	if (!selected)
		return;

	updateEdge();

	moving = true;

	if (farRight + xy * dt < window.getSize().x && farLeft >= 0)
		point.setX(std::round(point.getX() + xy * dt));

	if (farBottom + xy * dt < window.getSize().y && farTop >= 0)
		point.setY(std::round(point.getY() + xy * dt));

	if (point.getX() < 0)
		point.setX(0);

	if (point.getY() < 0)
		point.setY(0);

	prevPos = point.getPosition();
}

void primitive_square::rotate(float angle, float dt)
{
	square.rotate(angle * dt);
}

float primitive_square::getRotation()
{
	return square.getRotation();
}

void primitive_square::setScale(float scale)
{
	square.setScale({ scale,scale });
}

void primitive_square::scale(float scale)
{
	square.scale({scale,scale});
}

void primitive_square::scale(float scaleX, float scaleY)
{
	square.scale({ scaleX,scaleY });
}

void primitive_square::scale(sf::Vector2f scale)
{
	square.scale(scale);
}
sf::Vector2f primitive_square::getScale()
{
	return square.getScale();
}
void primitive_square::setTexture(sf::Texture* texture)
{
	square.setTexture(texture);
	this->texture.setTexture(*texture);
}

void primitive_square::setTextureRect(sf::IntRect rect)
{
	square.setTextureRect(rect);
	this->texture.setTextureRect(rect);
}

void primitive_square::setColor(sf::Color color)
{
	this->texture.setColor(color);
}

void primitive_square::isPressed(sf::Vector2i mousePos)
{
	if ((mousePos.x >= farLeft && mousePos.x <= farRight)
		&& (mousePos.y >= farTop && mousePos.y <= farBottom))
	{
		selected = !selected;
		if (!selected)
			std::cout << "deselected\n";
		else
			std::cout << "selected\n";
	}
}
////////////////////////////////////// Triangle
////////////////////////////////////// Triangle
////////////////////////////////////// Triangle
void primitive_triangle::updateEdge()
{
	farLeft = triangle.getGlobalBounds().left;
	farRight = triangle.getGlobalBounds().width;
	farTop = triangle.getGlobalBounds().top;
	farBottom = triangle.getGlobalBounds().height;
}
void primitive_triangle::drawTriangle(sf::Color color, unsigned int thickness, unsigned int radius)
{
	triangle.setRadius(radius);
	triangle.setPosition(point.getPosition());
	triangle.setPointCount(3);
	triangle.setFillColor({ 0,0,0,0 });
	triangle.setOutlineColor(color);
	triangle.setOutlineThickness(thickness);
	triangle.setPosition(point.getPosition());
	window.draw(triangle);
}

void primitive_triangle::drawFIlledTriangle(sf::Color color, unsigned int thickness, unsigned int radius)
{
	triangle.setRadius(radius);
	triangle.setPosition(point.getPosition());
	triangle.setPointCount(3);
	triangle.setOutlineColor(color);
	triangle.setFillColor(color);
	triangle.setOutlineThickness(thickness);
	window.draw(triangle);
}

void primitive_triangle::drawTexturedTriangle(sf::Texture texture)
{
	triangle.setPosition(point.getPosition());
	triangle.setTexture(&texture);
	triangle.setPointCount(3);
	triangle.setTextureRect({ 0,0, getSizeX(), getSizeY() });
	window.draw(triangle);
}

void primitive_triangle::draw()
{
	triangle.setOutlineThickness(0);
	triangle.setPosition(point.getPosition());
	triangle.setPointCount(3);
	this->texture.setPosition(point.getPosition());
	if (std::round(prevPos.getX()) == std::round(point.getX()) && std::round(prevPos.getY()) == std::round(point.getY()))
		moving = false;
	else
		moving = true;

	window.draw(triangle);
}

void primitive_triangle::setPosition(sf::Vector2f position)
{
	point.setPosition(position);
}

sf::Vector2f primitive_triangle::getPosition()
{
	return point.getPosition();
}

void primitive_triangle::resize(float newSize)
{
	triangle.setRadius(triangle.getRadius()+newSize);
}

void primitive_triangle::setSize(float newSize)
{
	triangle.setRadius(newSize);
}

float primitive_triangle::getSize()
{
	return triangle.getRadius();
}

int primitive_triangle::getSizeX()
{
	return triangle.getRadius();
}

int primitive_triangle::getSizeY()
{
	return triangle.getRadius();
}

void primitive_triangle::translate(float x, float y, float dt)
{
	updateEdge();

	moving = true;

	if (farRight + x * dt < window.getSize().x && farLeft >= 0)
		point.setX(std::round(point.getX() + x * dt));

	if (farBottom + y * dt < window.getSize().y && farTop >= 0)
		point.setY(std::round(point.getY() + y * dt));

	if (point.getX() < 0)
		point.setX(0);

	if (point.getY() < 0)
		point.setY(0);

	prevPos = point.getPosition();
}

void primitive_triangle::translate(sf::Vector2f translation, float dt)
{
	updateEdge();

	moving = true;

	if (farRight + translation.x * dt < window.getSize().x && farLeft > 0)
		point.setX(point.getX() + translation.x * dt);

	if (farBottom + translation.y * dt < window.getSize().y && farTop > 0)
		point.setY(point.getY() + translation.y * dt);

	if (point.getX() < 0)
		point.setX(0);

	if (point.getY() < 0)
		point.setY(0);

	prevPos = point.getPosition();
}

void primitive_triangle::translate(float xy, float dt)
{
	updateEdge();

	moving = true;

	if (farRight + xy * dt < window.getSize().x && farLeft >= 0)
		point.setX(std::round(point.getX() + xy * dt));

	if (farBottom + xy * dt < window.getSize().y && farTop >= 0)
		point.setY(std::round(point.getY() + xy * dt));

	if (point.getX() < 0)
		point.setX(0);

	if (point.getY() < 0)
		point.setY(0);

	prevPos = point.getPosition();
}

void primitive_triangle::rotate(float angle, float dt)
{
	triangle.rotate(angle * dt);
}

void primitive_triangle::setScale(float scale)
{
	triangle.setScale({scale,scale});
}

void primitive_triangle::scale(float scale)
{
	triangle.scale({ scale,scale });
}

void primitive_triangle::scale(float scaleX, float scaleY)
{
	triangle.scale({ scaleX,scaleY });
}

void primitive_triangle::scale(sf::Vector2f scale)
{
	triangle.scale(scale);
}
sf::Vector2f primitive_triangle::getScale()
{
	return triangle.getScale();
}

void primitive_triangle::setTexture(sf::Texture* texture)
{
	triangle.setTexture(texture);
	this->texture.setTexture(*texture);
}

void primitive_triangle::setTextureRect(sf::IntRect rect)
{
	triangle.setTextureRect(rect);
	this->texture.setTextureRect(rect);
}

void primitive_triangle::setColor(sf::Color color)
{
	triangle.setFillColor(color);
	this->texture.setColor(color);
}
////////////////////////////////////// Circle
////////////////////////////////////// Circle
////////////////////////////////////// Circle
void primitive_circle::updateEdge()
{
	farLeft = circle.getGlobalBounds().left;
	farRight = circle.getGlobalBounds().width;
	farTop = circle.getGlobalBounds().top;
	farBottom = circle.getGlobalBounds().height;
}
void primitive_circle::drawCircle(sf::Color color, unsigned int thickness, unsigned int radius)
{
	circle.setRadius(radius);
	circle.setPosition(point.getPosition());
	circle.setFillColor({ 0,0,0,0 });
	circle.setOutlineColor(color);
	circle.setOutlineThickness(thickness);
	circle.setPosition(point.getPosition());
	window.draw(circle);
}

void primitive_circle::drawFilledCircle(sf::Color color, unsigned int thickness, unsigned int radius)
{
	circle.setRadius(radius);
	circle.setPosition(point.getPosition());
	circle.setOutlineColor(color);
	circle.setFillColor(color);
	circle.setOutlineThickness(thickness);
	window.draw(circle);
}

void primitive_circle::drawTexturedCircle(sf::Texture texture)
{
	circle.setPosition(point.getPosition());
	circle.setTexture(&texture);
	circle.setTextureRect({ 0,0, getSizeX(), getSizeY() });
	window.draw(circle);
}

void primitive_circle::draw()
{
	circle.setOutlineThickness(0);
	circle.setPosition(point.getPosition());
	this->texture.setPosition(point.getPosition());
	if (std::round(prevPos.getX()) == std::round(point.getX()) && std::round(prevPos.getY()) == std::round(point.getY()))
		moving = false;
	else
		moving = true;

	window.draw(circle);
}

void primitive_circle::setPosition(sf::Vector2f position)
{
	point.setPosition(position);
}

sf::Vector2f primitive_circle::getPosition()
{
	return point.getPosition();
}

void primitive_circle::resize(float newSize)
{
	circle.setRadius(circle.getRadius() + newSize);
}

void primitive_circle::setSize(float newSize)
{
	circle.setRadius(newSize);
}

float primitive_circle::getSize()
{
	return circle.getRadius();
}

int primitive_circle::getSizeX()
{
	return circle.getRadius();
}

int primitive_circle::getSizeY()
{
	return circle.getRadius();
}

void primitive_circle::translate(float x, float y, float dt)
{
	updateEdge();

	moving = true;

	if (farRight + x * dt < window.getSize().x && farLeft >= 0)
		point.setX(std::round(point.getX() + x * dt));

	if (farBottom + y * dt < window.getSize().y && farTop >= 0)
		point.setY(std::round(point.getY() + y * dt));

	if (point.getX() < 0)
		point.setX(0);

	if (point.getY() < 0)
		point.setY(0);

	prevPos = point.getPosition();
}

void primitive_circle::translate(sf::Vector2f translation, float dt)
{
	updateEdge();

	moving = true;

	if (farRight + translation.x * dt < window.getSize().x && farLeft > 0)
		point.setX(point.getX() + translation.x * dt);

	if (farBottom + translation.y * dt < window.getSize().y && farTop > 0)
		point.setY(point.getY() + translation.y * dt);

	if (point.getX() < 0)
		point.setX(0);

	if (point.getY() < 0)
		point.setY(0);

	prevPos = point.getPosition();
}

void primitive_circle::translate(float xy, float dt)
{
	updateEdge();

	moving = true;

	if (farRight + xy * dt < window.getSize().x && farLeft >= 0)
		point.setX(std::round(point.getX() + xy * dt));

	if (farBottom + xy * dt < window.getSize().y && farTop >= 0)
		point.setY(std::round(point.getY() + xy * dt));

	if (point.getX() < 0)
		point.setX(0);

	if (point.getY() < 0)
		point.setY(0);

	prevPos = point.getPosition();
}

void primitive_circle::rotate(float angle, float dt)
{
	circle.rotate(angle * dt);
}

void primitive_circle::setScale(float scale)
{
	circle.setScale({ scale,scale });
}

void primitive_circle::scale(float scale)
{
	circle.scale({ scale,scale });
}

void primitive_circle::scale(float scaleX, float scaleY)
{
	circle.scale({ scaleX,scaleY });
}

void primitive_circle::scale(sf::Vector2f scale)
{
	circle.scale(scale);
}

sf::Vector2f primitive_circle::getScale()
{
	return circle.getScale();
}
void primitive_circle::setTexture(sf::Texture* texture)
{
	circle.setTexture(texture);
	this->texture.setTexture(*texture);
}

void primitive_circle::setTextureRect(sf::IntRect rect)
{
	circle.setTextureRect(rect);
	this->texture.setTextureRect(rect);
}

void primitive_circle::setColor(sf::Color color)
{
	circle.setFillColor(color);
	this->texture.setColor(color);
}
////////////////////////////////////// Line
////////////////////////////////////// Line
////////////////////////////////////// Line
void primitive_line::drawLine(sf::Color color)
{
	line[0].color = color;
	line[1].color = color;
	window.draw(line,2,sf::Lines);
}

void primitive_line::setPosition(sf::Vector2f point1, sf::Vector2f point2)
{
	line[0].position = point1;
	line[1].position = point2;
}

void primitive_line::setThickness(unsigned int thickness)
{
}

void primitive_line::translate(sf::Vector2f newPoint1, sf::Vector2f newPoint2)
{
	line[0].position = { line[0].position.x + newPoint1.x, line[0].position.y = newPoint1.y };
	line[1].position = { line[1].position.x + newPoint2.x, line[1].position.y = newPoint2.y };
}

void primitive_line::rotate(float angle, float dt)
{
	if (angle > 360)
		angle -= 360;

	float x1, x2;
	float y1, y2;
	
	x1 = line[0].position.x; y1 = line[0].position.y;
	x2 = line[1].position.x; y2 = line[1].position.y;
	line[0].position.x = x1 * cos(angle) - y1 * sin(angle);
	line[0].position.y = x1 * sin(angle) + y2 * cos(angle);

	line[1].position.x = x2 * cos(angle) - y2 * sin(angle);
	line[1].position.y = x2 * sin(angle) + y2 * cos(angle);
	std::printf("Linia %f %f, %f %f\n", line[0].position.x, line[0].position.y, line[1].position.x, line[1].position.y);
}

void primitive_line::scale(float scale)
{
}

////////////////////////////////////// Convex
////////////////////////////////////// Convex
////////////////////////////////////// Convex

void primitive_convex::drawConvex(sf::Color color, float thickness)
{
	convex.setPosition(point.getPosition());
	convex.setFillColor({0,0,0,0});
	convex.setOutlineColor(color);
	convex.setOutlineThickness(thickness);
	window.draw(convex);
}

void primitive_convex::drawFilledConvex(sf::Color color, float thickness)
{
	convex.setPosition(point.getPosition());
	convex.setFillColor(color);
	convex.setOutlineColor(color);
	convex.setOutlineThickness(thickness);
	window.draw(convex);
}

void primitive_convex::setPoint(unsigned int index, sf::Vector2f point)
{
	if (index > convex.getPointCount() || index < 0)
		return;

	convex.setPoint(index, point);
}

void primitive_convex::setPoint(unsigned int index, float pointX, float pointY)
{
	if (index > convex.getPointCount() || index < 0)
		return;

	convex.setPoint(index, { pointX,pointY });
}

void primitive_convex::setPointCount(unsigned int pointCount)
{
	convex.setPointCount(pointCount);
}

void primitive_convex::setPointPosition(std::vector<sf::Vector2f> pointPosition)
{
	/*
	if (convex.getPointCount() != pointPosition.size())
		return;
	*/

	for (int i = 0; i < convex.getPointCount(); i++)
		convex.setPoint(i,pointPosition[i]);
}

int primitive_convex::getPointCount()
{
	return convex.getPointCount();
}

sf::Vector2f primitive_convex::getPoint(unsigned int index)
{
	if (index > convex.getPointCount() || index < 0)
		return { NULL,NULL };

	return convex.getPoint(index);
}

std::vector<sf::Vector2f> primitive_convex::getPointsPosition()
{
	std::vector<sf::Vector2f> pointPosition = {};

	for (int i = 0; i < convex.getPointCount(); i++)
	{
		pointPosition.push_back(convex.getPoint(i));
	}

	return pointPosition;
}

void primitive_convex::setPosition(sf::Vector2f position)
{
	convex.setPosition(position);
}

void primitive_convex::setPosition(float newX, float newY)
{
	convex.setPosition({ newX,newY });
}

void primitive_convex::setPosition(float newXY)
{
	convex.setPosition({ newXY,newXY });
}

sf::Vector2f primitive_convex::getPosition()
{
	return convex.getPosition();
}

void primitive_convex::translate(sf::Vector2f translation, float dt)
{
	std::vector<sf::Vector2f> points = getPointsPosition();
	for (int i = 0; i < convex.getPointCount(); i++)
	{
		points[i].x += translation.x*dt;
		points[i].y += translation.y*dt;
	}
}

void primitive_convex::translate(float newX, float newY, float dt)
{
	std::vector<sf::Vector2f> points = getPointsPosition();
	for (int i = 0; i < convex.getPointCount(); i++)
	{
		points[i].x += newX*dt;
		points[i].y += newY*dt;
	}
}

void primitive_convex::rotate(float angle)
{
	convex.rotate(angle);
}

float primitive_convex::getRotation()
{
	return convex.getRotation();
}

void primitive_convex::setScale(sf::Vector2f scale)
{
	convex.setScale(scale);
}

void primitive_convex::setScale(float scaleX, float scaleY)
{
	convex.setScale({ scaleX,scaleY });
}

void primitive_convex::setScale(float scale)
{
	convex.setScale({ scale,scale });
}

void primitive_convex::scale(sf::Vector2f scale)
{
	convex.scale(scale);
}

void primitive_convex::scale(float scaleX, float scaleY)
{
	convex.scale({ scaleX,scaleY });
}

void primitive_convex::scale(float scale)
{
	convex.scale({ scale,scale });
}

sf::Vector2f primitive_convex::getScale()
{
	return convex.getScale();
}
