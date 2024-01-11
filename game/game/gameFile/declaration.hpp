#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <array>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
struct mapStuct
{
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f position;
    sf::Vector2f size;
    int arreyMapStatusPosition[800 + 1][600 + 1];
};

struct car
{
    sf::Clock &clock;
    sf::Texture texture;
    sf::Vector2f size;
    sf::Sprite sprite;
    int money = 0;
    sf::Vector2f position;
    float rotation = 0;
    float withAPassenger = 0;
    car(sf::Clock &clock)
        : clock(clock){};
    float collision;
    int passengerNumber = -1;
    int passengerMoney = 0;
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
    sf::Texture texture;
    float collision;
    sf::Sprite sprite;
    int money = 0;
    sf::Vector2f position;
    float rotation = 0;
    sf::Vector2f size;
    int activation = 0;
};

void redrawFrame(sf::RenderWindow &window, car &car, passenger passenger[], destination &destination, mapStuct &levelMap);
void update(const sf::Vector2f &mousePosition, sf::Vector2f &mouseClikPosition, car &car, passenger passenger[], destination &destination, mapStuct &levelMap, sf::Clock &clock);
void pollEvents(sf::RenderWindow &window, sf ::Vector2f &mousePosition, sf ::Vector2f &mouseClikPosition);
void initDestination(destination &destination);
void initLevel(mapStuct &levelMap);
void initPassenger(passenger passenger[], mapStuct &levelMap);
void initCar(car &car, sf::Clock &clock);
void onMouseMove(const sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePosition);
void onMouseClick(const sf::Event::MouseButtonEvent &event, sf::Vector2f &mouseClikPosition);
void updatecar(car &car, sf::Clock &clock, sf::Vector2f &delta, mapStuct &levelMap, passenger passenger[]);
void collisionCheck(car &car, mapStuct &levelMap);
void goCarToTheLeft(car &car, float T);
void goCarToTheRight(car &car, float T);
void goCarToTheUp(car &car, float T);
void goCarToTheDown(car &car, float T);
void collisionCheckInitPassenger(passenger &passenger, mapStuct &levelMap);