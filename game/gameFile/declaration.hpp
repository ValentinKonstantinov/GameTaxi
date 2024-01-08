#pragma once

void redrawFrame(sf::RenderWindow &window, car &car, passenger &passenger, destination &destination, obstruction arreyObstruction[]);
void update(const sf::Vector2f &mousePosition, sf::Vector2f &mouseClikPosition, car &car, passenger &passenger, destination &destination, obstruction arreyObstruction[], sf::Clock &clock);
void pollEvents(sf::RenderWindow &window, sf ::Vector2f &mousePosition, sf ::Vector2f &mouseClikPosition);
void initDestination(destination &destination);
void initLevel(obstruction arreyObstruction[]);
void initPassenger(passenger &passenger);
void initCar(car &car, sf::Clock &clock);
void onMouseMove(const sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePosition);
void onMouseClick(const sf::Event::MouseButtonEvent &event, sf::Vector2f &mouseClikPosition);
void updatecar(car &car, sf::Clock &clock, sf::Vector2f &delta, obstruction arreyObstruction[]);
void collisionCheck(car &car, obstruction arreyObstruction[]);
void goCarToTheLeft(car &car, float T);
void goCarToTheRight(car &car, float T);
void goCarToTheUp(car &car, float T);
void goCarToTheDown(car &car, float T);