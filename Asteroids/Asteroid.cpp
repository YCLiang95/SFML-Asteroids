#include "Asteroid.h"

Asteroid::Asteroid(int size) : Pawn() {
	hp = size;
	if (size == 3)
		shape.setRadius(15);
	else if (size == 2)
		shape.setRadius(10);
	else
		shape.setRadius(5);

	speedx = -rand() % 300 + 150;
	speedy = -rand() % 300 + 150;

	x = rand() % 800;
	y = rand() % 600;
}

void Asteroid::Update() {
	Pawn::Update();
	
	if (x < 0) x = GameManager::getInstance()->width;
	if (y < 0) y = GameManager::getInstance()->height;
	if (x > GameManager::getInstance()->width) x = 0;
	if (y > GameManager::getInstance()->height) y = 0;
}