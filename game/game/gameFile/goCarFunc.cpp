#include "declaration.hpp"

void goCarToTheLeft(car &car, float T)
{
    car.position.x = car.position.x - T;
    car.rotation = 180;
}

void goCarToTheRight(car &car, float T)
{
    car.position.x = car.position.x + T;
    car.rotation = 0;
}

void goCarToTheUp(car &car, float T)
{
    car.position.y = car.position.y - T;
    car.rotation = -90;
}

void goCarToTheDown(car &car, float T)
{
    car.position.y = car.position.y + T;
    car.rotation = 90;
}