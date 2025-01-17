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

	if (!bufferHitSound.loadFromFile("hit.wav")) {
		std::cout << "Failded to load hit sound" << std::endl;
	}
	hitSound.setBuffer(bufferHitSound);

	if (!texture.loadFromFile("asteroid.png")) {
		std::cout << "Faild to load image" << std::endl;
		return;
	}
	sprite.setTexture(texture);
	sprite.setScale(0.03f * hp, 0.03f * hp);
	sprite.setOrigin(400, 400);
}

void Asteroid::Update() {
	Pawn::Update();
	
	if (x < 0) x = GameManager::getInstance()->width;
	if (y < 0) y = GameManager::getInstance()->height;
	if (x > GameManager::getInstance()->width) x = 0;
	if (y > GameManager::getInstance()->height) y = 0;
}

void Asteroid::Destroy() {
	if (isDead)
		return;
	for (int i = 0; i < 100; i++) {
		Particle* particle = new Particle(x, y, -rand() % 400 + 200, -rand() % 400 + 200, sf::Color::Red, (rand() % 5) / 10.0f + 0.2f);
		ParticleSystem::getInstance()->Add(particle);
	}
	hitSound.play();
	isDead = true;
	GameManager::getInstance()->asteroidsCount -= 1;
	GameManager::getInstance()->score += 1;
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
		GameManager::getInstance()->asteroidsCount += 2;

		PawnSystem::getInstance()->Add(small1);
		PawnSystem::getInstance()->Add(small2);
	}
}

void Asteroid::Collide(Pawn* pawn) {
	if (pawn->type.compare("Asteroid") == 0) {
		speedx = -speedx;
		speedy = -speedy;
		x += speedx * GameManager::getInstance()->deltaTime;
		y += speedy * GameManager::getInstance()->deltaTime;
	} else {
		Destroy();
	}
}

void Asteroid::Draw() {
	Pawn::Draw();
	sprite.setPosition(x + radius, y + radius);
	GameManager::getInstance()->window.draw(sprite);
}