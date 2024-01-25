#include "declaration.hpp"
#include <iomanip>
#include <string>
#include <climits>
#include <iostream>

using namespace std;

void simplePathfindingAlgoritm(int ADJACENCY_MATRIX[][640], int &START, int &END, sf::Vector2i &targetDrive)
{
    int VERTICES = 640;
    bool visited[VERTICES];
    int distances[VERTICES];
    int minimalWeight, minimalIndex;

    for (int i = 0; i < VERTICES; ++i)
    {
        visited[i] = false;
        distances[i] = INT_MAX;
    }

    distances[START] = 1;

    do
    {
        minimalIndex = INT_MAX;
        minimalWeight = INT_MAX;

        for (int i = 0; i < VERTICES; ++i)
        {
            if (!visited[i] && distances[i] < minimalWeight)
            {
                minimalIndex = i;
                minimalWeight = distances[i];
            }
        }

        if (minimalIndex != INT_MAX)
        {
            for (int i = 0; i < VERTICES; ++i)
            {
                if (ADJACENCY_MATRIX[minimalIndex][i])
                {
                    int temp = minimalWeight + ADJACENCY_MATRIX[minimalIndex][i];

                    if (temp < distances[i])
                        distances[i] = temp;
                }
            }

            visited[minimalIndex] = true;
        }
    } while (minimalIndex < INT_MAX);

    int i = END;
    if (distances[i] != INT_MAX)
    {
        int end = i;
        int weight = distances[end];
        targetDrive.x = end % 32 * 25;
        targetDrive.y = end / 32 * 25 + 100;
        while (end != START)
        {
            for (int j = 0; j < VERTICES; ++j)
            {
                if (ADJACENCY_MATRIX[j][end])
                {
                    int temp = weight - ADJACENCY_MATRIX[j][end];

                    if (temp == distances[j])
                    {
                        end = j;
                        weight = temp;
                        if (START != j)
                        {
                            targetDrive.x = j % 32 * 25;
                            targetDrive.y = j / 32 * 25 + 100;
                        }
                    }
                }
            }
        };
    }
    else
    {
        //targetDrive.x = -1;
        /*   cout << "" << START << " ~ " << i << " = "
             << "no way" << endl;*/
    };
};

void algoDijkstra(sf::Vector2f end, sf::Vector2i &targetDrive, sf::Vector2f start)
{
    int x1 = end.x;
    int y1 = end.y - 100;
    int x2 = start.x;
    int y2 = start.y - 100;
    int END = x1 / 25 + (y1 / 25) * 32;   //цель
    int START = x2 / 25 + (y2 / 25) * 32; //car

    int VERTICES = 640;
    int ADJACENCY_MATRIX[640][640];

    int temp = 1;
    for (int i = 0; i < VERTICES; i++)
    {
        for (int j = 0; j < VERTICES; j++)
        {
            ADJACENCY_MATRIX[i][j] = 0;
        }
    };
    for (int k = 0; k < 20; ++k)
    {
        for (int i = 1; i <= 32; ++i)
        {
            if (i + 1 <= 32)
            {
                ADJACENCY_MATRIX[i + k * 32 - 1][i + k * 32 + 1 - 1] = temp;
                ADJACENCY_MATRIX[i + k * 32 + 1 - 1][i + k * 32 - 1] = temp;
            };
            if (i - 1 >= 1)
            {
                ADJACENCY_MATRIX[i + k * 32 - 1][i + k * 32 - 1 - 1] = temp;
                ADJACENCY_MATRIX[i + k * 32 - 1 - 1][i + k * 32 - 1] = temp;
            };
            if (k + 1 < 20)
            {
                ADJACENCY_MATRIX[i + k * 32 - 1][i + k * 32 + 32 - 1] = temp;
                ADJACENCY_MATRIX[i + k * 32 + 32 - 1][i + k * 32 - 1] = temp;
            };
            if (k - 1 >= 0)
            {
                ADJACENCY_MATRIX[i + k * 32 - 1][i + k * 32 - 32 - 1] = temp;
                ADJACENCY_MATRIX[i + k * 32 - 32 - 1][i + k * 32 - 1] = temp;
            };
        }
    };

    ifstream level1Obstruction;
    level1Obstruction.open(".\\level\\fileLevel1Obstruction.txt");

    temp = 0;
    do
    {
        int pozX, pozY, sizeX, sizeY;
        level1Obstruction >> sizeX >> sizeY >> pozX >> pozY;

        pozX = pozX / 25;
        pozY = pozY / 25;
        sizeX = sizeX / 25;
        sizeY = sizeY / 25;
        //  cout << pozX << pozY << sizeX << sizeY << endl;
        for (int i = pozX; i < pozX + sizeX; ++i)
        {
            for (int j = pozY; j < pozY + sizeY; ++j)
            {
                //  cout << i << ' ' << j << endl;
                if (i + 1 <= 32)
                {
                    ADJACENCY_MATRIX[i + j * 32 - 1][i + j * 32 + 1 - 1] = temp;
                    ADJACENCY_MATRIX[i + j * 32 + 1 - 1][i + j * 32 - 1] = temp;
                };
                if (i - 1 >= 1)
                {
                    ADJACENCY_MATRIX[i + j * 32 - 1][i + j * 32 - 1 - 1] = temp;
                    ADJACENCY_MATRIX[i + j * 32 - 1 - 1][i + j * 32 - 1] = temp;
                };
                if (j + 1 < 20)
                {
                    ADJACENCY_MATRIX[i + j * 32 - 1][i + j * 32 + 32 - 1] = temp;
                    ADJACENCY_MATRIX[i + j * 32 + 32 - 1][i + j * 32 - 1] = temp;
                };
                if (j - 1 >= 0)
                {
                    ADJACENCY_MATRIX[i + j * 32 - 1][i + j * 32 - 32 - 1] = temp;
                    ADJACENCY_MATRIX[i + j * 32 - 32 - 1][i + j * 32 - 1] = temp;
                };
            }
        };
    } while (!level1Obstruction.eof());
    level1Obstruction.close();

    simplePathfindingAlgoritm(ADJACENCY_MATRIX, START, END, targetDrive);
};