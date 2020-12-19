#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Pawn.h"
#include "Particle.h"

class Bullet : public Particle {
public:
	Bullet(float x, float y, float speedx, float speedy);
	void Update() override;
};