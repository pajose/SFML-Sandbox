#include "EventHandler.h"

EventHandler::EventHandler(sf::RenderWindow& window) : m_window(window) {}

EventHandler::~EventHandler() {}

void EventHandler::HandleEvents() {

    for (auto event = sf::Event(); m_window.pollEvent(event);)
        {
            switch (event.type) {
                case sf::Event::Closed:
                    m_window.close();
                    break;
                case sf::Event::TextEntered:
                    if (event.text.unicode < 128) {
                        std::cout << "Character entered: " << static_cast<char>(event.text.unicode) << std::endl;
                    }
                    break;
            }
        }
}