#include <SFML/Graphics.hpp>
#include <iostream>
#include <filesystem>
#include <cmath>

#include "Game.h"

using namespace Global;

int main()
{
    Game game;
    game.Init();
    game.Run();
}
