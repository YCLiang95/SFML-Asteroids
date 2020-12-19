#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "ParticleSystem.h"
#include "PawnSystem.h"
#include "Pawn.h"
#include "Ship.h"
#include "Asteroid.h"

const int STATE_MAIN_MENU = 0;
const int STATE_IS_RUNNING = 1;
const int STATE_GAMEOVER = 2;
const int STATE_WIN = 3;

class GameManager {
    GameManager() {
        width = 800;
        height = 600;
        window.create(sf::VideoMode(width, height), "Asteroids");


        timeScale = 1.0f;
        lastTime = clock();
        deltaTime = 0;
        life = 3;
        level = 0;
        state = STATE_MAIN_MENU;

        ps = ParticleSystem::getInstance();
        pawnSystem = PawnSystem::getInstance();

        Ship* ship = new Ship();
        pawnSystem->Add(ship);

        isRunning = false;

        LoadFont();
    }



public:
    int height, width;
    sf::RenderWindow window;
    bool gameOver = false;

    static GameManager* getInstance();
    void Draw();
    void Update();

    clock_t lastTime;
    float deltaTime;
    float timeScale;
    bool isRunning;

    int life = 3;
    int level = 0;
    int asteroidsCount = 0;

    int state;

    sf::Font font;
    sf::Text lifeCountText;
    sf::Text asteroidsCountText;
    sf::Text winningText;
    sf::Text gameOverText;
    sf::Text mainMenuText;

    ParticleSystem* ps;
    PawnSystem* pawnSystem;

    //~GameManager() {
    //}

    void LoadFont();
    void GenerateLevel();


private:
    static GameManager* instance;
};