#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.hpp"
#include "MapLoader.hpp"
#include "MapData.hpp"

class Map
{
private: 
    sf::Texture tileSheetTexture;

    Tile* tiles;

    MapLoader mapLoader;
    MapData md;

    int totalTiles;

    int totalTilesX;
    int totalTilesY;

    sf::Sprite* mapSprites;

public:
    Map();
    ~Map();

    void Initialize(); //wywoływane raz
    void Load(std::string filename); //wywoływane raz

    void Update(double deltaTime); //wywoływane raz na klatkę
    void Draw(sf::RenderWindow& window); //wywoływane raz na klatkę

};