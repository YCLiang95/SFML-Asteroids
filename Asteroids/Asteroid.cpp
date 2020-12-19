#include "Asteroid.h"

Asteroid::Asteroid(int size) : Pawn() {
	hp = size;
	if (size == 3)
		shape.setRadius(15);
	else if (size == 2)
		shape.setRadius(10);
	else
		shape.setRadius(5);
}