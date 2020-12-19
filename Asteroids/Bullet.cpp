#include "Bullet.h"
#include "GameManager.h"

Bullet::Bullet(float x, float y, float speedx, float speedy) : Particle(x, y, sf::Color::White, lifespan){
	this->lifespan = 500.0f;
	this->x = x;
	this->y = y;
	this->speedx = speedx;
	this->speedy = speedy;
}

void Bullet::Update() {
	Particle::Update();
	if (x < 0 || y < 0 || x > GameManager::getInstance()->width || y > GameManager::getInstance()->height) {
		isDead = true;
		return;
	}
}