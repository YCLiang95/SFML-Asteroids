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

	type = "Asteroid";
}

void Asteroid::Update() {
	Pawn::Update();
	
	if (x < 0) x = GameManager::getInstance()->width;
	if (y < 0) y = GameManager::getInstance()->height;
	if (x > GameManager::getInstance()->width) x = 0;
	if (y > GameManager::getInstance()->height) y = 0;
}

void Asteroid::Destroy() {
	isDead = true;
	if (hp > 1) {
		Asteroid* small1 = new Asteroid(hp - 1);
		Asteroid* small2 = new Asteroid(hp - 1);

		small1->speedx = speedx;
		small1->speedy = speedy;
		small2->speedx = -speedx;
		small2->speedy = -speedy;
		small1->x = x + radius;
		small1->y = y + radius;
		small2->x = x - radius;
		small2->y = y - radius;

		PawnSystem::getInstance()->Add(small1);
		PawnSystem::getInstance()->Add(small2);
	}
}