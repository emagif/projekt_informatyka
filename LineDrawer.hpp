#pragma once
#include <SFML/Graphics.hpp>

class LineDrawer : public sf::Drawable
{
private: 
    std::vector<sf::VertexArray> m_lines;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        for(const auto& m_line : m_lines)
        {
            target.draw(m_line, states);
        }
    }


public: 
    LineDrawer();
    void addLine(const sf::Vector2f& pointA, const sf::Vector2f& pointB, sf::Color color);
};