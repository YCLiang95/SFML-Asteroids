#pragma once
#include <vector>
#include "Pawn.h"

using std::vector;

class PawnSystem {
public:
	static PawnSystem* getInstance();

	void Draw();
	void Update();

	void Add(Pawn* pawn);

	vector<Pawn*> pawns;

private:
	static PawnSystem* instance;
};
