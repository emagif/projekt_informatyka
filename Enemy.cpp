#include "Enemy.hpp"
#include <iostream> 




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


void Enemy::Load()
{
 
    if(font.loadFromFile("font/font.ttf")) //ładowanie czcionki do punktów życia gracza // zrobić manager zasobów, żeby nie ładować czcionki 2 razy
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


if(texture.loadFromFile("Tiles/tile_0086.png"))
{
    sprite.setTexture(texture);
    sprite.scale(sf::Vector2f(2,2));
    sprite.setPosition(sf::Vector2f(500,700));

    boundingRectangle.setSize(sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));
}

else
{
    std::cout<<"The texture is not here"<<std::endl;
}
}


void Enemy::Update(double deltaTime)
{
    if(health>0)
    {
    boundingRectangle.setPosition(sprite.getPosition());
    healthText.setPosition(sprite.getPosition()); //ustawia napis w miejscu, w którym znajduje się przeciwnik
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