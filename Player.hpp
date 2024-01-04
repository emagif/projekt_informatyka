#pragma once 
#include <SFML/Graphics.hpp>
#include "Enemy.hpp"
#include "Bullet.hpp"

class Player
{
private: 
    sf::Texture texture;

    std::vector<Bullet> bullets;

    float maxFireRate;
    double fireRateTimer;

    float playerSpeed;

    sf::Vector2i size;
    
public:     
    sf::Sprite sprite;
    sf::RectangleShape boundingRectangle;

public: 
    Player();
    ~Player();

    void Initialize(); // envoking once
    void Load(); // envoking once

    void Update(double deltaTime, Enemy& enemy, sf::Vector2f& mousePosition, sf::RenderWindow& window); // envoking once per fram
    void Draw(sf::RenderWindow& window); // envoking once per frame
};