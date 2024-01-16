#include "Enemy.hpp"
#include <iostream> 
#include <cmath>

Enemy::Enemy() : health(100)
{
}

Enemy::~Enemy()
{
}

void Enemy::ChangeHealth(int hp)
{
health += hp;
healthText.setString(std::to_string(health));
}

void Enemy::Initialize()
{
    boundingRectangle.setFillColor(sf::Color::Transparent);
    boundingRectangle.setOutlineColor(sf::Color::Blue);
    boundingRectangle.setOutlineThickness(1);

    size = sf::Vector2i(16, 16);
}

void Enemy::Load(sf::Vector2f enemyPosition)
{
 
    if(font.loadFromFile("font/font.ttf")) //  health bar font
{
    std::cout<<"Font has been loaded successfully"<<std::endl;
    healthText.setFont(font);
    healthText.setCharacterSize(10);
    healthText.setString(std::to_string(health));
}

else
{
    std::cout<<"Failed to load the font"<<std::endl;
}

if(texture.loadFromFile("Tiles/tile_0121.png"))
{
    sprite.setTexture(texture);
    sprite.scale(sf::Vector2f(2,2));
    sprite.setPosition(sf::Vector2f(enemyPosition.x, enemyPosition.y));

    boundingRectangle.setSize(sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));
}

else
{
    std::cout<<"The texture is not here"<<std::endl;
}
}

void Enemy::Update(double deltaTime, const sf::Vector2f& playerPosition)
{
    if(health>0)
    {

        sf::Vector2f direction = playerPosition - sprite.getPosition();
        float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
        if(length != 0)
        {
            direction.x /= length;
            direction.y /= length;
        }
        float enemySpeed = 0.1f; // speed of the enemy following player

        sprite.move(direction * enemySpeed * static_cast<float>(deltaTime)); // had to cast deltaTime to float  // bullets disappear after adding this piece
        
        boundingRectangle.setPosition(sprite.getPosition());
        healthText.setPosition(sprite.getPosition()); // sets the health bar where the enemy is
    }
}

void Enemy::Draw(sf::RenderWindow& window)
{
    if(health>0)
    {
        window.draw(sprite);
        window.draw(boundingRectangle);
        window.draw(healthText);
    }

}