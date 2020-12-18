#include "main.h"

int main(){
    GameManager* gm = gm->getInstance();

    while (!gm->gameOver){
        gm->Update();
    }

    delete gm;
    return 0;
}

