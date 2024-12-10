#include <SFML/Graphics.hpp>
#include <iostream>
#include <filesystem>
#include <cmath>

#include "EventHandler.h"
#include "Ball.h"
#include "StarShape.h"

std::string texturesPath = "..\\..\\..\\assets\\textures\\";

int main()
{
    // VideoMode is in pixels
    auto window = sf::RenderWindow({1080u, 800u}, "My Game"); // This implicitly creates a VideoMode object using {1920u,1080u} as an initializer list
    window.setFramerateLimit(60);

    EventHandler eventHandler(window);

    sf::Texture texture1;
    // load a 32x32 rectangle that starts at (10, 10)
    if (!texture1.loadFromFile(texturesPath+"desert_outback_ground_mud_rocky__01_xikxcgl_2k\\Desert_Outback_Ground_Mud_Rocky__01_xikxcgl_2K_AO.jpg", sf::IntRect(100, 100, 1000, 1000)))
    {
        // error...
        std::cout << "Unable to load texture" << std::endl;
        return -1;
    }
    sf::Texture texture2;
    texture2.loadFromFile(texturesPath+"desert_outback_ground_mud_rocky__01_xikxcgl_2k\\Desert_Outback_Ground_Mud_Rocky__01_xikxcgl_2K_BaseColor.jpg", sf::IntRect(100, 100, 1000, 1000));

    sf::Texture texture3;
    texture3.loadFromFile("..\\..\\..\\assets\\Pirate Bomb\\Sprites\\1-Player-Bomb Guy\\1-Idle\\1.png");

    sf::CircleShape circle(50.f);
    circle.setPosition(10.f, 50.f);
    circle.setTexture(&texture1);
    Ball ball(circle, window);

    StarShape star(100.f, 5); // Star with radius 100 and 5 points
    star.setTexture(&texture2);
    star.setPosition(300.f, 200.f); // Move it to the desired position

    sf::Sprite sprite;
    sprite.setTexture(texture3);

    while (window.isOpen())
    {
        eventHandler.HandleEvents();

        ball.Move();

        window.clear();
        window.draw(circle);
        window.draw(star);
        window.draw(sprite);
        window.display();
    }
}
