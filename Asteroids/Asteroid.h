#pragma once
#include "Pawn.h"
#include "GameManager.h"

class Asteroid : public Pawn{
public:
	Asteroid(int size);

	void Update() override;
};