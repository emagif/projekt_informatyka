#pragma once 
#include <SFML/Graphics.hpp>

class Grid 
{
private: 
    sf::RectangleShape hLine;
    sf::RectangleShape vLine;




public:
    Grid();
    ~Grid();

    void Initialize(); //wywoływane raz
    void Load(); //wywoływane raz

    void Update(double deltaTime); //wywoływane raz na klatkę
    void Draw(sf::RenderWindow& window); //wywoływane raz na klatkę
};