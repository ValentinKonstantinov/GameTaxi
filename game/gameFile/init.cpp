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
    destination.position = {50, 100};
    destination.sprite.setPosition(destination.position);
}

void initLevel(levelMap &levelMap, obstruction arreyObstruction[])
{

    static sf::Texture Texture;
    if (!Texture.loadFromFile(".\\texture\\level1.png"))
    {
        std::cout << "not texture level1" << std::endl;
    };
    levelMap.sprite.setPosition(sf::Vector2f(0, 100));
    levelMap.sprite.setTexture(Texture);

    ifstream level1Obstruction;
    level1Obstruction.open(".\\level\\fileLevel1Obstruction.txt");

    float pozX, pozY, sizeX, sizeY;
    int i = 0;
    do
    {
        level1Obstruction >> sizeX >> sizeY >> pozX >> pozY;
        pozY = pozY + 100;
        arreyObstruction[i].position = {pozX, pozY};
        arreyObstruction[i].size = {sizeX, sizeY};
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
        } while (passenger[i].collision != 1);
        passenger[i].money = 10 + rand() % 30;
        passenger[i].sprite.setPosition(passenger[i].position);
        passenger[i].sprite.setTexture(texture);
        passenger[i].sprite.setTextureRect(sf::IntRect(60, 0, 30, 40));
        if (passenger[i].money > 30)
        {
            passenger[i].sprite.setColor(sf::Color::Red);
            passenger[i].drive = {20, 20};
        }
        else
        {
            passenger[i].sprite.setColor(sf::Color::Green);
            passenger[i].drive = {10, 10};
        };
        passenger[i].sprite.setOrigin(sf::Vector2f(10, 20));
    };
    level1Passenger.close();
};

void initCar(car &car, sf::Font &fontName) //инициализирует структуру
{

    if (!car.texture.loadFromFile(".\\texture\\taxi.png"))
    {
        std::cout << "not texture car" << std::endl;
    }
    car.sprite.setTexture(car.texture);
    car.sprite.setTextureRect(sf::IntRect(120, 0, 40, 40));
    car.sprite.setColor(sf::Color::Yellow);
    car.position = {1, 555};
    car.sprite.setPosition(car.position);
    car.size = {40, 20};
    //car.sprite.setOrigin(sf::Vector2f(20, 12));
    car.collision = 0;
    car.speed = 100;
    car.name.setFont(fontName);
    std::string str;
    str = std::to_string(car.money);
    str = "stupid:" + str + "$";
    car.name.setString(str);
    car.name.setCharacterSize(30);
    car.name.setStyle(sf::Text::Bold);
    car.name.setFillColor(sf::Color::Red);
    car.name.setPosition(100, 0);
};

void initUserCar(car &userCar, sf::Font &fontName) //инициализирует структуру
{
    if (!userCar.texture.loadFromFile(".\\texture\\taxi.png"))
    {
        std::cout << "not texture car" << std::endl;
    };

    userCar.sprite.setTexture(userCar.texture);
    userCar.sprite.setTextureRect(sf::IntRect(120, 0, 40, 40));
    userCar.sprite.setColor(sf::Color(250, 235, 215));
    userCar.position = {300, 551};
    userCar.size = {40, 20};
    //userCar.sprite.setOrigin(sf::Vector2f(20, 12));
    userCar.collision = 0;
    userCar.speed = 100;
    userCar.name.setFont(fontName);
    std::string str;
    str = std::to_string(userCar.money);
    str = "user:" + str + "$";
    userCar.name.setString(str);
    userCar.name.setCharacterSize(30);
    userCar.name.setStyle(sf::Text::Bold);
    userCar.name.setFillColor(sf::Color::Red);
    userCar.name.setPosition(100, 40);
};

void initOilStruct(oilStruct &oil)
{
    if (!oil.texture.loadFromFile(".\\texture\\oil.png"))
    {
        std::cout << "not texture oil" << std::endl;
    };
    oil.sprite.setTexture(oil.texture);
    oil.sprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
    oil.position = {250, 250};
    oil.timeOil = 0;
    oil.activation = 0;
}