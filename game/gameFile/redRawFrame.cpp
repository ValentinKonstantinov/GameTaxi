#include "declaration.hpp"

void redrawFrame(car &algoCar, car &userCar, car &userCar2, sf::RenderWindow &window, car &car, passenger passenger[], destination &destination, levelMap &levelMap, oilStruct &oil)
{
    window.clear(sf::Color(255, 255, 255));
    window.draw(car.menuText);
    window.draw(algoCar.menuText);
    window.draw(userCar.menuText);
    if (userCar2.activation)
    {
        window.draw(userCar2.menuText);
    };

    window.draw(levelMap.sprite);
    window.draw(destination.sprite);
    for (int i = 0; i < 30; ++i)
    {
        if (passenger[i].activation == 1)
        {
            window.draw(passenger[i].sprite);
        }
    };
    if ((oil.activation == 1) || (oil.activation == 3))
    {
        window.draw(oil.sprite);
    };
    window.draw(car.sprite);
    window.draw(algoCar.sprite);
    window.draw(userCar.sprite);
    if (userCar2.activation)
    {
        window.draw(userCar2.sprite);
    };

    window.display();
    //  window.draw(arrow.ellipseInternal);
}