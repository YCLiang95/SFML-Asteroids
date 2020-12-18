#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "ParticleSystem.h"

class GameManager {
    GameManager() {
        width = 800;
        height = 600;
        window.create(sf::VideoMode(width, height), "Asteroids");


        timeScale = 1.0f;
        lastTime = clock();
        deltaTime = 0;


        ps = ParticleSystem::getInstance();

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

    ~GameManager() {
    }

private:
    static GameManager* instance;
};