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

void engine::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;

	this->window = new sf::RenderWindow(this->videoMode, "Silnik", sf::Style::Titlebar | sf::Style::Close);
}

//(de)Konstruktor
engine::engine()
{
	this->init();
	this->initWindow();
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

void engine::pollEvents()
{
	while (this->window->pollEvent(this->event))
	{
		if (this->event.type == sf::Event::Closed)
			this->window->close();
		//Klawiatura
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			this->window->close();
		

		//mysz
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			std::cout << "Lewy";

		if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
			std::cout << "Prawy";

		if (sf::Mouse::isButtonPressed(sf::Mouse::Middle))
			std::cout << "Scroll";

		if (this->event.type == sf::Event::MouseWheelScrolled)
		{
			if (this->event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel)
				std::cout << "Scrolled";
		}
	}
}

void engine::update()
{
	this->pollEvents();
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

//Zegar
void engine::startClock()
{
	this->clock.restart();
}

float engine::getClockTime()
{
	return this->clock.getElapsedTime().asSeconds();
}
