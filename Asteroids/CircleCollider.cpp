#include "CircleCollider.h"
#include "GameManager.h"
#include <math.h>
#include <iostream>
#include "Particle.h"
#include "ParticleSystem.h"

CircleCollider::CircleCollider() {
	x = 400;
	y = 300;
	speedx = 400.0f;
	speedy = 300.0f;
	isLauched = false;
	radius = 10.0f;
	shape.setRadius(radius);
	shape.setFillColor(sf::Color(255,255,255));
}

void CircleCollider::Update() {

	if (!GameManager::getInstance()->isRunning)
		return;

	float  dx = x + speedx * GameManager::getInstance()->deltaTime;
	float dy = y + speedy * GameManager::getInstance()->deltaTime;

	x = dx;
	y = dy;
}

void CircleCollider::Draw() {
	shape.setPosition(x, y);
	GameManager::getInstance()->window.draw(shape);
}
