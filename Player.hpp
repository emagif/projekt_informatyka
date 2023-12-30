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


    sf::RectangleShape boundingRectangle;
    sf::Vector2i size;
    
    
public:     
    sf::Sprite sprite;

public: 
    Player();
    ~Player();

    void Initialize(); //wywoływane raz
    void Load(); //wywoływane raz

    void Update(double deltaTime, Enemy& enemy, sf::Vector2f& mousePosition); //wywoływane raz na klatkę
    void Draw(sf::RenderWindow& window); //wywoływane raz na klatkę
};