#include "declaration.hpp"

void collisionCheck(car &car, obstruction arreyObstruction[]) //виснет, слишком трудоемко?
{
    //return false;
    //std::cout << event.y << std::endl;
    car.collision = 0;
    sf::Vector2f coordinatesObstr, coordinatesCar;
    if ((car.sprite.getPosition().x < 0) || (car.sprite.getPosition().x + 40 > 800) || (car.sprite.getPosition().y < 100) || (car.sprite.getPosition().y + 40 > 600))
    {
        car.collision = 1;
    }
    else
    {
        float carX = car.sprite.getPosition().x;
        float carY = car.sprite.getPosition().y;

        for (float x = carX; x <= carX + 24; ++x)
        {
            for (float y = carY; y <= carY + 24; ++y)
            {
                for (int i = 0; i <= 20; ++i)
                {

                    for (float ObstrX = arreyObstruction[i].position.x; ObstrX <= arreyObstruction[i].position.x + arreyObstruction[i].size.x; ObstrX = ObstrX + 20)
                    {

                        for (float ObstrY = arreyObstruction[i].position.y; ObstrY <= arreyObstruction[i].position.y + arreyObstruction[i].size.y; ObstrY = ObstrY + 20)
                        {

                            if ((x - ObstrX < 1) && (x - ObstrX > -1) && (y - ObstrY < 1) && (y - ObstrY > -1))
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

void collisionCheckOilAndCar(oilStruct &oil, car &car)
{
    float carX = car.sprite.getPosition().x;
    float carY = car.sprite.getPosition().y;
    float carUserX = oil.sprite.getPosition().x;
    float carUserY = oil.sprite.getPosition().y;
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
                        if (oil.activation == 1)
                        {
                            car.availabilityOil = 1;
                            oil.activation = 2;
                        };
                        if ((oil.activation == 3) && (oil.timeOil <= 0))
                        {
                            car.timeOil = 10;
                            car.speed = 20;
                            oil.activation = 0;
                        }
                    }
                }
            }
        }
    }
};

void collisionCheckPetrolAndCar(petrolStruct &petrol, car &car)
{
    float carX = car.sprite.getPosition().x;
    float carY = car.sprite.getPosition().y;
    float carUserX = petrol.sprite.getPosition().x;
    float carUserY = petrol.sprite.getPosition().y;
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
                        petrol.activation = 0;
                    }
                }
            }
        }
    };
    if (petrol.activation == 0)
    {
        car.speed += petrol.addingSpeed;
    }
};

void collisionCheckAlgoCar(car &car, obstruction arreyObstruction[]) //виснет, слишком трудоемко?
{
    //return false;
    //std::cout << event.y << std::endl;
    car.collision = 0;
    sf::Vector2f coordinatesObstr, coordinatesCar;
    if ((car.sprite.getPosition().x < 0) || (car.sprite.getPosition().x + 40 > 800) || (car.sprite.getPosition().y < 100) || (car.sprite.getPosition().y + 40 > 600))
    {
        car.collision = 1;
    }
    else
    {
        float carX = car.sprite.getPosition().x;
        float carY = car.sprite.getPosition().y;

        for (float x = carX; x <= carX; ++x)
        {
            for (float y = carY; y <= carY; ++y)
            {
                for (int i = 0; i <= 20; ++i)
                {

                    for (float ObstrX = arreyObstruction[i].position.x; ObstrX <= arreyObstruction[i].position.x + arreyObstruction[i].size.x; ObstrX = ObstrX + 20)
                    {

                        for (float ObstrY = arreyObstruction[i].position.y; ObstrY <= arreyObstruction[i].position.y + arreyObstruction[i].size.y; ObstrY = ObstrY + 20)
                        {

                            if ((x - ObstrX < 1) && (x - ObstrX > -1) && (y - ObstrY < 1) && (y - ObstrY > -1))
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
