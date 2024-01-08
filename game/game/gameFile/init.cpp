#include "declaration.hpp"

using namespace std;

void initDestination(destination &destination)
{
    static sf::Texture texture;
    if (!texture.loadFromFile(".\\texture\\destination.png"))
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
    level1Obstruction.open(".\\level\\fileLevel1Obstruction.txt");

    float pozX, pozY, sizeX, sizeY;
    int i = 0;

    static sf::Texture rTexture;
    if (!rTexture.loadFromFile(".\\texture\\r.png"))
    {
        std::cout << "not texture r" << std::endl;
    }

    static sf::Texture domTexture;
    if (!domTexture.loadFromFile(".\\texture\\dom.png"))
    {
        std::cout << "not texture dom" << std::endl;
    }

    static sf::Texture domAltTexture;
    if (!domAltTexture.loadFromFile(".\\texture\\domalt.png"))
    {
        std::cout << "not texture dom" << std::endl;
    }

    static sf::Texture bulvarTexture;
    if (!bulvarTexture.loadFromFile(".\\texture\\bulvar.png"))
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
            pozX = pozX - 35;
            sizeX = sizeX - 20;
            arreyObstruction[i].sprite.setPosition(sf::Vector2f(pozX + 35, pozY));
            arreyObstruction[i].position = {pozX, pozY};
            arreyObstruction[i].sprite.setTexture(domTexture);
            arreyObstruction[i].size = {sizeX + 40, sizeY};
        }
        else if (objectType == "bulvar")
        {
            pozX = pozX - 35;
            sizeX = sizeX - 20;
            arreyObstruction[i].sprite.setPosition(sf::Vector2f(pozX + 35, pozY));
            arreyObstruction[i].position = {pozX, pozY};
            arreyObstruction[i].sprite.setTexture(bulvarTexture);
            arreyObstruction[i].size = {sizeX + 40, sizeY};
        }
        else if (objectType == "domalt")
        {
            pozX = pozX - 35;
            sizeX = sizeX - 20;
            arreyObstruction[i].sprite.setPosition(sf::Vector2f(pozX + 35, pozY));
            arreyObstruction[i].position = {pozX, pozY};
            arreyObstruction[i].sprite.setTexture(domAltTexture);
            arreyObstruction[i].size = {sizeX + 40, sizeY};
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

void initPassenger(passenger passenger[], obstruction arreyObstruction[])
{
    ifstream level1Passenger;
    level1Passenger.open(".\\level\\fileLevel1Passenger.txt");

    static sf::Texture texture;
    if (!texture.loadFromFile(".\\texture\\passenger.png"))
    {
        std::cout << "not texture passenger" << std::endl;
    };
    int quantityPassenger;
    level1Passenger >> quantityPassenger;
    for (int i = 0; i < quantityPassenger; ++i)
    {
        float pozX, pozY;
        passenger[i].activation = 1;
        passenger[i].size = {20, 40};

        do
        {
            passenger[i].collision = 0;
            pozX = 100 + rand() % 600;
            pozY = 100 + rand() % 400;
            passenger[i].position = {pozX, pozY};
            collisionCheckInitPassenger(passenger[i], arreyObstruction);
        } while (passenger[i].collision != 0);
        passenger[i].money = 10 + rand() % 10;
        passenger[i].sprite.setPosition(passenger[i].position);
        passenger[i].sprite.setTexture(texture);
        passenger[i].sprite.setColor(sf::Color::Red);
        passenger[i].sprite.setOrigin(sf::Vector2f(10, 20));
    };
}

void initCar(car &car, sf::Clock &clock) //инициализирует структуру
{
    if (!car.texture.loadFromFile(".\\texture\\taxi.png"))
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