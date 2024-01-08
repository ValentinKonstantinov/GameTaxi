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
void update(const sf::Vector2f &mousePosition, sf::Vector2f &mouseClikPosition, car &car, passenger &passenger, destination &destination, obstruction arreyObstruction[], sf::Clock &clock)
{
    passenger.sprite.setPosition(mouseClikPosition);
    passenger.position = mouseClikPosition;
    sf::Vector2f delta;
    if (car.withAPassenger == 0)
    {
        delta = passenger.position - car.position;
    }
    else
    {
        delta = destination.position - car.position;
    }
    //car.rotation = atan2(delta.y, delta.x);

    //distance = delta.x * delta.x + delta.y * delta.y;
    //distance = sqrt(distance);

    updatecar(car, clock, delta, arreyObstruction);
}