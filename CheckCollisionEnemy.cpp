#include "CheckCollisionEnemy.hpp"
#include <iostream>
#include <unistd.h>
#include <fstream>

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

void CheckCollisionEnemy::checkCollisionBetweenPlayerAndEnemy(Player1& player, double deltaTime, Enemy& enemy, sf::RenderWindow& window, sf::Clock& clock, Points& points)
{
    if(player.m_sprite.getGlobalBounds().intersects(enemy.sprite.getGlobalBounds()))
    {
        std::ofstream scoreFile("ScoreFile.rmap");

        if(scoreFile.is_open())
        {
            scoreFile << "Final score: "<< static_cast<int>(points.m_score.asSeconds());
            scoreFile.close();
        }



        sf::Time elapsedTime = clock.getElapsedTime();
        if(!m_font.loadFromFile("/home/emmanuel/Pulpit/projekt_informatyka/font/font.ttf")) // loads the font 
        {
            std::cout<<"Programmer did something wrong :("<<std::endl;
        }
        
        m_text.setFont(m_font);
        m_text.setString("GAME OVER! YOU LOST");
        m_text.setCharacterSize(60);
        m_text.setFillColor(sf::Color::White);
        m_text.setPosition(350, 450);
        window.draw(m_text);
        window.display();
        sleep(6); // puts game to sleep for 6 seconds and then closes the window

        window.close();
    }
}