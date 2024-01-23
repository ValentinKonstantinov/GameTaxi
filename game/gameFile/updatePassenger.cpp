#include "declaration.hpp"

void updatePassenger(float time, obstruction arreyObstruction[], passenger passenger[])
{
    for (int i = 0; i < 10; ++i)
    {
        if (passenger[i].activation == 1)
        {
            passenger[i].timeDrive = passenger[i].timeDrive + time;
            if (passenger[i].drive.x > 0)
            {
                if (static_cast<int>(passenger[i].timeDrive) % 2 == 0)
                {
                    passenger[i].sprite.setTextureRect(sf::IntRect(90, 0, 30, 40));
                }
                else
                {
                    passenger[i].sprite.setTextureRect(sf::IntRect(121, 0, 30, 40));
                };
            }
            else
            {
                if (static_cast<int>(passenger[i].timeDrive) % 2 == 0)
                {
                    passenger[i].sprite.setTextureRect(sf::IntRect(30, 0, 30, 40));
                }
                else
                {
                    passenger[i].sprite.setTextureRect(sf::IntRect(0, 0, 29, 40));
                };
            };
            sf::Vector2f positionPassengerPrevious = passenger[i].position;
            if (static_cast<int>(passenger[i].timeDrive) % 10 < 8)
            {
                passenger[i].position = passenger[i].position + passenger[i].drive * time;
            }
            else
            {
                passenger[i].sprite.setTextureRect(sf::IntRect(60, 0, 30, 40));
            };
            collisionCheckInitPassenger(passenger[i], arreyObstruction);
            if ((passenger[i].collision != 1) && (passenger[i].counterCollision / 2 == 0))
            {
                passenger[i].position = positionPassengerPrevious;
                passenger[i].drive.x = -passenger[i].drive.x;
                passenger[i].position = passenger[i].position + passenger[i].drive * time;
                collisionCheckInitPassenger(passenger[i], arreyObstruction);
                if (passenger[i].collision != 1)
                {
                    passenger[i].position = positionPassengerPrevious;
                    passenger[i].drive.y = -passenger[i].drive.y;
                    passenger[i].position = passenger[i].position + passenger[i].drive * time;
                    ++passenger[i].counterCollision;
                };
            }
            else if ((passenger[i].collision != 1) && (passenger[i].counterCollision / 2 != 0))
            {
                passenger[i].position = positionPassengerPrevious;
                passenger[i].drive.y = -passenger[i].drive.y;
                passenger[i].position = passenger[i].position + passenger[i].drive * time;
                collisionCheckInitPassenger(passenger[i], arreyObstruction);
                if (passenger[i].collision != 1)
                {
                    passenger[i].position = positionPassengerPrevious;
                    passenger[i].drive.x = -passenger[i].drive.x;
                    passenger[i].position = passenger[i].position + passenger[i].drive * time;
                    ++passenger[i].counterCollision;
                };
            };
            ++passenger[i].counterCollision;
            passenger[i].sprite.setPosition(passenger[i].position);
        }
    }
}
