#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class CircleCollider {
public:
	//The x, y postion of the ball
	float x, y;

	float radius;

	//The direction of the ball
	float speedx, speedy;

	bool isLauched;

	sf::CircleShape shape;

	CircleCollider();

public:
	void Update();
	void Draw();
};