#pragma once

#include <SFML/Graphics.hpp>

class Ball {
private:
    sf::CircleShape& m_shape;
    unsigned int m_xWindowMax;
    unsigned int m_yWindowMax;
    float m_xMovement;
    float m_yMovement;
    int m_xDirection;
    int m_yDirection;
public:
    Ball(sf::CircleShape& shape, sf::RenderWindow& window);

    void Move();
};