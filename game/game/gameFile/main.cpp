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
    cout << "main" << endl;
    constexpr unsigned WINDOW_WIDTH = 800;
    constexpr unsigned WINDOW_HEIGHT = 600;
    sf::Clock clock;
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}),
        "Arrow follows mouse", sf::Style::Default, settings);
    car car(clock);
    cout << "RenderWindow window" << endl;
    destination destination(clock);
    passenger passenger[100];
    mapStuct levelMap;
    sf::Vector2f mousePosition;
    sf::Vector2f mouseClikPosition;
    cout << "struct" << endl;
    initLevel(levelMap);
    initPassenger(passenger, levelMap);
    initDestination(destination);

    initCar(car, clock);
    cout << "init level" << endl;
    bool gogame = false;
    while (window.isOpen())
    {

        pollEvents(window, mousePosition, mouseClikPosition);
        cout << "pollEvents" << endl;
        update(mousePosition, mouseClikPosition, car, passenger, destination, levelMap, clock);
        cout << "update" << endl;
        redrawFrame(window, car, passenger, destination, levelMap);
        cout << "redrawFrame" << endl;
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
            cout << gogame << endl;
            window.close();
            cout << car.money << endl;
        };
    };
    cout << "end correct" << endl;
}