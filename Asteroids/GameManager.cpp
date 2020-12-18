#include "GameManager.h"
#include <iostream>

GameManager* GameManager::instance;

void GameManager::Update() {

    if (!isRunning) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            isRunning = true;
        }
    }

    deltaTime = (float)(clock() - lastTime) / CLOCKS_PER_SEC * timeScale;
    lastTime = clock();

    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed) {
            window.close();
            gameOver = true;
        }
    }



    Draw();
}

void GameManager::Draw() {
    window.clear();


    window.display();
}

GameManager* GameManager::getInstance(){
    if (!instance)
        instance = new GameManager;
    return instance;
}
