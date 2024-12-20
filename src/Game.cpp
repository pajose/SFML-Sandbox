#include "Game.h"

Game::Game() 
    : circle(50.f), star(100.f, 5), window({1080u, 800u}, "My Game"), eventHandler(window, player),
    player("idle"), ball(circle, window) {
    
}

Game::~Game() {}

void Game::init() {
    // VideoMode is in pixels
    // auto window = sf::RenderWindow({1080u, 800u}, "My Game"); // This implicitly creates a VideoMode object using {1920u,1080u} as an initializer list
    window.setFramerateLimit(20);

    // Load textures
    // load a 32x32 rectangle that starts at (10, 10)
    groundRockyTexture.loadFromFile(Global::texturesPath+"desert_outback_ground_mud_rocky__01_xikxcgl_2k\\Desert_Outback_Ground_Mud_Rocky__01_xikxcgl_2K_AO.jpg", sf::IntRect(100, 100, 1000, 1000));
    mudRockyTexture.loadFromFile(Global::texturesPath+"desert_outback_ground_mud_rocky__01_xikxcgl_2k\\Desert_Outback_Ground_Mud_Rocky__01_xikxcgl_2K_BaseColor.jpg", sf::IntRect(100, 100, 1000, 1000));

    circle.setPosition(10.f, 50.f);
    circle.setTexture(&groundRockyTexture);

    // StarShape star(100.f, 5); // Star with radius 100 and 5 points
    star.setTexture(&mudRockyTexture);
    star.setPosition(300.f, 200.f); // Move it to the desired position

    player.init();

}

void Game::run() {
    while (window.isOpen())
    {
        eventHandler.HandleEvents();

        // ball.Move();

        window.clear();
        // window.draw(circle);
        window.draw(player.getSprite());
        window.display();
        player.update();
    }
}