#include "declaration.hpp"

void collisionCheck(car &car, obstruction arreyObstruction[]) //виснет, слишком трудоемко?
{
    //return false;
    //std::cout << event.y << std::endl;
    car.collision = 0;
    sf::Vector2f coordinatesObstr, coordinatesCar;
    if ((car.position.x < 10) || (car.position.x > 790) || (car.position.y < 10) || (car.position.y > 590))
    {
        car.collision = 1;
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
        sizeX = car.size.x / 2;
        sizeY = car.size.y / 2;
        // };
        float carX = round(car.position.x) - sizeX;
        float carY = round(car.position.y) - sizeY;
        for (carX; carX <= car.position.x + sizeX; ++carX)
        {
            for (carY; carY <= car.position.y + sizeY; ++carY)
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
                                car.collision = 1;
                            }
                        }
                    }
                }
            }
        }
    }
};