#include "declaration.hpp"

void collisionCheckInitPassenger(passenger &passenger, mapStuct &levelMap)
{

    float sizeX, sizeY;
    if ((passenger.position.x < 10) || (passenger.position.x > 790) || (passenger.position.y < 100) || (passenger.position.y > 590))
    {
        passenger.collision = 0;
    }
    else
    {
        sizeX = passenger.size.x / 2;
        sizeY = passenger.size.y / 2;
        passenger.collision = 1;
        for (int X = round(passenger.position.x) - sizeX; (X <= passenger.position.x + sizeX) && (passenger.collision == 1); ++X)
        {
            for (int Y = round(passenger.position.y) - sizeY; (Y <= passenger.position.y + sizeY) && (passenger.collision == 1); ++Y)
            {
                if (levelMap.arreyMapStatusPosition[X][Y] == 0)
                {
                    passenger.collision = 0;
                }
            }
        }
    }
};