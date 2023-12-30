// implementation file with base sprite :)
#include "tile.hpp"
#include <iostream> 
#include <iomanip>
#include <vector>
#include <SFML/Graphics.hpp>


GameTile::GameTile(std::string textureName, float x, float y, bool passable, bool exit)
{
if(!setUpSprite(textureName))
{
    return;
}
position = sf::Vector2f(x,y);
sprite.setPosition(position);
isPassable = passable;
isExit = exit;
}

bool GameTile::setUpSprite(std::string textureName)
{
if(!texture.loadFromFile(textureName))
{
return false;
}
texture.setSmooth(true);
sprite.setTexture(texture);
sprite.setTextureRect(sf::IntRect(0,0,50,50));
return true;

}