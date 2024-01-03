#include "LineDrawer.hpp"
#include <vector>

LineDrawer::LineDrawer()
{
}

void LineDrawer::addLine(const sf::Vector2f& pointA, const sf::Vector2f& pointB, sf::Color color)
{
    sf::VertexArray m_line(sf::Lines, 2);
    m_line[0].position = pointA;
    m_line[0].color = color;
    m_line[1].position = pointB;
    m_line[1].color = color;

    m_lines.push_back(m_line);
}