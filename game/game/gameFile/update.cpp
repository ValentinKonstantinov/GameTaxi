#include "declaration.hpp"

void update(car &userCar, const sf::Vector2f &mousePosition, sf::Vector2f &mouseClikPosition, char &keyPressed, car &car, passenger passenger[], destination &destination, obstruction arreyObstruction[], sf::Clock &clock, oilStruct &oil)
{
    float time = clock.restart().asSeconds();
    userCar.keyPressed = keyPressed;
    sf::Vector2f delta;
    std::string str;
    if (car.withAPassenger == 0)
    {
        int passengerNumber = 0;
        do
        {
            ++passengerNumber;
        } while ((passenger[passengerNumber - 1].activation != 1) && (passengerNumber < 100));
        --passengerNumber;
        delta = passenger[passengerNumber].position - car.position;
        if ((fabs(round(delta.x)) <= 50) && (fabs(round(delta.y)) <= 50))
        {
            car.passengerMoney = passenger[passengerNumber].money;
            car.passengerNumber = passengerNumber;
            car.withAPassenger = 1;
            passenger[car.passengerNumber].activation = 2;
        };
    }
    else
    {
        delta = destination.position - car.position;
        if ((fabs(round(delta.x)) <= 60) && (fabs(round(delta.y)) <= 60))
        {
            car.money = car.money + car.passengerMoney;
            car.passengerMoney = 0;
            passenger[car.passengerNumber].activation = 0;
            car.withAPassenger = 0;
        };
    };
    str = std::to_string(car.money);
    str = "stupid:" + str + "$";
    if (car.availabilityOil == 1)
    {
        str = str + " OIL";
    };
    car.name.setString(str);

    updatecar(car, time, delta, arreyObstruction, passenger);

    if (userCar.withAPassenger == 0)
    {
        int passengerNumber = 0;
        do
        {
            if (passenger[passengerNumber].activation == 1)
            {
                delta = passenger[passengerNumber].position - userCar.position;
                if ((fabs(round(delta.x)) <= 40) && (fabs(round(delta.y)) <= 40))
                {
                    userCar.withAPassenger = 1;
                    userCar.passengerMoney = passenger[passengerNumber].money;
                    userCar.passengerNumber = passengerNumber;
                    if (userCar.passengerMoney > 30)
                    {
                        userCar.sprite.setColor(sf::Color::Red);
                    }
                    else
                    {
                        userCar.sprite.setColor(sf::Color::Green);
                    };
                    passenger[userCar.passengerNumber].activation = 2;
                }
            }
            ++passengerNumber;
        } while ((userCar.withAPassenger == 0) && (passengerNumber < 100));
    }
    else if (userCar.withAPassenger == 1)
    {
        delta = destination.position - userCar.position;
        if ((fabs(round(delta.x)) <= 50) && (fabs(round(delta.y)) <= 50))
        {
            userCar.money = userCar.money + userCar.passengerMoney;
            userCar.passengerMoney = 0;
            passenger[userCar.passengerNumber].activation = 0;
            userCar.withAPassenger = 0;
            userCar.sprite.setColor(sf::Color(250, 235, 215));

            str = std::to_string(userCar.money);
            str = "user:" + str + "$";
        };
    };
    str = std::to_string(userCar.money);
    str = "user:" + str + "$";
    if (userCar.availabilityOil == 1)
    {
        str = str + " OIL";
    };
    userCar.name.setString(str);

    updateDestination(time, destination);
    updateUserCar(userCar, time, keyPressed, arreyObstruction, passenger);
    updatePassenger(time, arreyObstruction, passenger);
    udateOil(userCar, oil, car, arreyObstruction, time);
};