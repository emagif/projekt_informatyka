#pragma once
#include <SFML/Graphics.hpp>
#include "LineDrawer.hpp"
#include "Player1.hpp"

class CheckCollision
{
private: 
    std::vector<sf::RectangleShape>& m_rectangles;

public:
    CheckCollision(std::vector<sf::RectangleShape>& rectangles);
    void checkCollision(const sf::RectangleShape& rectangle, double deltaTime, Player1& player);
};