#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"

class EventHandler {
private:
    sf::RenderWindow& m_window;
    Player& m_player;
public:
    EventHandler(sf::RenderWindow& window, Player& player);
    ~EventHandler();

    void HandleEvents();
};