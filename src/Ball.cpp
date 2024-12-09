#include "Ball.h"

Ball::Ball(sf::CircleShape& shape, sf::RenderWindow& window) : m_shape(shape){
    m_xDirection = 1;
    m_yDirection = 1;
    m_xMovement = 5.f;
    m_yMovement = 5.f;
    m_xWindowMax = window.getSize().x;
    m_yWindowMax = window.getSize().y;
}

void Ball::Move() {
    sf::Vector2f shapePos = m_shape.getPosition();
    // Y coordinate
    if ((shapePos.y + m_shape.getRadius()*2 > m_yWindowMax) || (shapePos.y < 0)) {
        m_yDirection *= -1;
    }
    // X coordinate
    if ((shapePos.x + m_shape.getRadius()*2 > m_xWindowMax) || (shapePos.x < 0)) {
        m_xDirection *= -1;
    }

    m_shape.move(m_xMovement*m_xDirection, m_yMovement*m_yDirection);
}