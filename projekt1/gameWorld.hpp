#pragma once 
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <sstream> 
#include <iomanip>
#include "tile.hpp"



class GameWorld
{
        sf::Vector2i exitPos;
        sf::Vector2i playerPos;
        std::vector<sf::Vector2i> enemyPositions;
        void setUpInitialState();
        void setUpEnemyPositions();
        void setUpTiles();
    
    
    public:
        std::vector<std::vector<GameTile* > >tiles;
        int gridLength;
        GameWorld();

     


};
