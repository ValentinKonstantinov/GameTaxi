#include "declaration.hpp"

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
    car algoCar(clock);
    car userCar(clock);
    car userCar2(clock);
    car car(clock);

    sf::Font fontName;
    if (!fontName.loadFromFile(".\\font\\ArialRegular.ttf"))
    {
        cout << "no ArialRegular" << endl;
    };

    passenger passenger[100];
    levelMap levelMap;
    obstruction arreyObstruction[100];
    sf::Vector2f mousePosition;
    sf::Vector2f mouseClikPosition;
    menu previewMenu;
    menu endMenu;
    oilStruct oil;
    petrolStruct petrol;
    destination destination(clock);
    bool endGame;
    char keyPressed;
    while (window.isOpen())
    {
        if (levelMap.state == 0)
        {
            float time = clock.restart().asSeconds();
            initNewGame(endGame, previewMenu, endMenu, oil, petrol, levelMap, arreyObstruction, passenger, destination, userCar, userCar2, fontName, algoCar, car, window, mousePosition, mouseClikPosition, keyPressed, time);
        };

        if (levelMap.state == 3)
        {
            levelMap.state = 4;
            //воспроизводим музыку
        };
        if (levelMap.state == 4)
        {
            pollEvents(window, mousePosition, mouseClikPosition, keyPressed);
            update(algoCar, userCar, userCar2, mousePosition, mouseClikPosition, keyPressed, car, passenger, destination, arreyObstruction, clock, oil, petrol);
            redrawFrame(algoCar, userCar, userCar2, window, car, passenger, destination, levelMap, oil, petrol);
            checkEndGame(endGame, algoCar, userCar, userCar2, car, passenger, levelMap, endMenu);
        };
        if (levelMap.state == 5)
        {

            pollEventsMenu(window, mousePosition, mouseClikPosition, keyPressed);
            if (keyPressed == 'r')
            {
                levelMap.state = 0;
            };
            redrawFrameEndMenu(algoCar, userCar, userCar2, window, car, passenger, destination, levelMap, endMenu);
        };
    }
};