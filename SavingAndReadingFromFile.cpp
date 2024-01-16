#include "SavingAndReadingFromFile.hpp"

SavingAndReadingFromFile::SavingAndReadingFromFile()
{
}

void SavingAndReadingFromFile::SaveToFile(sf::RenderWindow& window, Points& points, Player1& player, sf::Event& event)
{
    while(window.pollEvent(event))
    {
        if(event.type == sf::Event::KeyPressed)
        {
            if(event.key.code == sf::Keyboard::K)
            {
                std::ofstream scoreFileAppend("PointsDuringGame.rmap", std::ios::app);
                if(scoreFileAppend.is_open())
                {
                    scoreFileAppend<<"Current amount of points: "<<static_cast<int>(points.m_score.asSeconds())<<std::endl;
                    scoreFileAppend<<"Current Player position: " << (player.m_sprite.getPosition().x) << " , "<<(player.m_sprite.getPosition().y)<<std::endl;
                    scoreFileAppend<<std::endl;
                    scoreFileAppend.close();
                }
            }
        }
    }
}

void SavingAndReadingFromFile::ReadFromFile(sf::RenderWindow& window)
{
}