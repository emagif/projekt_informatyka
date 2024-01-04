#pragma once
#include <SFML/Graphics.hpp>

class DrawRectangles
{
private:
    std::vector<sf::RectangleShape> m_rectangles;

public:     
    DrawRectangles();
    void addRectangle(float x, float y, float sizeX, float sizeY, sf::Color color); 
    void Draw(sf::RenderWindow& window);

};