#include "Grid.hpp"

Grid::Grid(const sf::Vector2f& position, const sf::Vector2i& totalCells, const sf::Vector2i& cellSize, const sf::Vector2i& scale, const sf::Color& color, int lineThickness) : m_position(position), m_scale(scale), m_totalCells(totalCells), m_cellSize(cellSize), m_lineThickness(lineThickness), m_color(color) // defining the values in the constructor
{
    m_totalLines = sf::Vector2i(totalCells.x + 1,totalCells.y + 1); // amount of total lines +1 in every dimension

    m_hLine = new sf::RectangleShape[m_totalLines.y];
    m_vLine = new sf::RectangleShape[m_totalLines.x];
}

Grid::~Grid()
{
    delete[] m_hLine;
    delete[] m_vLine;
}

void Grid::Initialize()
{  
    // grid for 10 elements
    // 16x16, 10x16=160

    int horizontalLineLength = m_totalCells.x * m_cellSize.x * m_scale.x;
    int verticalLineLength = m_totalCells.y * m_cellSize.y * m_scale.y + m_lineThickness;   // adding +lineThickness to fill the gap in the corner

    for(int i = 0; i < m_totalLines.y; i++)
    {
        m_hLine[i].setSize(sf::Vector2f(horizontalLineLength, m_lineThickness));
        m_hLine[i].setPosition(m_position + sf::Vector2f(0, i * m_cellSize.y * m_scale.y)); // draws a line every 16px on the Y axis
        m_hLine[i].setFillColor(m_color);
    }

     for(int i = 0; i < m_totalLines.x; i++)
    {
        m_vLine[i].setSize(sf::Vector2f(m_lineThickness, verticalLineLength));
        m_vLine[i].setPosition(m_position + sf::Vector2f(i * m_cellSize.x * m_scale.x, 0)); // draws a line every 16px on the X axis
        m_vLine[i].setFillColor(m_color);
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

    for(int i = 0; i < m_totalLines.y; i++)    // + 1 in the iterator for the extreme bottom and extreme right lines to appear
    {
        window.draw(m_hLine[i]);              // to draw the horizontal line
    }

    for(int i = 0; i < m_totalLines.x; i++)
    {
        window.draw(m_vLine[i]);              // to draw the vertical line
    }

}
