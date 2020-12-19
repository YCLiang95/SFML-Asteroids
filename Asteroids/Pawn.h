#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Pawn {
public:
	//The x, y postion of the ball
	float x, y;

	float radius;

	//The direction of the ball
	float speedx, speedy;

	sf::CircleShape shape;

	int hp = 1;

	bool isDead;

	Pawn();

public:
	void virtual Update();
	void virtual Draw();
	void virtual Collide(Pawn) {};
	void virtual Destroy() {
		isDead = true;
	};
};