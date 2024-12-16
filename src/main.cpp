#include <SFML/Graphics.hpp>
#include <iostream>
#include <filesystem>
#include <cmath>

#include "Game.h"

using namespace Global;

int main()
{
    // std::filesystem::path cwd = std::filesystem::current_path();
    // std::cout << cwd.string() << std::endl;
    // sf::Texture texture;
    // texture.loadFromFile(Global::texturesPath+"desert_outback_ground_mud_rocky__01_xikxcgl_2k\\Desert_Outback_Ground_Mud_Rocky__01_xikxcgl_2K_AO.jpg", sf::IntRect(100, 100, 1000, 1000));

    Game game;
    game.Init();
    game.Run();
}
