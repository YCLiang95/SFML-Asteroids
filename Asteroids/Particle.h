#pragma once
#include <SFML/Graphics.hpp>

class Particle {
public:
	float lifespan;
	float timeSinceCreated;

	float x, y;
	float speedx, speedy;

	bool isDead;

	sf::CircleShape shape;

	Particle(float x, float y, float speedx, float speedy, sf::Color color, float lifespan = 3.0f) {
		this->x = x;
		this->y = y;
		this->lifespan = lifespan;
		timeSinceCreated = 0.0f;
		this->speedx = speedx;
		this->speedy = speedy;
		this->speedx += -rand() % 100 + 50;
		this->speedy += -rand() % 100 + 50;
		isDead = false;

		shape.setRadius(3);
		shape.setFillColor(color);
	}

	void virtual Update();
	void Draw();
};