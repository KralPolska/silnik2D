#include "engine.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#define swap(a, b) (a ^= b, b = a ^ b, a ^= b)

//Inicjalizacja

void engine::init()
{
	this->window = nullptr;
}

void engine::initWindow(float height, float width, bool fullscreen, std::string title)
{
	this->videoMode.height = height;
	this->videoMode.width = width;

	if (fullscreen)
		this->window = new sf::RenderWindow(this->videoMode, title, sf::Style::Titlebar | sf::Style::Close);
	else
		this->window = new sf::RenderWindow(this->videoMode, title, sf::Style::Titlebar | sf::Style::Close | sf::Style::Fullscreen);

}

//(de)Konstruktor
engine::engine(float height, float width, bool fullscreen, std::string title)
{
	this->init();
	this->initWindow(height,width,fullscreen,title);
}

engine::~engine()
{
	delete this->window;
}

//Obsluga
const bool engine::gameRunning()
{
	return (this->window->isOpen());
}

void engine::clearToColor(sf::Color color)
{
	this->window->clear(color);
}

void engine::render()
{
	this->window->display();
}

void engine::setFramerate(unsigned int framerate)
{
	this->window->setFramerateLimit(framerate);
}

bool engine::enginePaused()
{
	return paused;
}

void engine::pause()
{
	paused = !paused;
}
