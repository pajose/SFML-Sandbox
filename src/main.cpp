#include <SFML/Graphics.hpp>
#include <iostream>

#include "EventHandler.h"

int main()
{
    // VideoMode is in pixels
    auto window = sf::RenderWindow({1080u, 800u}, "My Game"); // This implicitly creates a VideoMode object using {1920u,1080u} as an initializer list
    window.setFramerateLimit(60);

    EventHandler eventHandler(window);

    while (window.isOpen())
    {
        eventHandler.HandleEvents();

        sf::CircleShape shape(50.f);
        shape.setFillColor(sf::Color(100,250,50));

        window.clear();
        window.draw(shape);
        window.display();
    }
}
