#pragma once 
#include <SFML/Graphics.hpp>

class Grid 
{
private: 
    sf::RectangleShape* m_hLine; // array of horizontal lines in the grid
    sf::RectangleShape* m_vLine; // array of vertical lines in the grid

    sf::Vector2f m_position;
    sf::Vector2i m_scale;         // for the scale of the whole grid
    sf::Vector2i m_totalCells;    // total tiles on the X and Y axis
    sf::Vector2i m_cellSize;      // a tile of 16px

    sf::Vector2i m_totalLines;    // total lines on the X and Y axis

     
    int m_lineThickness; 

public:
    Grid(const sf::Vector2i& totalCells);
    ~Grid();

    void Initialize(); 
    void Load(); 

    void Update(double deltaTime); 
    void Draw(sf::RenderWindow& window); 
};