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
	//inicjalizacja
	void init();
	void initWindow(float height, float width, bool fullscreen, std::string title);
	bool paused = false;

public:
	sf::RenderWindow* window;
	sf::Event event;
	//(de)konstruktor
	engine(float height, float width, bool fullscreen, std::string title);
	virtual ~engine();


	//obsluga
	const bool gameRunning();
	void clearToColor(sf::Color);
	void render();
	void setFramerate(unsigned int framerate);
	bool enginePaused();
	void pause();
};


