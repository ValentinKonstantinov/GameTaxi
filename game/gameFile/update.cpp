#include "declaration.hpp"

void update(car &algoCar, car &userCar, car &userCar2, const sf::Vector2f &mousePosition, sf::Vector2f &mouseClikPosition, char &keyPressed, car &car, passenger passenger[], destination &destination, obstruction arreyObstruction[], sf::Clock &clock, oilStruct &oil, petrolStruct &petrol)
{
    float time = clock.restart().asSeconds();
    if ((keyPressed == 'W') || (keyPressed == 'D') || (keyPressed == 'S') || (keyPressed == 'A') || (keyPressed == 'F'))
    {
        userCar.keyPressed = keyPressed;
    }
    else if ((keyPressed == 'U') || (keyPressed == 'K') || (keyPressed == 'J') || (keyPressed == 'H') || (keyPressed == 'L'))
    {
        userCar2.keyPressed = keyPressed;
    };

    sf::Vector2f delta;
    sf::Vector2i targetDrive;
    algoCarLogica(algoCar, targetDrive, passenger, destination, oil, arreyObstruction);
    updateAlgoCar(algoCar, time, targetDrive, passenger, arreyObstruction);
    carLogica(car, delta, passenger, destination);
    updatecar(car, time, delta, arreyObstruction, passenger);
    userCarLogica(userCar, passenger, destination);
    userCarLogica(userCar2, passenger, destination);
    updateDestination(time, destination);
    updateUserCar(userCar, userCar2, time, keyPressed, arreyObstruction, passenger);
    updatePassenger(time, arreyObstruction, passenger);
    udateOil(algoCar, userCar, userCar2, oil, car, arreyObstruction, time);
    udatePetrol(algoCar, userCar, userCar2, petrol, car, arreyObstruction, time);
};