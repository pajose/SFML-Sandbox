#include "Player.h"

using json = nlohmann::json;

Player::Player(const std::string& spriteName) {    
    // loadSpriteSheet(spriteName);

    // m_currTexture = m_idleTexture;
    // m_sprite.setTexture(*m_currTexture);
    // m_sprite.setTextureRect({0,0,58,58});
    // m_sprite.setPosition(300.f, 200.f);
    // m_sprite.setScale({1.5f,1.5f});
}

Player::~Player() {
    for (auto& texture : m_textures) {
        delete texture.second;
    }
}

void Player::init() {
    std::vector textures = {"idle", "run"};
    for (const auto& texture: textures) {
        m_textures[texture] = new sf::Texture;
        m_textures[texture]->loadFromFile(Global::spritesPath+texture+".png");
        loadSpriteSheetData(texture);
    }

    m_currTexture = "idle";
    m_sprite.setTexture(*m_textures[m_currTexture]);
    m_sprite.setTextureRect({0,0,58,58});
    m_sprite.setPosition(300.f, 200.f);
    m_sprite.setScale({1.25f,1.25f});
}

sf::Sprite& Player::getSprite() {
    return m_sprite;
}

void Player::loadSpriteSheetData(const std::string& spriteName) {
    // m_currTexture.loadFromFile(Global::spritesPath+spriteName+".png");
    
    std::ifstream f(Global::spritesPath+spriteName+".json");
    json sprite_sheet = json::parse(f);
    for (const auto& sprite: sprite_sheet["sprites"]) {
        std::string fileName = sprite["fileName"];
        fileName = fileName.substr(0,fileName.find('.'));
        int spriteNum = std::stoi(fileName);
        int width = sprite["width"];
        int height = sprite["height"];
        int x = sprite["x"];
        int y = sprite["y"];
        m_spriteSheetData[spriteName][spriteNum-1] = {width,height,x,y};
    }
}

void Player::update() {
    updateSprite();

    if (m_move != m_prevAnimation) {
        if (m_move == Movement::IDLE) {
            m_currTexture = "idle";
        }
        else if (m_move != Movement::IDLE) {
            m_currTexture = "run";
        }
        m_sprite.setTexture(*m_textures[m_currTexture]);
    }
    m_prevAnimation = m_move;
    
    switch(m_move) {
        case UP:
            moveUp();
            break;
        case DOWN:
            moveDown();
            break;
        case RIGHT:
            moveRight();
            break;
        case LEFT:
            moveLeft();
            break;
        default:
            break;
    }
}

void Player::updateSprite() {
    m_currSprite = ((m_currSprite+1) % m_spriteSheetData[m_currTexture].size());
    int width = m_spriteSheetData[m_currTexture][m_currSprite].width;
    int height = m_spriteSheetData[m_currTexture][m_currSprite].height;
    int x = m_spriteSheetData[m_currTexture][m_currSprite].x;
    int y = m_spriteSheetData[m_currTexture][m_currSprite].y;
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

void Player::setMovement(const Player::Movement& move) {
    m_move = move;
}

Player::Movement Player::getMovement() {
    return m_move;
}