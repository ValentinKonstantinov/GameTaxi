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
    car userCar(clock);
    car car(clock);
    sf::Font fontName;
    if (!fontName.loadFromFile(".\\font\\ArialRegular.ttf"))
    {
        cout << "no ArialRegular" << endl;
    }
    destination destination(clock);
    passenger passenger[100];
    levelMap levelMap;
    obstruction arreyObstruction[100];
    sf::Vector2f mousePosition;
    sf::Vector2f mouseClikPosition;
    char keyPressed;
    oilStruct oil;
    initOilStruct(oil);
    initLevel(levelMap, arreyObstruction);
    initPassenger(passenger, arreyObstruction);
    initDestination(destination);
    initUserCar(userCar, fontName);
    initCar(car, fontName);

    bool endGame = false;
    while (window.isOpen())
    {
        pollEvents(window, mousePosition, mouseClikPosition, keyPressed);
        update(userCar, mousePosition, mouseClikPosition, keyPressed, car, passenger, destination, arreyObstruction, clock, oil);
        redrawFrame(userCar, window, car, passenger, destination, levelMap, oil);
        endGame = true;
        for (int i = 0; i < 100; ++i)
        {
            if (passenger[i].activation != 0)
            {
                endGame = false;
            };
        };
        collisionCarAndUserCar(userCar, endGame, car);
        if (endGame)
        {
            window.close();
            cout << car.money << endl;
            cout << userCar.money << endl;
        }
    };
}