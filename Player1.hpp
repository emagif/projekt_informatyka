#pragma once 
#include <SFML/Graphics.hpp>
#include "Enemy.hpp"
#include "Bullet.hpp"

class Player1
{
private: 
    sf::Texture texture;

    std::vector<Bullet> bullets;

    float maxFireRate;
    double fireRateTimer;

    sf::Vector2i size;
    
public:     
    float playerSpeed;
    sf::Sprite m_sprite;
    sf::RectangleShape boundingRectangle;

public: 
    Player1();
    ~Player1();

    void Initialize(); // envoking once
    void Load(); // envoking once

    void Update(double deltaTime, Enemy& enemy, sf::Vector2f& mousePosition, sf::RenderWindow& window); // envoking once per fram
    void Draw(sf::RenderWindow& window); // envoking once per frame
};