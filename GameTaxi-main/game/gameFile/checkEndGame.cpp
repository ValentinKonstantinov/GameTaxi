#include "declaration.hpp"

void checkEndGame(bool &endGame, car &algoCar, car &userCar, car &userCar2, car &car, passenger passenger[], levelMap &levelMap, menu &endMenu)
{
    endGame = true;
    for (int i = 0; i < 100; ++i)
    {
        if (passenger[i].activation != 0)
        {
            endGame = false;
        };
    };
    if (endGame)
    {
        cout << "111" << endl;
        levelMap.state = 5;
        cout << car.money << endl;
        cout << algoCar.money << endl;
        cout << userCar.money << endl;
        cout << userCar2.money << endl;
        if (!endMenu.texture.loadFromFile(".\\texture\\endMenu2.png"))
        {
            std::cout << "not texture endMenu2" << std::endl;
        };
        endMenu.sprite.setTexture(endMenu.texture);
    };

    collisionCarAndUserCar(userCar, endGame, car);
    if (endGame)
    {
        levelMap.state = 5;
        cout << "user1 lose" << endl;
        userCar.money = -1;
    };

    collisionCarAndUserCar(userCar, endGame, algoCar);
    if (endGame)
    {
        levelMap.state = 5;
        cout << "user1 lose" << endl;
        userCar.money = -1;
    };

    collisionCarAndUserCar(userCar2, endGame, car);
    if (endGame)
    {
        levelMap.state = 5;
        cout << "user2 lose" << endl;
        userCar2.money = -1;
    };

    collisionCarAndUserCar(userCar2, endGame, algoCar);
    if (endGame)
    {
        levelMap.state = 5;
        cout << "user2 lose" << endl;
        userCar2.money = -1;
    };

    collisionCarAndUserCar(userCar2, endGame, userCar);
    if (endGame)
    {
        levelMap.state = 5;
        cout << "everyone lose" << endl;
        userCar.money = -1;
        userCar2.money = -1;
    };
}