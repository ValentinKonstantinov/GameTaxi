#include "declaration.hpp"

void updateDestination(float &time, destination &destination)
{
    destination.timeDestination = destination.timeDestination + time;
    if (destination.timeDestination < -10)
    {
        //раздуваем и сдуваем
    };
    if (static_cast<int>(destination.timeDestination) % 2 == 1)
    {
        destination.sprite.setColor(sf::Color::Red);
    }
    else if (static_cast<int>(destination.timeDestination) % 2 == 0)
    {
        destination.sprite.setColor(sf::Color::Green);
    }
};

void udateOil(car &userCar, oilStruct &oil, car &car, obstruction arreyObstruction[], float &time)
{
    if (oil.timeOil > 0)
    {
        oil.timeOil = oil.timeOil - time;
    };
    if (oil.activation == 0)
    {
        oil.activation = 1;
        float pozX = 0;
        float pozY = 0;
        do
        {
            oil.collision = 0;
            pozX = 100 + rand() % 600;
            pozY = 100 + rand() % 400;
            oil.position = {pozX, pozY};
            collisionCheckInitOil(oil, arreyObstruction);
        } while (oil.collision == 1);
        oil.sprite.setPosition(oil.position);
        oil.sprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
    };
    if ((oil.activation == 1) || (oil.activation == 3))
    {
        collisionCheckOilAndCar(oil, userCar);
    };
    if ((oil.activation == 1) || (oil.activation == 3))
    {
        collisionCheckOilAndCar(oil, car);
    };
    if ((userCar.keyPressed == 'F') && (userCar.availabilityOil == 1))
    {
        userCar.availabilityOil = 0;
        oil.activation = 3;
        oil.sprite.setPosition(userCar.sprite.getPosition());
        oil.sprite.setTextureRect(sf::IntRect(50, 0, 50, 50));
        oil.timeOil = 4;
    };
    if (car.availabilityOil == 1)
    {
        car.availabilityOil = 0;
        oil.activation = 3;
        oil.sprite.setPosition(car.sprite.getPosition());
        oil.sprite.setTextureRect(sf::IntRect(50, 0, 50, 50));
        oil.timeOil = 6;
    };
};