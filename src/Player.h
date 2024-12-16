#pragma once

#include <string>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "Global.h"
#include "nlohmann/json.hpp"

class Player {
private:
    struct SpriteSheet {
        int width;
        int height;
        int x;
        int y;
    };

    sf::Sprite m_sprite;
    sf::Texture m_texture;
    std::unordered_map<int,SpriteSheet> m_spriteSheetData;
    int m_currSprite = 0;
    float m_movementSpeed = 10.0;
public:
    Player(const std::string& textureName);
    sf::Sprite& getSprite();
    void loadSpriteSheet(const std::string& spriteName);
    void updateSprite();
    void moveUp();
    void moveDown();
    void moveRight();
    void moveLeft();
};