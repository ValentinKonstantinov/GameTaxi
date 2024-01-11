#include "declaration.hpp"

void update(const sf::Vector2f &mousePosition, sf::Vector2f &mouseClikPosition, car &car, passenger passenger[], destination &destination, mapStuct &levelMap, sf::Clock &clock)
{
    //passenger.sprite.setPosition(mouseClikPosition);
    // passenger.position = mouseClikPosition;
    sf::Vector2f delta;
    if (car.withAPassenger == 0)
    {
        int passengerNumber = 0;
        do
        {
            //passengerTarget = passenger[passengerNumber];
            ++passengerNumber;
        } while ((passenger[passengerNumber - 1].activation != 1) && (passengerNumber < 100));
        --passengerNumber;
        if (passengerNumber > 99)
        {
            cout << car.money << endl;
        };
        car.passengerMoney = passenger[passengerNumber].money;
        car.passengerNumber = passengerNumber;
        delta = passenger[passengerNumber].position - car.position;
    }
    else
    {
        delta = destination.position - car.position;
    }
    //car.rotation = atan2(delta.y, delta.x);

    //distance = delta.x * delta.x + delta.y * delta.y;
    //distance = sqrt(distance);

    updatecar(car, clock, delta, levelMap, passenger);
}