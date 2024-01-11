#include "declaration.hpp"

void collisionCheck(car &car, mapStuct &levelMap) //виснет, слишком трудоемко?
{
    //return false;
    //std::cout << event.y << std::endl;
    car.collision = 0;
    sf::Vector2f coordinatesObstr, coordinatesCar;
    if ((car.position.x < 10) || (car.position.x > 790) || (car.position.y < 100) || (car.position.y > 590))
    {
        car.collision = 1;
    }
    else
    {
        int sizeX, sizeY;
        sizeX = car.size.x / 2;
        sizeY = car.size.y / 2;
        for (int carX = round(car.position.x) - sizeX; (carX <= car.position.x + sizeX) && (car.collision == 0); ++carX)
        {
            for (int carY = round(car.position.y) - sizeY; (carY <= car.position.y + sizeY) && (car.collision == 0); ++carY)
            {
                if (levelMap.arreyMapStatusPosition[carX][carY] != 0)
                {
                    car.collision = 1;
                }
            }
        }
    }
};