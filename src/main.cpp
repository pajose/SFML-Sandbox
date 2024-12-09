#include <SFML/Graphics.hpp>
#include <iostream>
#include <filesystem>

#include "EventHandler.h"
#include "Ball.h"

std::string texturesPath = "..\\..\\..\\assets\\textures\\";

int main()
{
    // VideoMode is in pixels
    auto window = sf::RenderWindow({1080u, 800u}, "My Game"); // This implicitly creates a VideoMode object using {1920u,1080u} as an initializer list
    window.setFramerateLimit(30);

    EventHandler eventHandler(window);

    sf::Texture texture;
    // load a 32x32 rectangle that starts at (10, 10)
    if (!texture.loadFromFile(texturesPath+"desert_outback_ground_mud_rocky__01_xikxcgl_2k\\Desert_Outback_Ground_Mud_Rocky__01_xikxcgl_2K_AO.jpg", sf::IntRect(100, 100, 1000, 1000)))
    {
        // error...
        std::cout << "Unable to load texture" << std::endl;
        return -1;
    }

    sf::CircleShape shape(50.f);
    shape.setPosition(10.f, 50.f);
    shape.setTexture(&texture);
    sf::Sprite sprite;
    sprite.setTexture(texture);

    Ball ball(shape, window);

    while (window.isOpen())
    {
        eventHandler.HandleEvents();

        ball.Move();

        window.clear();
        window.draw(shape);
        window.display();
    }
}
