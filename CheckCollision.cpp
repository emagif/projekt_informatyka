#include "CheckCollision.hpp"
#include <iostream>

CheckCollision::CheckCollision(std::vector<sf::RectangleShape>& rectangles) : m_rectangles(rectangles)
{
}

void CheckCollision::checkCollision(const sf::RectangleShape& rectangle, double deltaTime, Player1& player)
{
    for (const auto& otherRect : m_rectangles)
    {
        if(rectangle.getGlobalBounds().intersects(otherRect.getGlobalBounds()))
        {

            sf::Vector2f position = player.m_sprite.getPosition();
            std::cout<<"True"<<std::endl;
            player.m_sprite.setPosition(position + sf::Vector2f(-3,0));
        }
    }
}