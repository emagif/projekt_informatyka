#include "Grid.hpp"

Grid::Grid()
{
}

Grid::~Grid()
{

}

void Grid::Initialize()
{  
    // siatka na 10 elementów  
    // kafelka 16x16, 10x16=160

    sf::Vector2f position = sf::Vector2f(100, 100);

    int totalCellsX = 10;
    int totalCellsY = 5;


    int cellSizeX = 16;
    int cellSizeY = 16; 
    
    int horizontalLineThickness = 2;
    int horizontalLineLength = totalCellsX * cellSizeX;


    int verticalLineThickness = horizontalLineThickness;
    int verticalLineLength = totalCellsY * cellSizeY;

    hLine.setSize(sf::Vector2f(horizontalLineLength,horizontalLineThickness));
    hLine.setPosition(position);

    vLine.setSize(sf::Vector2f(verticalLineLength,verticalLineThickness));
    vLine.setPosition(position);
}

void Grid::Load()
{

}

void Grid::Update(double deltaTime)
{

}

void Grid::Draw(sf::RenderWindow &window)
{
    window.draw(hLine);
}
