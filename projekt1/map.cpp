#include "map.hpp"
#include <SFML/Graphics.hpp>
#include <iostream> 

Map::Map()
{

}

Map::~Map()
{

}

void Map::Initialize()
{

}

void Map::Load()
{
if(tileSheetTexture.loadFromFile("Tilemap/tilemap.png"))
{
    std::cout<<"Texture has been loaded"<<std::endl;
    sprite.setTexture(tileSheetTexture);
    
}

else
{
    std::cout<<"Failed to load the texture"<<std::endl;
}
}

void Map::Update(float deltaTime)
{

}

void Map::Draw(sf::RenderWindow& Play)
{
Play.draw(sprite);
}