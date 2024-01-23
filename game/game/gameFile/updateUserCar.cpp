#include "declaration.hpp"

void updateUserCar(car &userCar, float time, char &keyPressed, obstruction arreyObstruction[], passenger passenger[])
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
    sf::Vector2f positionCarPrevious;
    sf::IntRect texturePrevious = userCar.sprite.getTextureRect();
    float rotationCarPrevious;
    userCar.sprite.setPosition(userCar.position);
    positionCarPrevious = userCar.sprite.getPosition();
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
}
