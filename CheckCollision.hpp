#pragma once
#include <SFML/Graphics.hpp>
#include "LineDrawer.hpp"
#include "Player.hpp"

class CheckCollision
{
public:
    CheckCollision();
    bool areRectAndLineIntersecting(const sf::RectangleShape& rect, const std::vector<sf::VertexArray>& lines) const;
};