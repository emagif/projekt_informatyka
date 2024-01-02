#pragma once
#include <SFML/Graphics.hpp>

class Enemy 
{
private:
    sf::Texture texture;

    sf::Text healthText;
    sf::Font font; 

public: 
    sf::Sprite sprite;

    sf::RectangleShape boundingRectangle;
    sf::Vector2i size;

    int health;

public: 
    Enemy();
    ~Enemy();

    void ChangeHealth(int hp);

    void Initialize(); //wywołane raz
    void Load(); //wywołane raz
    void Update(double deltaTime); //wywołane przy każdej klatce
    void Draw(sf::RenderWindow& window); //wywołane przy każdej klatce

};