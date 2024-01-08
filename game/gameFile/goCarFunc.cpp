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
}