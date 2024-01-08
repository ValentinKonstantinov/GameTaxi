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
void onMouseMove(const sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePosition)
{
    // std::cout << "mouse x=" << event.x << ", y=" << event.y << std::endl;

    mousePosition = {float(event.x), float(event.y)};
}
void onMouseClick(const sf::Event::MouseButtonEvent &event, sf::Vector2f &mouseClikPosition)
{
    std::cout << "mouse x=" << event.x << ", y=" << event.y << std::endl;

    mouseClikPosition = {float(event.x), float(event.y)};