#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
class Animation
{
private:
	sf::Vector2u frameCount;
	sf::Vector2u framePosition;
	float refreshRate;
	float totalTime;

public:
	sf::IntRect uvRect;
	
	Animation(sf::Texture* texture, sf::Vector2u frameCount, float refreshRate);
	
	void update(float dt, unsigned int state);

	void setRefreshRate(float newRefreshRate);
};

