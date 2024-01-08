#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <array>
#include <fstream>
using namespace std;
#include "declaration.hpp"
void redrawFrame(sf::RenderWindow &window, car &car, passenger &passenger, destination &destination, obstruction arreyObstruction[])
{
    window.clear(sf::Color(255, 255, 255));
    window.draw(car.sprite);
    window.draw(destination.sprite);
    for (int i = 0; i < 11; ++i)
    {
        window.draw(arreyObstruction[i].sprite);
    };

    if (car.withAPassenger == 0)
    {
        window.draw(passenger.sprite);
    };
    window.display();
    //  window.draw(arrow.ellipseInternal);
}