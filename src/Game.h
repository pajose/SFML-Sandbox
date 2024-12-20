#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <filesystem>
#include <cmath>

#include "EventHandler.h"
#include "Ball.h"
#include "StarShape.h"
#include "Player.h"
#include "Global.h"

class Game {
private:
    sf::RenderWindow window;
    EventHandler eventHandler;
    sf::Texture groundRockyTexture;
    sf::Texture mudRockyTexture;
    sf::CircleShape circle;
    StarShape star;
    Player player;
    Ball ball;

public:
    Game();
    ~Game();
    void init();
    void run();
};