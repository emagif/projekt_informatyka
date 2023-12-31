#pragma once 
#include <SFML/Graphics.hpp>

#define totalLinesX 10 + 1
#define totalLinesY 5 + 1


class Grid 
{
private: 
    sf::RectangleShape hLine[5 + 1]; // array of horizontal lines in the grid
    sf::RectangleShape vLine[10 + 1]; // array of vertical lines in the grid

    sf::Vector2f position;
    sf::Vector2i scale; // for the scale of the whole grid
    sf::Vector2i totalCells; // total tiles on the X and Y axis
    sf::Vector2i cellSize; // a tile of 16px
     
    int lineThickness; 

public:
    Grid();
    ~Grid();

    void Initialize(); 
    void Load(); 

    void Update(double deltaTime); 
    void Draw(sf::RenderWindow& window); 
};