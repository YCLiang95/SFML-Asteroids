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
	sf::Texture texture;

	float angle;

	float fireTime = 0.25f;
	float fireTimer = 0.25f;

	float speed = 50.0f;

	float respawnInvi = 2.0f;
	float respawnTimer = 0.0f;

	sf::SoundBuffer bufferLoseSound;
	sf::Sound loseSound;
};