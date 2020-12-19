#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Pawn.h"

class Ship : public Pawn{
public:
	void Draw() override;
	void Update() override;

	sf::Sprite sprite;

	float angle;

	float fireTime = 1.0f;
	float fireTimer = 1.0f;

	float speed = 50.0f;
};