#include "Player.h"

using json = nlohmann::json;

Player::Player(const std::string& spriteName) {
    
    loadSpriteSheet(spriteName);

    m_sprite.setTexture(m_texture);
    m_sprite.setTextureRect({0,0,58,58});
    m_sprite.setPosition(300.f, 200.f);
}

sf::Sprite& Player::getSprite() {
    return m_sprite;
}

void Player::loadSpriteSheet(const std::string& spriteName) {
    m_texture.loadFromFile(Global::spritesPath+spriteName+".png");
    
    std::ifstream f(Global::spritesPath+spriteName+".json");
    json sprite_sheet = json::parse(f);
    for (const auto& sprite: sprite_sheet["sprites"]) {
        std::string spriteName = sprite["fileName"];
        spriteName = spriteName.substr(0,spriteName.find('.'));
        int spriteNum = std::stoi(spriteName);
        int width = sprite["width"];
        int height = sprite["height"];
        int x = sprite["x"];
        int y = sprite["y"];
        m_spriteSheetData[spriteNum-1] = {width,height,x,y};
    }
}

void Player::updateSprite() {
    m_currSprite = ((m_currSprite+1) % m_spriteSheetData.size());
    int width = m_spriteSheetData[m_currSprite].width;
    int height = m_spriteSheetData[m_currSprite].height;
    int x = m_spriteSheetData[m_currSprite].x;
    int y = m_spriteSheetData[m_currSprite].y;
    m_sprite.setTextureRect({x,y,width,height});
}

void Player::moveUp() {
    m_sprite.move(0,-m_movementSpeed);
}
void Player::moveDown() {
    m_sprite.move(0,m_movementSpeed);
}
void Player::moveRight() {
    m_sprite.move(m_movementSpeed,0);
}
void Player::moveLeft() {
    m_sprite.move(-m_movementSpeed,0);
}