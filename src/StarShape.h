#pragma once
#include <SFML/Graphics.hpp>


class StarShape : public sf::Shape {
public:
    // Constructor to initialize the star properties
    StarShape(float radius, unsigned int points);

    // Override to specify the number of points in the shape
    std::size_t getPointCount() const override;

    // Override to specify the position of each point
    sf::Vector2f getPoint(std::size_t index) const override;

private:
    float m_radius;          // Outer radius of the star
    unsigned int m_points;   // Number of points in the star
};