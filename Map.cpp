#include "Map.hpp"
#include <iostream>
#include "Player1.hpp"

Map::Map() :totalTilesX(0), totalTilesY(0), totalTiles(0), tiles(nullptr), mapSprites(nullptr)
{

}

Map::~Map()
{
    delete[] mapSprites; //usuniete z heapu mapSprite (był błąd rdzenia)
    delete[] tiles; //usunięte z heapu ^
}

void Map::Initialize()
{

}

void Map::Load(std::string filename)
{
    mapLoader.Load(filename, md);

    mapSprites = new sf::Sprite[md.dataLength];


    if(tileSheetTexture.loadFromFile(md.tilesheet))
    {
        std::cout<<"Loaded successfully!"<<std::endl;

        totalTilesX = tileSheetTexture.getSize().x / md.tileWidth;
        totalTilesY = tileSheetTexture.getSize().y / md.tileHeight;

        totalTiles = totalTilesX * totalTilesY;

        tiles = new Tile[totalTiles];


        for(int y = 0; y<totalTilesY; y++)
        {

            for (int x =0; x<totalTilesX; x++)
            {
                int i =x + y * totalTilesX;

                tiles[i].id = i; 
                tiles[i].position = sf::Vector2i(x * md.tileWidth, y * md.tileWidth);
            }

        }

    }

    else
    {
        std::cout<<"The texture is not here"<<std::endl;
    }

    for(int y = 0; y<md.mapHeight; y++)
    {
        for(int x = 0; x<md.mapWidth; x++)
        {
            int i = x + y * md.mapWidth;

            int index = md.data[i];

            mapSprites[i].setTexture(tileSheetTexture);
            mapSprites[i].setTextureRect(sf::IntRect(tiles[index].position.x, tiles[index].position.y, md.tileWidth, md.tileHeight));
            mapSprites[i].setScale(sf::Vector2f(md.scaleX, md.scaleY));
            mapSprites[i].setPosition(sf::Vector2f(x * md.tileWidth * md.scaleX, y * md.tileHeight * md.scaleY));
        }
    }

}

void Map::Update(double deltaTime)
{

}


void Map::Draw(sf::RenderWindow& window)
{

    for(size_t i =0; i<md.dataLength; i++)
    {
        window.draw(mapSprites[i]);
    }
    
}
