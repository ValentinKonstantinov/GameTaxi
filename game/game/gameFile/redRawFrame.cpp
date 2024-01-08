#include "declaration.hpp"

void redrawFrame(sf::RenderWindow &window, car &car, passenger passenger[], destination &destination, obstruction arreyObstruction[])
{
    window.clear(sf::Color(255, 255, 255));

    window.draw(destination.sprite);
    for (int i = 0; i < 11; ++i)
    {
        window.draw(arreyObstruction[i].sprite);
    };
    for (int i = 0; i < 30; ++i)
    {
        if (passenger[i].activation == 1)
        {
            window.draw(passenger[i].sprite);
        }
    };
    window.draw(car.sprite);
    window.display();
    //  window.draw(arrow.ellipseInternal);
}