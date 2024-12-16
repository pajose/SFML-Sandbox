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
                            m_player.moveUp();
                            break;
                        case sf::Keyboard::Scan::A:
                            m_player.moveLeft();
                            break;
                        case sf::Keyboard::Scan::S:
                            m_player.moveDown();
                            break;
                        case sf::Keyboard::Scan::D:
                            m_player.moveRight();
                            break;
                    }
            }
        }
}