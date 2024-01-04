#include "CheckCollision.hpp"

CheckCollision::CheckCollision()
{
    
}

bool CheckCollision::areRectAndLineIntersecting(const sf::RectangleShape& rect, const std::vector<sf::VertexArray>& lines) const
{
    sf::FloatRect rectBounds = rect.getGlobalBounds();

    for (const auto& line : lines)
    {
        for (int i = 0; i < line.getVertexCount() - 1; ++i)
        {
            sf::Vector2f p1 = line[i].position;
            sf::Vector2f p2 = line[i + 1].position;

            sf::FloatRect lineBounds = sf::FloatRect(p1.x, p1.y, p2.x - p1.x, p2.y - p1.y);

            if(rectBounds.intersects(lineBounds))
            {
                return true;
            }
        }
    }
    return false;
}