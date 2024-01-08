#include "declaration.hpp"

float distance = 0;

sf::Vector2f toEuclidean(float radius, float angle)
{
    return {
        static_cast<float>(radius * cos(angle)),
        static_cast<float>(radius * sin(angle))};
};

int main()
{
    constexpr unsigned WINDOW_WIDTH = 800;
    constexpr unsigned WINDOW_HEIGHT = 600;
    sf::Clock clock;
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}),
        "Arrow follows mouse", sf::Style::Default, settings);

    car car(clock);
    destination destination(clock);
    passenger passenger[100];
    obstruction arreyObstruction[100];
    sf::Vector2f mousePosition;
    sf::Vector2f mouseClikPosition;
    initLevel(arreyObstruction);
    initPassenger(passenger, arreyObstruction);
    initDestination(destination);

    initCar(car, clock);
    bool gogame = false;
    while (window.isOpen())
    {
        pollEvents(window, mousePosition, mouseClikPosition);
        update(mousePosition, mouseClikPosition, car, passenger, destination, arreyObstruction, clock);
        redrawFrame(window, car, passenger, destination, arreyObstruction);
        bool gogame = false;
        for (int i = 0; i < 100; ++i)
        {
            if (passenger[i].activation != 0)
            {
                gogame = true;
            };
        };
        if (!gogame)
        {
            window.close();
            cout << car.money << endl;
        }
    };
}