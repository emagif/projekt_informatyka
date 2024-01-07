#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Points
{
private: 
    sf::Text m_text;
    sf::Font m_font;

public:
    sf::Time m_score;
    
    Points();
    void IncreaseScore(sf::Clock clock);
    void UpdateText();
    void SetPosition(float x, float y);
    void Draw(sf::RenderWindow& window);
};