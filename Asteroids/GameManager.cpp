#include "GameManager.h"
#include <iostream>

GameManager* GameManager::instance;

void GameManager::Update() {

    if (state == STATE_MAIN_MENU) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            level = 0;
            GenerateLevel();
            state = STATE_IS_RUNNING;
            isRunning = true;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close();
            gameOver = true;
        }
    } else if (state == STATE_GAMEOVER){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            state = STATE_MAIN_MENU;
    }
    else if (state == STATE_WIN) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            level += 1;
            GenerateLevel();
            state = STATE_IS_RUNNING;
            isRunning = true;
        }
    } else {
        if (life <= 0) {
            pawnSystem->Clear();
            isRunning = false;
            state = STATE_GAMEOVER;
        } else if (asteroidsCount <= 0) {
            pawnSystem->Clear();
            state = STATE_WIN;
            isRunning = false;
        }
    }



    deltaTime = (float)(clock() - lastTime) / CLOCKS_PER_SEC * timeScale;
    lastTime = clock();

    ps->Update();
    pawnSystem->Update();

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

    if (state == STATE_MAIN_MENU) {
        window.draw(mainMenuText);
    } else if (state == STATE_IS_RUNNING) {
        lifeCountText.setString("Life: " + std::to_string(life));
        window.draw(lifeCountText);
        asteroidsCountText.setString(std::to_string(asteroidsCount) + " Asteroids remain");
        window.draw(asteroidsCountText);
        ps->Draw();
        pawnSystem->Draw();
    } else if (state == STATE_GAMEOVER){
        window.draw(gameOverText);
    } else {
        window.draw(winningText);
    }

    window.display();
}

GameManager* GameManager::getInstance(){
    if (!instance)
        instance = new GameManager;
    return instance;
}


void GameManager::LoadFont() {
    if (!font.loadFromFile("arial.ttf")) {
        std::cout << "Failed to load Font" << std::endl;
        return;
    }


    lifeCountText.setFont(font);
    lifeCountText.setCharacterSize(24);
    lifeCountText.setFillColor(sf::Color::White);
    lifeCountText.setPosition(width - 100, 0);


    asteroidsCountText.setFont(font);
    asteroidsCountText.setCharacterSize(24);
    asteroidsCountText.setFillColor(sf::Color::White);
    asteroidsCountText.setPosition(10, 0);


    mainMenuText.setFont(font);
    mainMenuText.setCharacterSize(24);
    mainMenuText.setFillColor(sf::Color::White);
    mainMenuText.setPosition(300.0f, 500.0f);
    mainMenuText.setString("Press Enter to Start");

    gameOverText.setFont(font);
    gameOverText.setCharacterSize(24);
    gameOverText.setFillColor(sf::Color::White);
    gameOverText.setPosition(400.0f, 300.0f);
    gameOverText.setString("Game Over! Press Enter to Continue");

    winningText.setFont(font);
    winningText.setCharacterSize(24);
    winningText.setFillColor(sf::Color::White);
    winningText.setPosition(400.0f, 300.0f);
    winningText.setString("You Won! Press Enter to Next Level");
}

void GameManager::GenerateLevel() {
    Ship* ship = new Ship();
    pawnSystem->Add(ship);
    life = 3;
    int count = (level + 2) * (rand() % 3 + 1) + rand() % 3 + (level * (rand() % 3));
    asteroidsCount = count;
    for (int i = 0; i < count; i++) {
        Asteroid* asteroid = new Asteroid(rand() % 3 + 1);
        pawnSystem->Add(asteroid);
    }
}