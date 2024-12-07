#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class EventHandler {
private:
    sf::RenderWindow& m_window;
public:
    EventHandler(sf::RenderWindow& window);
    ~EventHandler();

    void HandleEvents();
};