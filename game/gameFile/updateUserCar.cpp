#include "declaration.hpp"

void updateUserCar(car &userCar, car &userCar2, float time, char &keyPressed, obstruction arreyObstruction[], passenger passenger[])
{
    if (userCar.timeOil > 0)
    {
        userCar.timeOil = userCar.timeOil - time;
    }
    else
    {
        userCar.speed = 100;
    };
    float T = userCar.speed * time;
    float distanceCarPassenger = 20;
    sf::Vector2f positionCarPrevious = userCar.sprite.getPosition();
    sf::Vector2f positionCarPrevious2 = userCar2.sprite.getPosition();
    sf::IntRect texturePrevious = userCar.sprite.getTextureRect();
    sf::IntRect texturePrevious2 = userCar2.sprite.getTextureRect();
    float rotationCarPrevious;
    userCar.sprite.setPosition(userCar.position);
    if (userCar.keyPressed == 'A')
    {
        goCarToTheLeft(userCar, T);
        collisionCheck(userCar, arreyObstruction);
        if (userCar.collision == 1)
        {
            userCar.position = positionCarPrevious;
            userCar.sprite.setPosition(positionCarPrevious);
            userCar.sprite.setTextureRect(texturePrevious);
        }
    };
    if (userCar.keyPressed == 'W')
    {
        goCarToTheUp(userCar, T);
        collisionCheck(userCar, arreyObstruction);
        if (userCar.collision == 1)
        {
            userCar.position = positionCarPrevious;
            userCar.sprite.setPosition(positionCarPrevious);
            userCar.sprite.setTextureRect(texturePrevious);
        }
    };
    if (userCar.keyPressed == 'D')
    {
        goCarToTheRight(userCar, T);
        collisionCheck(userCar, arreyObstruction);
        if (userCar.collision == 1)
        {
            userCar.position = positionCarPrevious;
            userCar.sprite.setPosition(positionCarPrevious);
            userCar.sprite.setTextureRect(texturePrevious);
        }
    };
    if (userCar.keyPressed == 'S')
    {
        goCarToTheDown(userCar, T);
        collisionCheck(userCar, arreyObstruction);
        if (userCar.collision == 1)
        {
            userCar.position = positionCarPrevious;
            userCar.sprite.setPosition(positionCarPrevious);
            userCar.sprite.setTextureRect(texturePrevious);
        }
    };
    if (userCar2.activation)
    {
        if (userCar2.keyPressed == 'H')
        {
            goCarToTheLeft(userCar2, T);
            collisionCheck(userCar2, arreyObstruction);
            if (userCar2.collision == 1)
            {
                userCar2.position = positionCarPrevious2;
                userCar2.sprite.setPosition(positionCarPrevious2);
                userCar2.sprite.setTextureRect(texturePrevious2);
            }
        };
        if (userCar2.keyPressed == 'U')
        {
            goCarToTheUp(userCar2, T);
            collisionCheck(userCar2, arreyObstruction);
            if (userCar2.collision == 1)
            {
                userCar2.position = positionCarPrevious2;
                userCar2.sprite.setPosition(positionCarPrevious2);
                userCar2.sprite.setTextureRect(texturePrevious2);
            }
        };
        if (userCar2.keyPressed == 'K')
        {
            goCarToTheRight(userCar2, T);
            collisionCheck(userCar2, arreyObstruction);
            if (userCar2.collision == 1)
            {
                userCar2.position = positionCarPrevious2;
                userCar2.sprite.setPosition(positionCarPrevious2);
                userCar2.sprite.setTextureRect(texturePrevious2);
            }
        };
        if (userCar2.keyPressed == 'J')
        {
            goCarToTheDown(userCar2, T);
            collisionCheck(userCar2, arreyObstruction);
            if (userCar2.collision == 1)
            {
                userCar2.position = positionCarPrevious2;
                userCar2.sprite.setPosition(positionCarPrevious2);
                userCar2.sprite.setTextureRect(texturePrevious2);
            }
        }
    }
}

void userCarLogica(car &userCar, passenger passenger[], destination &destination)
{
    if (userCar.activation)
    {
        sf::Vector2f delta;
        std::string str;
        if (userCar.withAPassenger == 0)
        {
            int passengerNumber = 0;
            do
            {
                if (passenger[passengerNumber].activation == 1)
                {
                    delta = passenger[passengerNumber].position - userCar.position;
                    if ((fabs(round(delta.x)) <= 40) && (fabs(round(delta.y)) <= 40))
                    {
                        userCar.withAPassenger = 1;
                        userCar.passengerMoney = passenger[passengerNumber].money;
                        userCar.passengerNumber = passengerNumber;
                        if (userCar.passengerMoney > 30)
                        {
                            userCar.sprite.setColor(sf::Color::Red);
                        }
                        else
                        {
                            userCar.sprite.setColor(sf::Color::Green);
                        };
                        passenger[userCar.passengerNumber].activation = 2;
                    }
                }
                ++passengerNumber;
            } while ((userCar.withAPassenger == 0) && (passengerNumber < 100));
        }
        else if (userCar.withAPassenger == 1)
        {
            delta = destination.position - userCar.position;
            if ((fabs(round(delta.x)) <= 50) && (fabs(round(delta.y)) <= 50))
            {
                userCar.money = userCar.money + userCar.passengerMoney;
                userCar.passengerMoney = 0;
                passenger[userCar.passengerNumber].activation = 0;
                userCar.withAPassenger = 0;
                userCar.sprite.setColor(sf::Color(250, 235, 215));
            };
        };
        str = std::to_string(userCar.money);
        str = userCar.userName + ": " + str + "$";
        if (userCar.availabilityOil == 1)
        {
            str = str + " OIL";
        };
        userCar.menuText.setString(str);
    }
}