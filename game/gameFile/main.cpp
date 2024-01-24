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
    car algoCar(clock);
    car userCar(clock);
    car userCar2(clock);
    car car(clock);

    sf::Font fontName;
    if (!fontName.loadFromFile(".\\font\\ArialRegular.ttf"))
    {
        cout << "no ArialRegular" << endl;
    };
    destination destination(clock);
    passenger passenger[100];
    levelMap levelMap;
    obstruction arreyObstruction[100];
    sf::Vector2f mousePosition;
    sf::Vector2f mouseClikPosition;
    menu previewMenu;

    oilStruct oil;
    initPreviewMenu(previewMenu);
    initOilStruct(oil);
    initLevel(levelMap, arreyObstruction);
    initPassenger(passenger, arreyObstruction);
    initDestination(destination);
    initUserCar(userCar, fontName);
    userCar.speed += 20;
    userCar.userName = "user1";
    userCar.menuText.setString(userCar.userName);
    initUserCar(userCar2, fontName);
    userCar2.speed += 20;
    userCar2.userName = "user2";
    userCar2.menuText.setString(userCar2.userName);
    userCar2.menuText.setPosition(400, 40);
    initCar(car, fontName);
    initCar(algoCar, fontName);
    algoCar.menuText.setString("algoCar");
    algoCar.menuText.setPosition(400, 0);
    bool endGame = false;
    /*
    sf::Music music; //создаем объект музыки
    if (!music.openFromFile("taxi.ogg"))
    {
        cout << "no music file" << endl;
    };
    //загружаем файл
    /* music.setPosition(0, 1, 10); // change its 3D position
    music.setPitch(2);           // increase the pitch
    music.setVolume(50);         // reduce the volume
    music.setLoop(true);
    music.play();*/
    /*std::string str = "";
    sf::Text userCarName1;
    userCarName1.setFont(fontName);
    userCarName1.setCharacterSize(30);
    userCarName1.setStyle(sf::Text::Bold);
    userCarName1.setFillColor(sf::Color::Red);
    userCarName1.setPosition(100, 340);
    sf::Text userCarName2;
    userCarName1.setFont(fontName);
    userCarName2.setCharacterSize(30);
    userCarName2.setStyle(sf::Text::Bold);
    userCarName2.setFillColor(sf::Color::Red);
    userCarName2.setPosition(100, 440);*/
    while (window.isOpen())
    {
        /* if (levelMap.state == 0)
        {
            char keyPressed;
            window.clear(sf::Color(255, 255, 255));
            window.draw(previewMenu.sprite);
            pollEventsMenu(window, mousePosition, mouseClikPosition, keyPressed);
            if (keyPressed != '1')
            {
                str = str + keyPressed;
                //userCarName1.setString(str);
            }
            else
            {
                userCar.userName = str;
                str = ' ';
                levelMap.state = 1;
            };
            window.draw(userCarName1);
            window.display();
        };
        if (levelMap.state == 1)
        {
            char keyPressed;
            window.clear(sf::Color(255, 255, 255));
            window.draw(previewMenu.sprite);
            pollEventsMenu(window, mousePosition, mouseClikPosition, keyPressed);
            if (keyPressed != '1')
            {
                str = str + keyPressed;
                //userCarName2.setString(str);
            }
            else
            {
                userCar.userName = str;
                str = ' ';
                levelMap.state = 3;
            };
            window.draw(userCarName1);
            window.draw(userCarName2);
            window.display();
        };*/
        if (levelMap.state == 0)
        {
            char keyPressed;
            pollEventsMenu(window, mousePosition, mouseClikPosition, keyPressed);
            if (keyPressed == 's')
            {
                userCar2.activation = false;
                levelMap.state = 3;
            }
            else if (keyPressed == 'q')
            {
                levelMap.state = 3;
            };
            window.clear(sf::Color(255, 255, 255));
            window.draw(previewMenu.sprite);
            window.display();
            float time = clock.restart().asSeconds();
        };
        if (levelMap.state == 3)
        {
            levelMap.state = 4;
            //воспроизводим музыку
        };
        if (levelMap.state == 4)
        {
            char keyPressed;
            pollEvents(window, mousePosition, mouseClikPosition, keyPressed);
            update(algoCar, userCar, userCar2, mousePosition, mouseClikPosition, keyPressed, car, passenger, destination, arreyObstruction, clock, oil);
            redrawFrame(algoCar, userCar, userCar2, window, car, passenger, destination, levelMap, oil);

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
                window.close();
                cout << car.money << endl;
                cout << algoCar.money << endl;
                cout << userCar.money << endl;
                cout << userCar2.money << endl;
            };
            endGame = false;
            collisionCarAndUserCar(userCar, endGame, car);
            if (endGame)
            {
                window.close();
                cout << "user1 lose" << endl;
            };
            endGame = false;
            collisionCarAndUserCar(userCar, endGame, algoCar);
            if (endGame)
            {
                window.close();
                cout << "user1 lose" << endl;
            };
            endGame = false;
            collisionCarAndUserCar(userCar2, endGame, car);
            if (endGame)
            {
                window.close();
                cout << "user2 lose" << endl;
            };
            endGame = false;
            collisionCarAndUserCar(userCar2, endGame, algoCar);
            if (endGame)
            {
                window.close();
                cout << "user2 lose" << endl;
            };
            endGame = false;
            collisionCarAndUserCar(userCar2, endGame, userCar);
            if (endGame)
            {
                window.close();
                cout << "everyone lose" << endl;
            };
        };
    }
};