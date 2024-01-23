#include "declaration.hpp"

void collisionCheckInitPassenger(passenger &passenger, obstruction arreyObstruction[]) //виснет, слишком трудоемко?
{
    sf::Vector2f coordinatesObstr, coordinatesCar;
    passenger.collision = 0;
    if ((passenger.position.x < 10) || (passenger.position.x > 790) || (passenger.position.y < 100) || (passenger.position.y > 590))
    {
        passenger.collision = 0;
    }
    else
    {
        float carX = round(passenger.position.x);
        float carY = round(passenger.position.y);
        coordinatesCar = {carX, carY};
        for (int i = 0; i <= 20; ++i)
        {
            for (float ObstrX = arreyObstruction[i].position.x; ObstrX <= arreyObstruction[i].position.x + arreyObstruction[i].size.x; ++ObstrX)
            {

                for (float ObstrY = arreyObstruction[i].position.y; ObstrY <= arreyObstruction[i].position.y + arreyObstruction[i].size.y; ++ObstrY)
                {
                    coordinatesObstr = {ObstrX, ObstrY};
                    if ((coordinatesCar.x == coordinatesObstr.x) && (coordinatesCar.y == coordinatesObstr.y))
                    {
                        passenger.collision = 1;
                    }
                }
            }
        }
    }
};

void collisionCheckInitOil(oilStruct &oil, obstruction arreyObstruction[])
{
    sf::Vector2f coordinatesObstr, coordinatesCar;
    oil.collision = 0;
    if ((oil.position.x < 10) || (oil.position.x > 790) || (oil.position.y < 100) || (oil.position.y > 590))
    {
        oil.collision = 0;
    }
    else
    {
        float carX = round(oil.position.x);
        float carY = round(oil.position.y);
        coordinatesCar = {carX, carY};
        for (int i = 0; i <= 20; ++i)
        {
            for (float ObstrX = arreyObstruction[i].position.x; ObstrX <= arreyObstruction[i].position.x + arreyObstruction[i].size.x; ++ObstrX)
            {

                for (float ObstrY = arreyObstruction[i].position.y; ObstrY <= arreyObstruction[i].position.y + arreyObstruction[i].size.y; ++ObstrY)
                {
                    coordinatesObstr = {ObstrX, ObstrY};
                    if ((coordinatesCar.x == coordinatesObstr.x) && (coordinatesCar.y == coordinatesObstr.y))
                    {
                        oil.collision = 1;
                    }
                }
            }
        }
    }
};

void collisionCarAndUserCar(car &userCar, bool &endGame, car &car)
{
    float carX = car.sprite.getPosition().x;
    float carY = car.sprite.getPosition().y;
    float carUserX = userCar.sprite.getPosition().x;
    float carUserY = userCar.sprite.getPosition().y;
    //cout << "collisionCarAndUserCar" << endl;
    //sf::Vector2f coordinatesUserCar, coordinatesCar;
    for (float i = carX; i <= carX + 40; ++i)
    {
        for (float j = carY; j <= carY + 40; ++j)
        {
            for (float x = carUserX; x <= carUserX + 40; ++x)
            {
                for (float y = carUserY; y <= carUserY + 40; ++y)
                {
                    if ((x - i < 1) && (x - i > -1) && (y - j < 1) && (y - j > -1))

                    {
                        endGame = true;
                    };
                }
            }
        }
    }
};
