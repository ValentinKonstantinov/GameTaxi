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
    };
}