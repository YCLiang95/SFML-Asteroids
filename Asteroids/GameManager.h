#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "ParticleSystem.h"
#include "PawnSystem.h"
#include "Pawn.h"
#include "Ship.h"

class GameManager {
    GameManager() {
        width = 800;
        height = 600;
        window.create(sf::VideoMode(width, height), "Asteroids");


        timeScale = 1.0f;
        lastTime = clock();
        deltaTime = 0;


        ps = ParticleSystem::getInstance();
        pawnSystem = PawnSystem::getInstance();

        Ship* ship = new Ship();
        pawnSystem->Add(ship);

        isRunning = true;
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

    ParticleSystem* ps;
    PawnSystem* pawnSystem;

    ~GameManager() {
    }

private:
    static GameManager* instance;
};