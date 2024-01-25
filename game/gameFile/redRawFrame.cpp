#include "declaration.hpp"

void redrawFrame(car &algoCar, car &userCar, car &userCar2, sf::RenderWindow &window, car &car, passenger passenger[], destination &destination, levelMap &levelMap, oilStruct &oil, petrolStruct &petrol)
{
    window.clear(sf::Color(255, 255, 255));
    window.draw(car.menuText);
    window.draw(algoCar.menuText);
    window.draw(userCar.menuText);
    if (userCar2.activation)
    {
        window.draw(userCar2.menuText);
    };

    window.draw(levelMap.sprite);
    window.draw(destination.sprite);
    for (int i = 0; i < 30; ++i)
    {
        if (passenger[i].activation == 1)
        {
            window.draw(passenger[i].sprite);
        }
    };
    if ((oil.activation == 1) || (oil.activation == 3))
    {
        window.draw(oil.sprite);
    };
    if (petrol.activation == 1)
    {
        window.draw(petrol.sprite);
    };
    window.draw(car.sprite);
    window.draw(algoCar.sprite);
    window.draw(userCar.sprite);
    if (userCar2.activation)
    {
        window.draw(userCar2.sprite);
    };

    window.display();
    //  window.draw(arrow.ellipseInternal);
};
void redrawFrameEndMenu(car &algoCar, car &userCar, car &userCar2, sf::RenderWindow &window, car &car, passenger passenger[], destination &destination, levelMap &levelMap, menu &endMenu)
{
    window.clear(sf::Color(255, 255, 255));
    window.draw(car.menuText);
    window.draw(algoCar.menuText);
    window.draw(userCar.menuText);
    if (userCar2.activation)
    {
        window.draw(userCar2.menuText);
    };
    window.draw(endMenu.sprite);
    sf::Font fontName;
    if (!fontName.loadFromFile(".\\font\\ArialRegular.ttf"))
    {
        cout << "no ArialRegular" << endl;
    };
    sf::Text textEnd;
    textEnd.setFont(fontName);
    textEnd.setCharacterSize(50);
    textEnd.setStyle(sf::Text::Bold);
    textEnd.setFillColor(sf::Color::Red);
    textEnd.setPosition(50, 500);
    std::string str = "";

    if ((userCar.money < 0) && (userCar2.money < 0))
    {
        str = "Users LOSE ";
    }
    else if ((userCar.money < userCar2.money) && (car.money < userCar2.money) && (algoCar.money < userCar2.money))
    {
        str = std::to_string(userCar2.money);
        str = "User 2 WINS: " + str + "$";
    }
    else if ((userCar2.money < userCar.money) && (car.money < userCar.money) && (algoCar.money < userCar.money))
    {
        str = std::to_string(userCar.money);
        str = "User 1 WINS: " + str + "$";
    }
    else if ((userCar.money < car.money) && (userCar2.money < car.money) && (algoCar.money < car.money))
    {
        str = std::to_string(car.money);
        str = "hardWorkingTaxi WINS: " + str + "$";
    }
    else
    {
        str = std::to_string(algoCar.money);
        str = "smartTaxi WINS: " + str + "$";
    };

    textEnd.setString(str);
    window.draw(textEnd);
    window.display();
};