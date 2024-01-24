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
#include <SFML/Graphics/Export.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Color.hpp>
#include "SFML/Audio.hpp"
#include "SFML/Audio/Music.hpp"
#include "SFML/Audio/Listener.hpp"
#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/Export.hpp>
#include <SFML/Audio/SoundStream.hpp>
#include <SFML/Audio/InputSoundFile.hpp>
#include <SFML/System/Mutex.hpp>
#include <SFML/System/Time.hpp>
#include <string>
#include <vector>
using namespace std;
struct menu
{
    sf::Texture texture;
    sf::Sprite sprite;
};

struct levelMap
{
    sf::Texture texture;
    sf::Sprite sprite;
    int state = 0;
};

struct obstruction
{
    sf::Vector2f position;
    sf::Vector2f size;
};

struct car
{
    sf::Clock &clock;
    sf::Texture texture;
    sf::Vector2f size;
    sf::Sprite sprite;
    int money = 0;
    sf::Vector2f position;
    float withAPassenger = 0;
    car(sf::Clock &clock)
        : clock(clock){};
    float collision;
    int passengerNumber = -1;
    int passengerMoney = 0;
    float speed;
    sf::Text menuText;
    std::string userName;
    int availabilityOil = 0;
    float timeOil = 0;
    char keyPressed;
    bool activation = true;
};

struct destination
{
    sf::Clock &clock;
    sf::Texture texture;
    float timeDestination = 0;
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
    sf::Vector2f drive;
    float rotation = 0;
    sf::Vector2f size;
    int activation = 0;
    int counterCollision = 0;
    float timeDrive = 0;
};
struct oilStruct
{
    sf::Texture texture;
    sf::Sprite sprite;
    int activation;
    sf::Vector2f position;
    float timeOil;
    float collision;
};

void redrawFrame(car &algoCar, car &userCar, car &userCar2, sf::RenderWindow &window, car &car, passenger passenger[], destination &destination, levelMap &levelMap, oilStruct &oil);
void update(car &algoCar, car &userCar, car &userCar2, const sf::Vector2f &mousePosition, sf::Vector2f &mouseClikPosition, char &keyPressed, car &car, passenger passenger[], destination &destination, obstruction arreyObstruction[], sf::Clock &clock, oilStruct &oil);
void pollEvents(sf::RenderWindow &window, sf ::Vector2f &mousePosition, sf ::Vector2f &mouseClikPosition, char &keyPressed);
void initDestination(destination &destination);
void initLevel(levelMap &levelMap, obstruction arreyObstruction[]);
void initPassenger(passenger passenger[], obstruction arreyObstruction[]);
void initCar(car &car, sf::Font &fontName);
void initUserCar(car &userCar, sf::Font &fontName);
void onMouseMove(const sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePosition);
void onMouseClick(const sf::Event::MouseButtonEvent &event, sf::Vector2f &mouseClikPosition);
//void onKeyPressed(sf::Event::KeyPressed &event.key, char &keyPressed);
void updatecar(car &car, float time, sf::Vector2f &delta, obstruction arreyObstruction[], passenger passenger[]);
void updateUserCar(car &userCar, car &userCar2, float time, char &keyPressed, obstruction arreyObstruction[], passenger passenger[]);
void updatePassenger(float time, obstruction arreyObstruction[], passenger passenger[]);
void collisionCheck(car &car, obstruction arreyObstruction[]);
void goCarToTheLeft(car &car, float T);
void goCarToTheRight(car &car, float T);
void goCarToTheUp(car &car, float T);
void goCarToTheDown(car &car, float T);
void collisionCheckInitPassenger(passenger &passenger, obstruction arreyObstruction[]);
void collisionCarAndUserCar(car &userCar, bool &endGame, car &car);
void updateDestination(float &time, destination &destination);
void initOilStruct(oilStruct &oil);
void udateOil(car &algoCar, car &userCar, car &userCar2, oilStruct &oil, car &car, obstruction arreyObstruction[], float &time);
void collisionCheckInitOil(oilStruct &oil, obstruction arreyObstruction[]);
void collisionCheckOilAndCar(oilStruct &oil, car &car);
void userCarLogica(car &userCar, passenger passenger[], destination &destination);
void carLogica(car &car, sf::Vector2f &delta, passenger passenger[], destination &destination);
void initPreviewMenu(menu &previewMenu);
void pollEventsMenu(sf::RenderWindow &window, sf ::Vector2f &mousePosition, sf ::Vector2f &mouseClikPosition, char &keyPressed);
void algoCarLogica(car &car, sf::Vector2i &targetDrive, passenger passenger[], destination &destination, oilStruct &oil, obstruction arreyObstruction[]);
void algoDijkstra(sf::Vector2f end, sf::Vector2i &targetDrive, sf::Vector2f start);
void simplePathfindingAlgoritm(int ADJACENCY_MATRIX[][640], int &START, int &END, sf::Vector2i &targetDrive);
void updateAlgoCar(car &car, float time, sf::Vector2i &targetDrive, passenger passenger[], obstruction arreyObstruction[]);
void collisionCheckAlgoCar(car &car, obstruction arreyObstruction[]);
