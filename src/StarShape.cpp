#include "StarShape.h"

// Constructor to initialize the star properties
StarShape::StarShape(float radius, unsigned int points)
    : m_radius(radius), m_points(points) {
    update(); // Recalculate the geometry when created
}

// Override to specify the number of points in the shape
std::size_t StarShape::getPointCount() const {
    return m_points * 2; // Each "arm" of the star has two points
}

// Override to specify the position of each point
sf::Vector2f StarShape::getPoint(std::size_t index) const {
    float angle = static_cast<float>(index) * 3.14159265f / m_points;
    float radius = (index % 2 == 0) ? m_radius : m_radius / 2; // Alternating between outer and inner radius
    return sf::Vector2f(
        std::cos(angle) * radius + m_radius, // Offset by radius for positioning
        std::sin(angle) * radius + m_radius
    );
}