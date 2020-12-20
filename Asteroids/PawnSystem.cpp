#include "PawnSystem.h"
#include "GameManager.h"

PawnSystem* PawnSystem::instance;

void PawnSystem::Draw() {
	for (int i = 0; i < pawns.size(); i++)
		pawns[i]->Draw();
}

void PawnSystem::Update() {

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 6; j++)
			bucket[i][j].clear();

	for (int i = 0; i < pawns.size(); i++) {
		pawns[i]->Update();
		//adds to the bucket
		if (!pawns[i]->isDead) {
			if (pawns[i]->x > 0 && pawns[i]->y > 0 && (pawns[i]->x / 100) < 8 && (pawns[i]->y / 100) < 6) {
				//std::cout << "Pawn :" << (int)pawns[i]->x << "," << (int)pawns[i]->y << "added to bucket : " << (int)(pawns[i]->x / 100) << "," << (int)(pawns[i]->y / 100) << std::endl;
				bucket[(int)(pawns[i]->x / 100)][(int)(pawns[i]->y / 100)].push_back(pawns[i]);
			}

			if ((int)(pawns[i]->x / 100) + pawns[i]->radius > 100 && (int)(pawns[i]->x / 100) + 1 < 8)
				bucket[(int)(pawns[i]->x / 100) + 1][(int)(pawns[i]->y / 100)].push_back(pawns[i]);

			if ((int)(pawns[i]->y / 100) + pawns[i]->radius > 100 && (int)(pawns[i]->y / 100) + 1 < 6)
				bucket[(int)(pawns[i]->x / 100)][(int)(pawns[i]->y / 100) + 1].push_back(pawns[i]);

			if ((int)(pawns[i]->y / 100) + pawns[i]->radius > 100 && (int)(pawns[i]->y / 100) + 1 < 6 && (int)(pawns[i]->x / 100) + pawns[i]->radius > 100 && (int)(pawns[i]->x / 100) + 1 < 8)
				bucket[(int)(pawns[i]->x / 100) + 1][(int)(pawns[i]->y / 100) + 1].push_back(pawns[i]);
		}
	}

	//Check for collisio
	for (int i = 0; i < 8; i ++)
		for (int j = 0; j < 6; j++)
			for (int k = 0; k < bucket[i][j].size(); k ++)
				for (int l = 0; l < bucket[i][j].size(); l ++)
					if (k != l && (bucket[i][j][k]->radius + bucket[i][j][l]->radius > sqrt(pow(bucket[i][j][k]->x - bucket[i][j][l]-> x, 2) + pow(bucket[i][j][k]->y - bucket[i][j][l]->y, 2)))){
						bucket[i][j][k]->Collide(bucket[i][j][l]);
						bucket[i][j][l]->Collide(bucket[i][j][k]);
		}


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
		instance = new PawnSystem();
	return instance;
}

void PawnSystem::Clear() {
	for (int i = 0; i < pawns.size(); i++)
		pawns[i]->isDead = true;
}

//constructor
PawnSystem::PawnSystem() {
	bucket.resize(8, vector<vector<Pawn*>>(6, vector<Pawn*>()));
}