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
	respawnTimer += GameManager::getInstance()->deltaTime;

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
		Particle* particle = new Particle(x -dir.x * 5.0f + radius, y - dir.y * 5.0f + radius, -speedx - dir.x * 100.0f, -speedy - dir.y * 100.0f, sf::Color::Red, 0.5f);
		ParticleSystem::getInstance()->Add(particle);
	}

	//Firing
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && fireTimer > fireTime) {
		fireTimer = 0;
		Bullet* bullet = new Bullet(x + dir.x * 5.0f, y + dir.y * 5.0f, speedx + dir.x * 300.0f, speedy + dir.y * 300.0f);
		PawnSystem::getInstance()->Add(bullet);
	}
	
	Pawn::Update();

	if (x < 0) x = GameManager::getInstance()->width;
	if (y < 0) y = GameManager::getInstance()->height;
	if (x > GameManager::getInstance()->width) x = 0;
	if (y > GameManager::getInstance()->height) y = 0;
}

Ship::Ship() : Pawn(){
	type = "Ship";
	angle = 0;
	fireTime = 1.0f;
	fireTimer = 1.0f;

	speed = 50.0f;
}

void Ship::Collide(Pawn* pawn) {
	if (respawnTimer < respawnInvi)
		return;

	if (pawn->type.compare("Astroid") == 0) {
		Destroy();
		std::cout << pawn->x << "," << pawn->y << std::endl;
	}
	else
		std::cout << "Collide with bullet" << std::endl;
}

void Ship::Destroy() {
	if (GameManager::getInstance()->life > 1) {
		GameManager::getInstance()->life -= 1;
		respawnTimer = 0;
		x = 400;
		y = 300;
		speedx = 0.0f;
		speedy = 0.0f;
	} else {
		isDead = true;
		GameManager::getInstance()->state = STATE_GAMEOVER;
	}
}