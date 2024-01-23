#include "declaration.hpp"

void goCarToTheLeft(car &car, float T)
{
    car.position.x = car.position.x - T;
    car.sprite.setPosition(car.position);
    car.sprite.setTextureRect(sf::IntRect(0, 0, 40, 40));
}

void goCarToTheRight(car &car, float T)
{
    car.position.x = car.position.x + T;
    car.sprite.setPosition(car.position);
    car.sprite.setTextureRect(sf::IntRect(120, 0, 40, 40));
}

void goCarToTheUp(car &car, float T)
{
    car.position.y = car.position.y - T;
    car.sprite.setPosition(car.position);
    car.sprite.setTextureRect(sf::IntRect(41, 0, 40, 40));
}

void goCarToTheDown(car &car, float T)
{
    car.position.y = car.position.y + T;
    car.sprite.setPosition(car.position);
    car.sprite.setTextureRect(sf::IntRect(79, 0, 40, 40));
}