#include "Pawn.h"
#include "GameManager.h"
#include <math.h>
#include <iostream>
#include "Particle.h"
#include "ParticleSystem.h"

Pawn::Pawn() {
	x = 400;
	y = 300;
	speedx = 0.0f;
	speedy = 0.0f;

	hp = 1;
	isDead = false;

	radius = 10.0f;
	shape.setRadius(radius);
	shape.setFillColor(sf::Color(255,255,255));
}

void Pawn::Update() {

	if (!GameManager::getInstance()->isRunning)
		return;

	float  dx = x + speedx * GameManager::getInstance()->deltaTime;
	float dy = y + speedy * GameManager::getInstance()->deltaTime;

	x = dx;
	y = dy;
}

void Pawn::Draw() {
	shape.setPosition(x, y);
	GameManager::getInstance()->window.draw(shape);
}

void Pawn::Collide(Pawn* pawn) {
	std::cout << "Colldie!" << std::endl;
	Destroy();
}
