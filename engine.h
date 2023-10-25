#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
class engine
{
private:
	sf::VideoMode videoMode;
	sf::Event event;
	sf::Clock clock;

	//inicjalizacja
	void init();
	void initWindow();

public:
	sf::RenderWindow* window;
	//(de)konstruktor
	engine();
	virtual ~engine();


	//obsluga
	const bool gameRunning();
	void pollEvents();
	void update();
	void clearToColor(sf::Color);
	void render();
	void setFramerate(unsigned int framerate);
	void startClock();
	float getClockTime();

};

