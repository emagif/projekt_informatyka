#include "DrawRectangles.hpp"

DrawRectangles::DrawRectangles() : m_rectangles(0)
{
}

void DrawRectangles::addRectangle(float x, float y, float sizeX, float sizeY, sf::Color color)
{
    sf::RectangleShape rectangle(sf::Vector2f(sizeX, sizeY));
    rectangle.setPosition(x, y);
    rectangle.setFillColor(color);
    m_rectangles.push_back(rectangle);
}

void DrawRectangles::Draw(sf::RenderWindow& window)
{
    for(int i = 0; i < m_rectangles.size(); i++)
    {
        window.draw(m_rectangles[i]);
    }
}
