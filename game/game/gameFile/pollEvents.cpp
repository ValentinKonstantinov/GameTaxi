#include "declaration.hpp"

void pollEvents(sf::RenderWindow &window, sf ::Vector2f &mousePosition, sf ::Vector2f &mouseClikPosition)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::MouseMoved:
            onMouseMove(event.mouseMove, mousePosition);
            break;
        case sf::Event::MouseButtonPressed:
            onMouseClick(event.mouseButton, mouseClikPosition);
            break;
        default:
            break;
        }
    }
}