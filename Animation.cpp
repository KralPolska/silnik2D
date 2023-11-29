#include "Animation.h"
#include <iostream>
Animation::Animation(sf::Texture* texture, sf::Vector2u frameCount, float refreshRate)
{
	this->frameCount = frameCount;
	this->framePosition = { 0,0 };;
	this->refreshRate = refreshRate;
	this->totalTime = 0.0f;
	this->uvRect.width = texture->getSize().x / frameCount.x;
	this->uvRect.height = texture->getSize().y / frameCount.y;
}

void Animation::update(float dt, unsigned int state)
{
	
	framePosition.x = state;
	totalTime += dt*1.2;

	if (totalTime < refreshRate)
		return;

		totalTime = 0;
		framePosition.y++;
		if (framePosition.x >= frameCount.x)
			framePosition.x = 0;
		if (framePosition.y >= frameCount.y)
			framePosition.y = 0;

		uvRect.left = framePosition.x * uvRect.width;
		uvRect.top = framePosition.y * uvRect.height;
}

void Animation::setRefreshRate(float newRefreshRate)
{
	this->refreshRate = newRefreshRate;
}
