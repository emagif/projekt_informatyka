#include "CheckCollision.hpp"
#include <iostream>

CheckCollision::CheckCollision(std::vector<sf::RectangleShape>& rectangles) : m_rectangles(rectangles)
{
}

void CheckCollision::checkCollision(const sf::RectangleShape& rectangle, double deltaTime, Player1& player)
{
    sf::FloatRect rectBounds = rectangle.getGlobalBounds();
    sf::Vector2f playerPos = player.m_sprite.getPosition();
    for (const auto& otherRect : m_rectangles)
    {
        sf::FloatRect otherBounds = otherRect.getGlobalBounds();

        if(rectBounds.intersects(otherBounds))
        {
            float overlapLeft = otherBounds.left + otherBounds.width - rectBounds.left;
            float overlapRight = rectBounds.left + rectBounds.width - otherBounds.left;
            float overlapTop = otherBounds.top + otherBounds.height - rectBounds.top;
            float overlapBottom = rectBounds.top + rectBounds.height - otherBounds.top;

            bool fromLeft = overlapRight < overlapLeft;
            bool fromTop = overlapBottom < overlapTop;

            float minOverlapX = std::min(overlapLeft, overlapRight);
            float minOverlapY = std::min(overlapTop, overlapBottom);

            if(minOverlapX < minOverlapY)
            {
                if(fromLeft) // checks for collision on the X axis
                {
                    playerPos.x -= minOverlapX;
                }
                else
                {
                    playerPos.x += minOverlapX;
                }
            }

            else
            {
                if(fromTop) // checks for collision on the Y axis
                {
                    playerPos.y -= minOverlapY;
                }

                else
                {
                    playerPos.y +=minOverlapY;
                }
            }
        }
    }
    player.m_sprite.setPosition(playerPos);
}