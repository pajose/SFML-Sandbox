#include "EventHandler.h"

EventHandler::EventHandler(sf::RenderWindow& window, Player& player) 
    : m_window(window), m_player(player)
    {}

EventHandler::~EventHandler() {}

void EventHandler::HandleEvents() {

    for (auto event = sf::Event(); m_window.pollEvent(event);)
        {
            switch (event.type) {
                case sf::Event::Closed:
                    m_window.close();
                    break;
                case sf::Event::TextEntered:
                    break;
                case sf::Event::KeyPressed:
                    switch (event.key.scancode) {
                        case sf::Keyboard::Scan::W:
                            m_player.setMovement(Player::UP);
                            break;
                        case sf::Keyboard::Scan::A:
                            m_player.setMovement(Player::LEFT);
                            break;
                        case sf::Keyboard::Scan::S:
                            m_player.setMovement(Player::DOWN);
                            break;
                        case sf::Keyboard::Scan::D:
                            m_player.setMovement(Player::RIGHT);
                            break;
                    }
                    break;
                case sf::Event::KeyReleased:
                    // Need to check that character released is what is the current movement, in case a different key was pressed
                    // while first key was still pressed
                    Player::Movement currMove = m_player.getMovement();
                    if (m_player.getMovement() == event.key.scancode) {
                        m_player.setMovement(Player::IDLE);
                    }
                    switch (event.key.scancode) {
                        case sf::Keyboard::Scan::W:
                            if (m_player.getMovement() == Player::UP) {
                                m_player.setMovement(Player::IDLE);
                            }
                            break;
                        case sf::Keyboard::Scan::A:
                            if (m_player.getMovement() == Player::LEFT) {
                                m_player.setMovement(Player::IDLE);
                            }
                            break;
                        case sf::Keyboard::Scan::S:
                            if (m_player.getMovement() == Player::DOWN) {
                                m_player.setMovement(Player::IDLE);
                            }
                            break;
                        case sf::Keyboard::Scan::D:
                            if (m_player.getMovement() == Player::RIGHT) {
                                m_player.setMovement(Player::IDLE);
                            }
                            break;
                    }
                    break;
            }
        }
}