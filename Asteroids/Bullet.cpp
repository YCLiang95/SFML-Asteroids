#include "Bullet.h"
#include "GameManager.h"

Bullet::Bullet(float x, float y, float speedx, float speedy) : Pawn(){
	this->x = x;
	this->y = y;
	this->speedx = speedx;
	this->speedy = speedy;
	shape.setRadius(5);
	radius = 5;
}

void Bullet::Update() {
	Pawn::Update();
	if (x < 0 || y < 0 || x > GameManager::getInstance()->width || y > GameManager::getInstance()->height) {
		isDead = true;
		return;
	}
}