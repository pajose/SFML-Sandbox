#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Global.h"
#include "nlohmann/json.hpp"

class Player {    
public:
    enum Movement {
        IDLE,
        UP,
        DOWN,
        RIGHT,
        LEFT
    };

    Player(const std::string& textureName);
    ~Player();
    void init();
    sf::Sprite& getSprite();
    void loadSpriteSheetData();
    void update();
    void updateSprite();
    void moveUp();
    void moveDown();
    void moveRight();
    void moveLeft();
    void setMovement(const Movement& move);
    Movement getMovement();

private:
    struct SpriteSheet {
        int width;
        int height;
        int x;
        int y;
    };

    sf::Sprite m_sprite;
    sf::Texture m_texture;
    std::string m_currTexture;
    std::string m_textureName = "mainChar";
    std::unordered_map<std::string, sf::Texture*> m_textures;
    std::unordered_map<std::string, std::unordered_map<int,SpriteSheet>> m_spriteSheetData;
    int m_currSprite = 0;
    float m_movementSpeed = 10.0;
    Movement m_move = IDLE;
    Movement m_prevAnimation = IDLE;
};