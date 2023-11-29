#pragma once
#include "point2D.h"
#include "test.h"
#include "Animation.h"
/////////////////// LINIA DO POPRAWIENIA

class primitive
{
protected:
	sf::RenderWindow& window;
	sf::Image image;
	int farRight;
	int farLeft;
	int farBottom;
	int farTop;
	sf::Sprite texture;
	point2D prevPos;
	point2D point;
public:
	bool moving;
	bool selected;
	primitive(sf::RenderWindow& window);
};

class primitive_rectangle : public primitive{
	sf::RectangleShape rectangle;
public:
	using primitive::primitive;
	
	void updateEdge();
	
	void drawRectangle(sf::Color color, unsigned int thickness);
	void drawFilledRectangle(sf::Color color, unsigned int thickness);
	void drawTexturedRectangle(sf::Texture texture);
	void draw();

	void setPosition(sf::Vector2f position);
	void setPosition(float x, float y);
	void setPosition(float xy);
	
	sf::Vector2f getPosition();

	void resize(sf::Vector2f newSize);
	void resize(float sizeX, float sizeY);
	
	void setSize(sf::Vector2f newSize);
	void setSize(float sizeX, float sizeY);

	sf::Vector2f getSize();
	int getSizeX();
	int getSizeY();

	void translate(float x, float y, float dt);
	void translate(sf::Vector2f translation, float dt);
	void translate(float xy, float dt);

	void rotate(float angle);
	
	float getRotaion();

	void setScale(float scale);
	
	void scale(float scale);
	void scale(float scaleX, float scaleY);
	void scale(sf::Vector2f scale);
	
	sf::Vector2f getScale();

	void setTexture(sf::Texture* texture);
	void setTextureRect(sf::IntRect rect);
	void setColor(sf::Color color);
	
	void isPressed(sf::Vector2i mousePos);
};

class primitive_square : public primitive {
	sf::RectangleShape square;
public:
	using primitive::primitive;
	
	void updateEdge();

	void drawSquare(sf::Color color, unsigned int thickness);
	void drawFilledSquare(sf::Color color, unsigned int thickness);
	void drawTexturedSquare(sf::Texture texture);
	void draw();

	void setPosition(sf::Vector2f position);
	void setPosition(float x, float y);
	void setPosition(float xy);
	sf::Vector2f getPosition();

	void resize(float newSize);
	void setSize(float newSize);
	float getSize();

	int getSizeX();
	int getSizeY();

	void translate(float x, float y, float dt);
	void translate(sf::Vector2f translation, float dt);
	void translate(float xy, float dt);

	void rotate(float angle, float dt);
	float getRotation();

	void setScale(float scale);
	void scale(float scale);
	void scale(float scaleX, float scaleY);
	void scale(sf::Vector2f scale);
	sf::Vector2f getScale();

	void setTexture(sf::Texture* texture);
	void setTextureRect(sf::IntRect rect);
	void setColor(sf::Color color);

	void isPressed(sf::Vector2i mousePos);
};

class primitive_triangle : public primitive {
	sf::CircleShape triangle;
public:
	using primitive::primitive;
	void updateEdge();
	void drawTriangle(sf::Color color, unsigned int thickness, unsigned int radius);
	void drawFIlledTriangle(sf::Color color, unsigned int thickness, unsigned int radius);
	void drawTexturedTriangle(sf::Texture texture);
	void draw();

	void setPosition(sf::Vector2f position);
	sf::Vector2f getPosition();

	void resize(float newSize);
	void setSize(float newSize);
	float getSize();

	int getSizeX();
	int getSizeY();

	void translate(float x, float y, float dt);
	void translate(sf::Vector2f translation, float dt);
	void translate(float xy, float dt);

	void rotate(float angle, float dt);

	void setScale(float scale);
	void scale(float scale);
	void scale(float scaleX, float scaleY);
	void scale(sf::Vector2f scale);
	sf::Vector2f getScale();

	void setTexture(sf::Texture* texture);
	void setTextureRect(sf::IntRect rect);
	void setColor(sf::Color color);
};

class primitive_circle : public primitive {
	sf::CircleShape circle;
public:
	using primitive::primitive;
	void updateEdge();
	void drawCircle(sf::Color color, unsigned int thickness, unsigned int radius);
	void drawFilledCircle(sf::Color color, unsigned int thickness, unsigned int radius);
	void drawTexturedCircle(sf::Texture texture);
	void draw();

	void setPosition(sf::Vector2f position);
	sf::Vector2f getPosition();

	void resize(float newSize);
	void setSize(float newSize);
	float getSize();

	int getSizeX();
	int getSizeY();

	void translate(float x, float y, float dt);
	void translate(sf::Vector2f translation, float dt);
	void translate(float xy, float dt);

	void rotate(float angle, float dt);

	void setScale(float scale);
	void scale(float scale);
	void scale(float scaleX, float scaleY);
	void scale(sf::Vector2f scale);
	sf::Vector2f getScale();

	void setTexture(sf::Texture* texture);
	void setTextureRect(sf::IntRect rect);
	void setColor(sf::Color color);
	
};

class primitive_line : public primitive {
	sf::Vertex line[2];
public:
	using primitive::primitive;

	void drawLine(sf::Color color);

	void setPosition(sf::Vector2f point1, sf::Vector2f point2);
	void setThickness(unsigned int thickness);
	void translate(sf::Vector2f newPoint1, sf::Vector2f newPoint2);
	void rotate(float angle, float dt);
	void scale(float scale);
};

class primitive_convex : public primitive {
	sf::ConvexShape convex;
public:
	using primitive::primitive;
	
	void drawConvex(sf::Color color, float thickness);
	void drawFilledConvex(sf::Color color, float thickness);

	void setPoint(unsigned int index, sf::Vector2f point);
	void setPoint(unsigned int index, float pointX, float pointY);
	void setPointCount(unsigned int pointCount);
	void setPointPosition(std::vector<sf::Vector2f> pointPosition);
	int getPointCount();
	sf::Vector2f getPoint(unsigned int index);
	std::vector<sf::Vector2f> getPointsPosition();

	void setPosition(sf::Vector2f position);
	void setPosition(float newX, float newY);
	void setPosition(float newXY);
	sf::Vector2f getPosition();

	void translate(sf::Vector2f tranlstaion, float dt);
	void translate(float newX, float newY, float dt);

	void rotate(float angle);
	float getRotation();

	void setScale(sf::Vector2f scale);
	void setScale(float scaleX, float scaleY);
	void setScale(float scale);
	void scale(sf::Vector2f scale);
	void scale(float scaleX, float scaleY);
	void scale(float scale);
	sf::Vector2f getScale();

};







