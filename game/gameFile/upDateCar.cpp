#include "declaration.hpp"

void updatecar(car &car, float time, sf::Vector2f &delta, obstruction arreyObstruction[], passenger passenger[])
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
    float distanceCarPassenger = 20;
    sf::Vector2f positionCarPrevious = car.sprite.getPosition();
    sf::IntRect texturePrevious = car.sprite.getTextureRect();
    if (car.collision == 0)
    {
        if (delta.x > distanceCarPassenger || delta.x < -distanceCarPassenger)
        {
            if (delta.x < 0)
            {
                goCarToTheLeft(car, T);
                collisionCheck(car, arreyObstruction);
                if (car.collision == 1)
                {
                    car.position = positionCarPrevious;
                    car.sprite.setPosition(positionCarPrevious);
                    car.sprite.setTextureRect(texturePrevious);
                    car.collision = 4;
                };
            }
            else
            {
                goCarToTheRight(car, T);
                collisionCheck(car, arreyObstruction);
                if (car.collision == 1)
                {
                    car.position = positionCarPrevious;
                    car.sprite.setPosition(positionCarPrevious);
                    car.sprite.setTextureRect(texturePrevious);
                    car.collision = 2;
                };
            };
            //definitionOfRotationCarLeftRight(car, delta, distanceCarPassenger);
        }
        else if (delta.y > distanceCarPassenger || delta.y < -distanceCarPassenger)
        {
            if (delta.y < 0)
            {
                goCarToTheUp(car, T);
                collisionCheck(car, arreyObstruction);
                if (car.collision == 1)
                {
                    car.position = positionCarPrevious;
                    car.sprite.setPosition(positionCarPrevious);
                    car.sprite.setTextureRect(texturePrevious);
                };
            }
            else
            {
                goCarToTheDown(car, T);
                collisionCheck(car, arreyObstruction);
                if (car.collision == 1)
                {
                    car.collision = 3;
                    car.position = positionCarPrevious;
                    car.sprite.setPosition(positionCarPrevious);
                    car.sprite.setTextureRect(texturePrevious);
                };
            };
            //definitionOfRotationCarUpDown(car, delta, distanceCarPassenger);
        };
    }
    else
    {

        if (car.collision == 1)
        {
            goCarToTheLeft(car, T);
            collisionCheck(car, arreyObstruction);
            if (car.collision == 1)
            {
                car.position = positionCarPrevious;
                car.sprite.setPosition(positionCarPrevious);
                car.sprite.setTextureRect(texturePrevious);
                car.collision = 4;
            }
            else
            {
                positionCarPrevious = car.sprite.getPosition();
                texturePrevious = car.sprite.getTextureRect();
                goCarToTheUp(car, T);
                collisionCheck(car, arreyObstruction);
                if (car.collision == 1)
                {
                    car.position = positionCarPrevious;
                    car.sprite.setPosition(positionCarPrevious);
                    car.sprite.setTextureRect(texturePrevious);
                    car.collision = 1;
                };
            }
        };
        if (car.collision == 4)
        {
            goCarToTheDown(car, T);
            collisionCheck(car, arreyObstruction);
            if (car.collision == 1)
            {
                car.position = positionCarPrevious;
                car.sprite.setPosition(positionCarPrevious);
                car.sprite.setTextureRect(texturePrevious);
                car.collision = 3;
            }
            else
            {
                positionCarPrevious = car.sprite.getPosition();
                texturePrevious = car.sprite.getTextureRect();
                goCarToTheLeft(car, T);

                collisionCheck(car, arreyObstruction);
                if (car.collision == 1)
                {
                    car.position = positionCarPrevious;
                    car.sprite.setPosition(positionCarPrevious);
                    car.sprite.setTextureRect(texturePrevious);
                    car.collision = 4;
                }
            }
        };
        if (car.collision == 3)
        {
            goCarToTheRight(car, T);
            collisionCheck(car, arreyObstruction);
            if (car.collision == 1)
            {
                car.position = positionCarPrevious;
                car.sprite.setPosition(positionCarPrevious);
                car.sprite.setTextureRect(texturePrevious);
                car.collision = 2;
                // std::cout << car.collision << std::endl;
            }
            else
            {
                positionCarPrevious = car.sprite.getPosition();
                texturePrevious = car.sprite.getTextureRect();
                goCarToTheDown(car, T);
                collisionCheck(car, arreyObstruction);
                if (car.collision == 1)
                {
                    car.position = positionCarPrevious;
                    car.sprite.setPosition(positionCarPrevious);
                    car.sprite.setTextureRect(texturePrevious);
                    car.collision = 3;
                };
                //std::cout << car.collision << std::endl;
            }
        };
        if (car.collision == 2)
        {
            goCarToTheUp(car, T);
            collisionCheck(car, arreyObstruction);
            if (car.collision == 1)
            {
                car.position = positionCarPrevious;
                car.sprite.setPosition(positionCarPrevious);
                car.sprite.setTextureRect(texturePrevious);
                car.collision = 1;
            }
            else
            {
                positionCarPrevious = car.sprite.getPosition();
                texturePrevious = car.sprite.getTextureRect();
                goCarToTheRight(car, T);
                collisionCheck(car, arreyObstruction);
                if (car.collision == 1)
                {
                    car.position = positionCarPrevious;
                    car.sprite.setPosition(positionCarPrevious);
                    car.sprite.setTextureRect(texturePrevious);
                    car.collision = 2;
                }
            }
        }
    }
};

void carLogica(car &car, sf::Vector2f &delta, passenger passenger[], destination &destination)
{
    std::string str;
    if (car.withAPassenger == 0)
    {
        int passengerNumber = 0;
        do
        {
            ++passengerNumber;
        } while ((passenger[passengerNumber - 1].activation != 1) && (passengerNumber < 100));
        --passengerNumber;
        delta = passenger[passengerNumber].position - car.position;
        if ((fabs(round(delta.x)) <= 50) && (fabs(round(delta.y)) <= 50))
        {
            car.passengerMoney = passenger[passengerNumber].money;
            car.passengerNumber = passengerNumber;
            car.withAPassenger = 1;
            passenger[car.passengerNumber].activation = 2;
        };
    }
    else
    {
        delta = destination.position - car.position;
        if ((fabs(round(delta.x)) <= 60) && (fabs(round(delta.y)) <= 60))
        {
            car.money = car.money + car.passengerMoney;
            car.passengerMoney = 0;
            passenger[car.passengerNumber].activation = 0;
            car.withAPassenger = 0;
        };
    };
    str = std::to_string(car.money);
    str = "stupidTaxi:" + str + "$";
    if (car.availabilityOil == 1)
    {
        str = str + " OIL";
    };
    car.menuText.setString(str);
}