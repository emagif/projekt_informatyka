#pragma once
#include <iostream>
#include "MapData.hpp"

class MapLoader
{
public: 
    void Load(std::string filename, MapData& mapData);
};