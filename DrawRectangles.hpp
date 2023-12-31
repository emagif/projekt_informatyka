#pragma once
#include <SFML/Graphics.hpp>

class DrawRectangles
{
private:

public:     
    std::vector<sf::RectangleShape> m_rectangles;
    DrawRectangles();
    void addRectangle(float x, float y, float sizeX, float sizeY, sf::Color color); 
    void Draw(sf::RenderWindow& window);

};