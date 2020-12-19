#include "Ship.h"
#include "GameManager.h"
#include <math.h>
#include "Bullet.h"
#include "PawnSystem.h"

void Ship::Draw() {
	Pawn::Draw();
	sprite.setPosition(x, y);
	sprite.setRotation(angle);
	GameManager::getInstance()->window.draw(sprite);
}

void Ship::Update() {
	fireTimer += GameManager::getInstance()->deltaTime;

	//Aiming
	sf::Vector2i mousePosition = sf::Mouse::getPosition(GameManager::getInstance()->window);
	sf::Vector2f dir = sf::Vector2f(mousePosition.x - x, mousePosition.y - y);
	angle = atan2(dir.y, dir.x) * 180 / 3.1415926f;
	dir = dir / (sqrtf(dir.x * dir.x + dir.y * dir.y));
	if (angle < 0) angle += 360.0f;

	//Propulsing
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		speedx += dir.x * speed * GameManager::getInstance()->deltaTime;
		speedy += dir.y * speed * GameManager::getInstance()->deltaTime;
	}

	//Firing
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && fireTimer > fireTime) {
		fireTimer = 0;
		Bullet* bullet = new Bullet(x + dir.x * 5.0f, y + dir.y * 5.0f, dir.x * 100.0f, dir.y * 100.0f);
		ParticleSystem::getInstance()->Add(bullet);
	}
	
	Pawn::Update();
}