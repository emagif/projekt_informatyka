#include "CheckCollisionEnemy.hpp"
#include <iostream>

CheckCollisionEnemy::CheckCollisionEnemy(std::vector<sf::RectangleShape>& rectangles) : m_rectangles(rectangles)
{
}

void CheckCollisionEnemy::checkCollision(const sf::RectangleShape& rectangle, double deltaTime, Enemy& enemy)
{
    sf::FloatRect rectBounds = rectangle.getGlobalBounds();
    sf::Vector2f enemyPos = enemy.sprite.getPosition();
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
                    enemyPos.x -= minOverlapX;
                }
                else
                {
                    enemyPos.x += minOverlapX;
                }
            }

            else
            {
                if(fromTop) // checks for collision on the Y axis
                {
                    enemyPos.y -= minOverlapY;
                }

                else
                {
                    enemyPos.y +=minOverlapY;
                }
            }
        }
    }
    enemy.sprite.setPosition(enemyPos);
}

void CheckCollisionEnemy::checkCollisionBetweenPlayerAndEnemy(Player1& player, double deltaTime, Enemy& enemy)
{
    if(player.m_sprite.getGlobalBounds().intersects(enemy.sprite.getGlobalBounds()))
    {
        std::cout<<"Collision"<<std::endl;
    }
}