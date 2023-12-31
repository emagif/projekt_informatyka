#include "Grid.hpp"

Grid::Grid() : position(100,100), scale(5, 5), totalCells(10,5), cellSize(16, 16),lineThickness(2) // defining the values in the constructor
{
}

Grid::~Grid()
{

}

void Grid::Initialize()
{  
    // grid for 10 elements  
    // 16x16, 10x16=160

    int horizontalLineLength = totalCells.x * cellSize.x * scale.x; + lineThickness; // adding +lineThickness to fill the gap in the corner
    int verticalLineLength = totalCells.y * cellSize.y * scale.y;

    for(int i = 0; i < totalLinesY; i++)
    {
        hLine[i].setSize(sf::Vector2f(horizontalLineLength, lineThickness));
        hLine[i].setPosition(position + sf::Vector2f(0, i * cellSize.y * scale.y)); // draws a line every 16px on the Y axis
    }

     for(int i = 0; i < totalLinesX; i++)
    {
        vLine[i].setSize(sf::Vector2f(lineThickness, verticalLineLength));
        vLine[i].setPosition(position + sf::Vector2f(i * cellSize.x * scale.x, 0)); // draws a line every 16px on the X axis
    }
}

void Grid::Load()
{

}

void Grid::Update(double deltaTime)
{

}

void Grid::Draw(sf::RenderWindow &window)
{

    for(int i = 0; i < totalLinesY; i++) // + 1 in the iterator for the extreme bottom and extreme right lines to appear
    {
        window.draw(hLine[i]); // to draw the horizontal line
    }

    for(int i = 0; i < totalLinesX; i++)
    {
        window.draw(vLine[i]); // to draw the vertical line
    }

}
