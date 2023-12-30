#include <iostream>
#include "Player.hpp"
#include "Vector.hpp"

Player::Player() : playerSpeed(1.0f), maxFireRate(1000), fireRateTimer(0)
{
}

Player::~Player()
{
}


void Player::Initialize()
{
    boundingRectangle.setFillColor(sf::Color::Transparent);
    boundingRectangle.setOutlineColor(sf::Color::Red);
    boundingRectangle.setOutlineThickness(1);

    size = sf::Vector2i(64, 64);
}


void Player::Load() //odpowiada za załadowanie tekstury i sprite
{
if(texture.loadFromFile("Tilemap/BODY_skeleton.png"))
{
    sprite.setTexture(texture);

    int XIndex = 0;
    int YIndex = 0;

    sprite.setTextureRect(sf::IntRect(XIndex * size.x,YIndex * size.y, size.x, size.y));
    sprite.setPosition(sf::Vector2f(0, 0));

    sprite.scale(sf::Vector2f(1,1));
    boundingRectangle.setSize(sf::Vector2f(size.x*sprite.getScale().x, size.y*sprite.getScale().y));
}

else 
{
    std::cout<<"The texture is not here"<<std::endl;
}
}


void Player::Update(double deltaTime, Enemy& enemy, sf::Vector2f& mousePosition) // całość odpowiada za ruch zawodnika
{

sf::Vector2f position = sprite.getPosition();

if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
{
    sprite.setPosition(position + sf::Vector2f(-1,0) * playerSpeed * (float)deltaTime);
}
    
if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
{
    sprite.setPosition(position + sf::Vector2f(1,0) * playerSpeed * (float)deltaTime);
}

if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
{
    sprite.setPosition(position + sf::Vector2f(0,-1) * playerSpeed * (float)deltaTime);
}

if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
{
    sprite.setPosition(position + sf::Vector2f(0,1) * playerSpeed* (float)deltaTime);
}


// odpowiada za tworzenie i strzelanie pociskami
fireRateTimer += deltaTime;

if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && fireRateTimer >= maxFireRate) // jeżeli naciśnięty jest przycisk myszy i fireRateTime jest większy niż 1s to można strzelać
{
    bullets.push_back(Bullet());
    int i = bullets.size() - 1;
    bullets[i].Initialize(sprite.getPosition(), mousePosition, 0.5f);
    fireRateTimer = 0;
}


for(size_t i = 0; i<bullets.size(); i++)
{

    bullets[i].Update(deltaTime);

    if(enemy.health > 0)
    {
        if(Vector::DidRectCollide(bullets[i].GetGlobalBounds(), enemy.sprite.getGlobalBounds())) //sprawdzanie kolizji pocisku z przeciwnikiem
        {
            enemy.ChangeHealth(-10);
            bullets.erase(bullets.begin() + i);
        }
    }
}
boundingRectangle.setPosition(sprite.getPosition());


}


void Player::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
    window.draw(boundingRectangle);

    for(size_t i = 0; i<bullets.size(); i++)
    {
        bullets[i].Draw(window);
    }
}