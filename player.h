#pragma once
#include "Animation.h"
#include "primitive.h"
class player : public Animation, public primitive_rectangle
{
private:
	int health;
	Animation anim;
	primitive_rectangle hitbox;
public:
	player(sf::Texture texture);
};

