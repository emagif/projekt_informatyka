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


void Player::Update(double deltaTime, Enemy& enemy, sf::Vector2f& mousePosition, sf::RenderWindow& window) // responsible for the movement of the player
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
 // responsible for switching sides of the player when crossing the bounds of the window
if(position.x > window.getSize().x)
{
    sprite.setPosition(0 - sprite.getGlobalBounds().width, position.y);
}

else if(position.x < 0 - sprite.getGlobalBounds().width)
{
    sprite.setPosition(window.getSize().x, position.y);
}

if(position.y > window.getSize().y)
{
    sprite.setPosition(position.x, 0 - sprite.getGlobalBounds().height);
}

else if(position.y < 0 - sprite.getGlobalBounds().height)
{
    sprite.setPosition(position.x, window.getSize().y);
}


// responsible for creating darts
fireRateTimer += deltaTime;

if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && fireRateTimer >= maxFireRate) // if the left button is pressed and fireRateTime is >1s then you can shoot again (change to a shorter amount of time)
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
        if(Vector::DidRectCollide(bullets[i].GetGlobalBounds(), enemy.sprite.getGlobalBounds())) // checking collision kolizji of the dart with enemy
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