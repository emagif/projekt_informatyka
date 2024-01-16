#include "Points.hpp"

Points::Points() : m_score(sf::Time::Zero)
{
    if(!m_font.loadFromFile("font/font.ttf"))
    {
        std::cout<<"The programmer did something wrong, cannot load the file"<<std::endl;
    }

    m_text.setFont(m_font);
    m_text.setCharacterSize(20);
    m_text.setFillColor(sf::Color::White);
}

void Points::IncreaseScore(sf::Clock clock)
{
    sf::Time deltaTime = clock.getElapsedTime();
    // clock.restart();
    m_score +=deltaTime;
    UpdateText();
}

void Points::UpdateText()
{
    int seconds = static_cast<int>(m_score.asSeconds());
    int minutes = seconds / 60;
    seconds %= 60;

    std::string timeText = "Points: " + std::to_string(seconds);
    m_text.setString(timeText);
}

void Points::SetPosition(float x, float y)
{
    m_text.setPosition(x, y);
}

void Points::Draw(sf::RenderWindow& window)
{
    window.draw(m_text);
}

