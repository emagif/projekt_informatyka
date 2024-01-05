#pragma once 
#include <SFML/Graphics.hpp>
#include "Enemy.hpp"
#include "Player1.hpp"

class CheckCollisionEnemy
{
private: 
    std::vector<sf::RectangleShape>& m_rectangles;

public: 
    CheckCollisionEnemy(std::vector<sf::RectangleShape>& rectangles);
    void checkCollision(const sf::RectangleShape& rectangle, double deltaTime, Enemy& enemy);
    void checkCollisionBetweenPlayerAndEnemy(Player1& player, double deltaTime, Enemy& enemy);

};