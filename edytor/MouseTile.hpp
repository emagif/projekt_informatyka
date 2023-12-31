#pragma once
#include <SFML/Graphics.hpp>

class MouseTile
{

private:

public:
    MouseTile();
    ~MouseTile();

    void Initialize(); 
    void Load(); 

    void Update(double deltaTime, sf::Vector2f mousePosition); 
    void Draw(sf::RenderWindow& window); 
};
