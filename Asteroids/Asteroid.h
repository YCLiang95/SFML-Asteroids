#pragma once
#include "Pawn.h"
#include "GameManager.h"

class Asteroid : public Pawn{
public:
	Asteroid(int size);

	void Update() override;
	void Draw() override;
	void Destroy() override;

	void Collide(Pawn* pawn) override;

	sf::SoundBuffer bufferHitSound;
	sf::Sound hitSound;

	sf::Texture texture;
	sf::Sprite sprite;
};