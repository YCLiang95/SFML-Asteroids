#include "PawnSystem.h"

PawnSystem* PawnSystem::instance;

void PawnSystem::Draw() {
	for (int i = 0; i < pawns.size(); i++)
		pawns[i]->Draw();
}

void PawnSystem::Update() {
	for (int i = 0; i < pawns.size(); i++)
		pawns[i]->Update();

	//Check for collision

	for (vector<Pawn*>::iterator it = pawns.begin(); it != pawns.end();) {
		//Removed dead particals
		if ((**it).isDead)
			it = pawns.erase(it);
		else
			++it;
	}
}

void PawnSystem::Add(Pawn* pawn) {
	pawns.push_back(pawn);
}

PawnSystem* PawnSystem::getInstance() {
	if (!instance)
		instance = new PawnSystem;
	return instance;
}

void PawnSystem::Clear() {
	for (int i = 0; i < pawns.size(); i++)
		pawns[i]->isDead = true;
}