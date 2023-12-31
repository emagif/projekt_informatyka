#include "Grid.hpp"

Grid::Grid()
{
}

Grid::~Grid()
{

}

void Grid::Initialize()
{  
    // grid for 10 elements  
    // 16x16, 10x16=160

    sf::Vector2f position = sf::Vector2f(100, 100);

    int scaleX = 5; // for the scale of the whole grid
    int scaleY = 5;

    int totalCellsX = 10; // total tiles on the X axis
    int totalCellsY = 5; //  total tiles on the Y axis

    int cellSizeX = 16; // a tile of 16px
    int cellSizeY = 16; 
    
    int lineThickness = 2; 
    int horizontalLineLength = totalCellsX * cellSizeX * scaleX;
    int verticalLineLength = totalCellsY * cellSizeY * scaleY;

    for(int i = 0; i < 5 + 1; i++)
    {
        hLine[i].setSize(sf::Vector2f(horizontalLineLength, lineThickness));
        hLine[i].setPosition(position + sf::Vector2f(0, i * cellSizeY * scaleY)); // draws a line every 16px on the Y axis
    }

     for(int i = 0; i < 10 + 1; i++)
    {
        vLine[i].setSize(sf::Vector2f(lineThickness, verticalLineLength));
        vLine[i].setPosition(position + sf::Vector2f(i * cellSizeX * scaleX, 0)); // draws a line every 16px on the X axis
    }

//     hLine.setSize(sf::Vector2f(horizontalLineLength, lineThickness));
//     hLine.setPosition(position);

//     vLine.setSize(sf::Vector2f(lineThickness, verticalLineLength));
//     vLine.setPosition(position);
}

void Grid::Load()
{

}

void Grid::Update(double deltaTime)
{

}

void Grid::Draw(sf::RenderWindow &window)
{

    for(int i = 0; i < 5 + 1; i++) // + 1 in the iterator for the extreme bottom and extreme right lines to appear
    {
        window.draw(hLine[i]); // to draw the horizontal line
    }

    for(int i = 0; i < 10 + 1; i++)
    {
        window.draw(vLine[i]); // to draw the vertical line
    }
//     window.draw(hLine); // to draw the horizontal line
//     window.draw(vLine); // to draw the vertical line
}
