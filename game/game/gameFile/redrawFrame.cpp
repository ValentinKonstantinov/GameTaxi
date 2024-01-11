#include "declaration.hpp"

void redrawFrame(sf::RenderWindow &window, car &car, passenger passenger[], destination &destination, mapStuct &levelMap)
{
    window.clear(sf::Color(255, 255, 255));
    //cout << " window clear" << endl;

    window.draw(levelMap.sprite);
    cout << " window.draw car" << endl;
    window.draw(destination.sprite);
    //cout << " window.draw" << endl;
    for (int i = 0; i < 30; ++i)
    {
        if (passenger[i].activation == 1)
        {

            window.draw(passenger[i].sprite);
        };
        //cout << "passenger draw " << endl;
    };
    //cout << "passengers draw" << endl;
    window.draw(car.sprite);
    window.display();
}