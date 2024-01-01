#include "Map.hpp"
#include <iostream>

 
Map::Map(const MouseTile& mouseTile) : m_mouseTile(mouseTile), m_mapSprites(nullptr)
{

}

Map::~Map()
{

}

void Map::Initialize()
{
    m_mapSprites = new sf::Sprite[MAP_SIZE];
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
        window.draw(m_mapSprites[i]);
    }
}

void Map:: grid(int x)
{

}


