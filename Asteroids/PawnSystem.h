#pragma once
#include <vector>
#include "Pawn.h"

using std::vector;

class PawnSystem {
public:
	static PawnSystem* getInstance();

	PawnSystem();

	void Draw();
	void Update();
	void Clear();

	void Add(Pawn* pawn);

	vector<Pawn*> pawns;

	vector<vector<vector<Pawn*>>> bucket;

private:
	static PawnSystem* instance;
};
