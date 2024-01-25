#include "declaration.hpp"

void algoCarLogica(car &car, sf::Vector2i &targetDrive, passenger passenger[], destination &destination, oilStruct &oil, obstruction arreyObstruction[])
{
    // targetDrive = car.position;/*
    if (targetDrive.x < 0)
    {
        targetDrive.x = 0;
    };
    if (targetDrive.x > 775)
    {
        targetDrive.x = 775;
    };
    if (targetDrive.y < 100)
    {
        targetDrive.y = 100;
    };
    if (targetDrive.y > 575)
    {
        targetDrive.y = 575;
    };

    if (car.position.x < 0)
    {
        car.position.x = 0;
    };
    if (car.position.x > 775)
    {
        car.position.x = 775;
    };
    if (car.position.y < 100)
    {
        car.position.y = 100;
    };
    if (car.position.y > 575)
    {
        car.position.y = 575;
    };

    std::string str;
    sf::Vector2f delta;
    sf::Vector2f end;
    sf::Vector2f start;
    if (car.withAPassenger == 0)
    {
        int passengerNumber = 0;
        do
        {
            ++passengerNumber;
        } while ((passenger[passengerNumber - 1].activation != 1) && (passengerNumber < 100));
        --passengerNumber;
        start = car.position;
        if (passenger[passengerNumber].activation == 1)
        {
            end = passenger[passengerNumber].position;
            int X = static_cast<int>(car.position.x);
            int Y = static_cast<int>(car.position.y);
            targetDrive = {X, Y};
            if (end.x > 50)
            {
                end.x = end.x - 48;
            };
            algoDijkstra(end, targetDrive, start);
            if (end.y < 550)
            {
                end.y = end.y + 48;
            }
            algoDijkstra(end, targetDrive, start);
        }
        else
        {
            end = {0, 550};
            algoDijkstra(end, targetDrive, start);
        };

        /* if (end.x < 750)
        {
            end.x = end.x + 48;
        };
        algoDijkstra(end, targetDrive, start);*/

        /* if (end.y > 150)
        {
            end.y = end.y - 48;
        }
        algoDijkstra(end, targetDrive, start);
*/
        for (passengerNumber = 0; (passengerNumber < 100) && (car.withAPassenger != 1); ++passengerNumber)
        {
            if (passenger[passengerNumber].activation == 1)
            {
                delta = passenger[passengerNumber].position - car.position;
                if ((fabs(round(delta.x)) <= 60) && (fabs(round(delta.y)) <= 60))
                {
                    car.passengerMoney = passenger[passengerNumber].money;
                    car.passengerNumber = passengerNumber;
                    car.withAPassenger = 1;
                    passenger[car.passengerNumber].activation = 2;
                }
            }
        };

        if (car.availabilityOil == 1)
        {
            car.availabilityOil = 0;
            oil.activation = 3;
            oil.sprite.setPosition(car.sprite.getPosition());
            oil.sprite.setTextureRect(sf::IntRect(50, 0, 50, 50));
            oil.timeOil = 5;
        };
    }
    else
    {
        start = car.position;
        end = {25, 125};

        algoDijkstra(end, targetDrive, start);
        delta = destination.position - car.position;
        if ((fabs(round(delta.x)) <= 50) && (fabs(round(delta.y)) <= 50))
        {
            car.money = car.money + car.passengerMoney;
            car.passengerMoney = 0;
            passenger[car.passengerNumber].activation = 0;
            car.withAPassenger = 0;
        };
    };

    str = std::to_string(car.money);
    str = "SmartTaxi:" + str + "$";
    if (car.availabilityOil == 1)
    {
        str = str + " OIL";
    };
    car.menuText.setString(str);
};

void updateAlgoCar(car &car, float time, sf::Vector2i &targetDrive, passenger passenger[], obstruction arreyObstruction[])
{
    if (car.timeOil > 0)
    {
        car.timeOil = car.timeOil - time;
    }
    else
    {
        car.speed = 100;
    };
    float T = car.speed * time;
    int X = static_cast<int>(car.position.x);
    int Y = static_cast<int>(car.position.y);
    sf::Vector2i carPosition{X, Y};

    sf::Vector2i delta = targetDrive - carPosition;
    sf::Vector2f positionCarPrevious = car.sprite.getPosition();
    sf::IntRect texturePrevious = car.sprite.getTextureRect();

    if (delta.x >= 10)
    {
        goCarToTheRight(car, T);
    }
    else if (delta.x <= -10)
    {
        goCarToTheLeft(car, T);
    }
    else if (delta.y >= 10)
    {
        goCarToTheDown(car, T);
    }
    else if (delta.y <= -10)
    {
        goCarToTheUp(car, T);
    }
    else
    {
        float x = targetDrive.x;
        float y = targetDrive.y;
        car.position = {x, y};
        car.sprite.setPosition(x, y);
    }
    /*
    collisionCheckAlgoCar(car, arreyObstruction);
    if (car.collision == 1)
    {
        car.position = positionCarPrevious;
        car.sprite.setPosition(positionCarPrevious);
        car.sprite.setTextureRect(texturePrevious);
    };

    car.sprite.setPosition(car.position);*/
};