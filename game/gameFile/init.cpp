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
void initDestination(destination &destination)
{
    static sf::Texture texture;
    if (!texture.loadFromFile("destination.png"))
    {
        std::cout << "not texture destination" << std::endl;
    }
    destination.sprite.setTexture(texture);
    destination.sprite.setOrigin(sf::Vector2f(80, 80));
    destination.position = {80, 80};
    destination.sprite.setPosition(destination.position);
}
void initLevel(obstruction arreyObstruction[])
{
    ifstream level1Obstruction;
    level1Obstruction.open("fileLevel1Obstruction.txt");

    float pozX, pozY, sizeX, sizeY;
    int i = 0;

    static sf::Texture rTexture;
    if (!rTexture.loadFromFile("r.png"))
    {
        std::cout << "not texture r" << std::endl;
    }

    static sf::Texture domTexture;
    if (!domTexture.loadFromFile("dom.png"))
    {
        std::cout << "not texture dom" << std::endl;
    }

    static sf::Texture domAltTexture;
    if (!domAltTexture.loadFromFile("domalt.png"))
    {
        std::cout << "not texture dom" << std::endl;
    }

    static sf::Texture bulvarTexture;
    if (!bulvarTexture.loadFromFile("bulvar.png"))
    {
        std::cout << "not texture dom" << std::endl;
    }

    do
    {
        level1Obstruction >> sizeX >> sizeY >> pozX >> pozY;
        std::string objectType;
        level1Obstruction >> objectType;
        std::cout << objectType << std::endl;
        //texture.setRepeated(true);
        if (objectType == "R")
        {
            //r.sprite.setPosition(sf::Vector2f(pozX, pozY));
            //r.position = {pozX, pozY};
            arreyObstruction[i].sprite.setPosition(sf::Vector2f(pozX, pozY));
            arreyObstruction[i].position = {pozX, pozY};
            arreyObstruction[i].sprite.setTexture(rTexture);
            arreyObstruction[i].size = {sizeX, sizeY};
        }
        else if (objectType == "dom")
        {
            arreyObstruction[i].sprite.setPosition(sf::Vector2f(pozX, pozY));
            arreyObstruction[i].position = {pozX, pozY};
            arreyObstruction[i].sprite.setTexture(domTexture);
            arreyObstruction[i].size = {sizeX, sizeY};
        }
        else if (objectType == "bulvar")
        {
            arreyObstruction[i].sprite.setPosition(sf::Vector2f(pozX, pozY));
            arreyObstruction[i].position = {pozX, pozY};
            arreyObstruction[i].sprite.setTexture(bulvarTexture);
            arreyObstruction[i].size = {sizeX, sizeY};
        }
        else if (objectType == "domalt")
        {
            arreyObstruction[i].sprite.setPosition(sf::Vector2f(pozX, pozY));
            arreyObstruction[i].position = {pozX, pozY};
            arreyObstruction[i].sprite.setTexture(domAltTexture);
            arreyObstruction[i].size = {sizeX, sizeY};
        }
        else if (objectType == "border")
        {
            arreyObstruction[i].position = {pozX, pozY};
            arreyObstruction[i].size = {sizeX, sizeY};
        };
        ++i;
    } while (!level1Obstruction.eof());
    level1Obstruction.close();
}
void initPassenger(passenger &passenger)
{
    static sf::Texture texture;
    if (!texture.loadFromFile("passenger.png"))
    {
        std::cout << "not texture passenger" << std::endl;
    }
    passenger.sprite.setTexture(texture);
    passenger.sprite.setOrigin(sf::Vector2f(25, 50));
}

void initCar(car &car, sf::Clock &clock) //инициализирует структуру
{
    if (!car.texture.loadFromFile("taxi.png"))
    {
        std::cout << "not texture car" << std::endl;
    }
    car.sprite.setTexture(car.texture);
    car.position = {500, 100};
    car.size = {50, 20};
    car.rotation = 0;
    car.sprite.setOrigin(sf::Vector2f(25, 10));
    car.collision = 0;
}
