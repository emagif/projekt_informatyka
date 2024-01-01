#pragma once
#include <SFML/Graphics.hpp>

#define MAP_SIZE 50

class Map
{
private: 
    sf::Sprite* mapSprites;

public: 
    Map();
    ~Map();

    void Initialize();
    void Load();
    void Update(double deltaTime);
    void Draw(sf::RenderWindow& window);
};