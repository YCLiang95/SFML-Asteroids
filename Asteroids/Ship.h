#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Pawn.h"

class Ship : public Pawn{
public:
	void Draw() override;
	void Update() override;

	void Collide(Pawn* pawn) override;
	void Destroy() override;

	Ship();

	sf::Sprite sprite;

	float angle;

	float fireTime = 1.0f;
	float fireTimer = 1.0f;

	float speed = 50.0f;

	float respawnInvi = 2.0f;
	float respawnTimer = 0.0f;
};