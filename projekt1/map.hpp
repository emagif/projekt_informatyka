#pragma once
#include <iostream> 
#include <SFML/Graphics.hpp>

class Map
{
public: 
Map();
~Map();
void Initialize();
void Load();
void Update(float deltaTime);
void Draw(sf::RenderWindow& Play);

private: 
sf::Texture tileSheetTexture;
sf::Sprite sprite;
};