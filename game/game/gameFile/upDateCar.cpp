#include "declaration.hpp"

void updatecar(car &car, sf::Clock &clock, sf::Vector2f &delta, obstruction arreyObstruction[], passenger passenger[])
{
    //const sf::Vector2f headOffset = toEuclidean(distance, car.rotation);
    float time = clock.restart().asSeconds();
    float speed = 100;
    float T = speed * time;
    float distanceCarPassenger = 20;
    sf::Vector2f positionCarPrevious;
    float rotationCarPrevious;
    positionCarPrevious = car.position;
    rotationCarPrevious = car.rotation;
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
                    car.rotation = rotationCarPrevious;
                    car.collision = 4;
                }
            }
            else
            {
                goCarToTheRight(car, T);
                collisionCheck(car, arreyObstruction);
                if (car.collision == 1)
                {
                    car.collision = 2;
                    car.position = positionCarPrevious;
                    car.rotation = rotationCarPrevious;
                }
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
                    car.rotation = rotationCarPrevious;
                }
            }
            else
            {
                goCarToTheDown(car, T);
                collisionCheck(car, arreyObstruction);
                if (car.collision == 1)
                {
                    car.collision = 3;
                    car.position = positionCarPrevious;
                    car.rotation = rotationCarPrevious;
                }
            };
            //definitionOfRotationCarUpDown(car, delta, distanceCarPassenger);
        };
    }
    else
    {
        //std::cout << car.collision << std::endl;
        if (car.collision == 1)
        {
            goCarToTheLeft(car, T);
            collisionCheck(car, arreyObstruction);
            if (car.collision == 1)
            {
                car.position = positionCarPrevious;
                car.rotation = rotationCarPrevious;
                car.collision = 4;
            }
            else
            {
                positionCarPrevious = car.position;
                rotationCarPrevious = car.rotation;
                goCarToTheUp(car, T);
                collisionCheck(car, arreyObstruction);
                if (car.collision == 1)
                {
                    car.position = positionCarPrevious;
                    car.rotation = rotationCarPrevious;
                    car.collision = 1;
                }
            }
        };
        if (car.collision == 4)
        {
            goCarToTheDown(car, T);
            collisionCheck(car, arreyObstruction);
            if (car.collision == 1)
            {
                car.position = positionCarPrevious;
                car.rotation = rotationCarPrevious;
                car.collision = 3;
            }
            else
            {

                positionCarPrevious = car.position;
                rotationCarPrevious = car.rotation;
                goCarToTheLeft(car, T);

                collisionCheck(car, arreyObstruction);
                if (car.collision == 1)
                {
                    car.position = positionCarPrevious;
                    car.rotation = rotationCarPrevious;
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
                car.rotation = rotationCarPrevious;
                car.collision = 2;
                // std::cout << car.collision << std::endl;
            }
            else
            {
                positionCarPrevious = car.position;
                rotationCarPrevious = car.rotation;
                goCarToTheDown(car, T);
                collisionCheck(car, arreyObstruction);
                if (car.collision == 1)
                {
                    car.position = positionCarPrevious;
                    car.rotation = rotationCarPrevious;
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
                car.rotation = rotationCarPrevious;
                car.collision = 1;
            }
            else
            {
                positionCarPrevious = car.position;
                rotationCarPrevious = car.rotation;
                goCarToTheRight(car, T);
                collisionCheck(car, arreyObstruction);
                if (car.collision == 1)
                {
                    car.position = positionCarPrevious;
                    car.rotation = rotationCarPrevious;
                    car.collision = 2;
                }
            }
        }
    };
    if ((fabs(round(delta.x)) <= 50) && (fabs(round(delta.y)) <= 50))
    {
        if (car.withAPassenger == 0)
        {
            car.withAPassenger = 1;
            passenger[car.passengerNumber].activation = 2;
        }
        else
        {
            car.money = car.money + car.passengerMoney;
            car.passengerMoney = 0;
            passenger[car.passengerNumber].activation = 0;
            car.withAPassenger = 0;
        };
    };
    // collisionCheck(car, arreyObstruction, collision);

    car.sprite.setRotation(car.rotation);
    car.sprite.setPosition(car.position);
}