#include "declaration.hpp"

void collisionCheckInitPassenger(passenger &passenger, obstruction arreyObstruction[]) //виснет, слишком трудоемко?
{
    //return false;
    //std::cout << event.y << std::endl;
    // passenger.collision = 0;
    sf::Vector2f coordinatesObstr, coordinatesCar;
    if ((passenger.position.x < 10) || (passenger.position.x > 790) || (passenger.position.y < 10) || (passenger.position.y > 590))
    {
        passenger.collision = 1;
    }
    else
    {
        float sizeX, sizeY;
        /* if ((car.rotation == -90) || (car.rotation == 90))
        {
            sizeX = car.size.y / 2;
            sizeY = car.size.x / 2;
        }
        else
        {*/
        sizeX = passenger.size.x / 2;
        sizeY = passenger.size.y / 2;
        // };
        float carX = round(passenger.position.x) - sizeX;
        float carY = round(passenger.position.y) - sizeY;
        for (carX; carX <= passenger.position.x + sizeX; ++carX)
        {
            for (carY; carY <= passenger.position.y + sizeY; ++carY)
            {
                coordinatesCar = {carX, carY};
                for (int i = 0; i <= 10; ++i)
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
        }
    }
};