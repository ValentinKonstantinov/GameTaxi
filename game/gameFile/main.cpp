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

float distance = 0;

struct obstruction
{
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f position;
    sf::Vector2f size;
};

struct car
{
    sf::Clock &clock;
    sf::Texture texture;
    sf::Vector2f size;
    sf::Sprite sprite;

    sf::Vector2f position;
    float rotation = 0;
    float withAPassenger = 0;
    car(sf::Clock &clock)
        : clock(clock){};
    float collision;
};

struct destination
{
    sf::Clock &clock;
    sf::Texture texture;

    sf::Sprite sprite;

    sf::Vector2f position;
    float rotation = 0;

    destination(sf::Clock &clock)
        : clock(clock)
    {
    }
};

struct passenger
{
    sf::Clock &clock;
    sf::Texture texture;

    sf::Sprite sprite;

    sf::Vector2f position;
    float rotation = 0;

    passenger(sf::Clock &clock)
        : clock(clock)
    {
    }
};

sf::Vector2f toEuclidean(float radius, float angle)
{
    return {
        static_cast<float>(radius * cos(angle)),
        static_cast<float>(radius * sin(angle))};
};
int main()
{
    constexpr unsigned WINDOW_WIDTH = 800;
    constexpr unsigned WINDOW_HEIGHT = 600;
    sf::Clock clock;
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}),
        "Arrow follows mouse", sf::Style::Default, settings);

    car car(clock);
    destination destination(clock);
    passenger passenger(clock);
    obstruction arreyObstruction[100];
    sf::Vector2f mousePosition;
    sf::Vector2f mouseClikPosition;
    initLevel(arreyObstruction);
    initPassenger(passenger);
    initDestination(destination);

    initCar(car, clock);

    while (window.isOpen())
    {
        pollEvents(window, mousePosition, mouseClikPosition);
        update(mousePosition, mouseClikPosition, car, passenger, destination, arreyObstruction, clock);
        redrawFrame(window, car, passenger, destination, arreyObstruction);
    }
}