#pragma once 
#include <SFML/Graphics.hpp>

class Grid 
{
private: 
    sf::RectangleShape hLine[5 + 1]; // array of horizontal lines in the grid
    sf::RectangleShape vLine[10 + 1]; // array of vertical lines in the grid

public:
    Grid();
    ~Grid();

    void Initialize(); //wywoływane raz
    void Load(); //wywoływane raz

    void Update(double deltaTime); //wywoływane raz na klatkę
    void Draw(sf::RenderWindow& window); //wywoływane raz na klatkę
};