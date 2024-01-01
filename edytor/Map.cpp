#include "Map.hpp"


Map::Map() : mapSprites(nullptr)
{

}

Map::~Map()
{

}

void Map::Initialize()
{
    mapSprites = new sf::Sprite[MAP_SIZE];
}

void Map::Load()
{

}

void Map::Update(double deltaTime)
{

}

void Map::Draw(sf::RenderWindow& window)
{
    for(int i = 0; i< MAP_SIZE; i++)
    {
        window.draw(mapSprites[i]);
    }
}