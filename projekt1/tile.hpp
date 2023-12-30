#pragma once
#include <iostream> 
#include <iomanip>
#include <vector>
#include <SFML/Graphics.hpp>


class GameTile
{
    public:         
    bool isPassable;
    bool isExit;

    sf::Vector2f position;
    sf::Texture texture;
    sf::Sprite sprite;

    GameTile(std::string,float, float, bool, bool);
    bool setUpSprite(std::string);
};