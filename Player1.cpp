#include <iostream>
#include "Player1.hpp"
#include "Vector.hpp"

Player1::Player1() : playerSpeed(0.3f), maxFireRate(1000), fireRateTimer(0)
{
}

Player1::~Player1()
{
}

void Player1::Initialize()
{
    boundingRectangle.setFillColor(sf::Color::Transparent);
    boundingRectangle.setOutlineColor(sf::Color::Red);
    boundingRectangle.setOutlineThickness(1);

    size = sf::Vector2i(64, 64);
}

void Player1::Load() //odpowiada za załadowanie tekstury i sprite
{
if(texture.loadFromFile("Tilemap/BODY_skeleton.png"))
{
    m_sprite.setTexture(texture);

    int XIndex = 0;
    int YIndex = 0;

    m_sprite.setTextureRect(sf::IntRect(XIndex * size.x,YIndex * size.y, size.x, size.y));
    m_sprite.setPosition(sf::Vector2f(0, 0));

    m_sprite.scale(sf::Vector2f(1,1));
    boundingRectangle.setSize(sf::Vector2f(size.x*m_sprite.getScale().x, size.y*m_sprite.getScale().y));
}

else 
{
    std::cout<<"The texture is not here"<<std::endl;
}
}

void Player1::Update(double deltaTime, Enemy& enemy, sf::Vector2f& mousePosition, sf::RenderWindow& window) // responsible for the movement of the player
{

sf::Vector2f position = m_sprite.getPosition();

if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) // when A is pressed the player goes to the left
{
    if(texture.loadFromFile("Tilemap/BODY_skeleton.png"))
    {
        int XIndex = 0;
        int YIndex = 1;
        m_sprite.setTexture(texture);
        m_sprite.setTextureRect(sf::IntRect(XIndex * size.x, YIndex * size.y, size.x, size.y));
    }
    m_sprite.setPosition(position + sf::Vector2f(-1,0) * playerSpeed * (float)deltaTime);
}
    
if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) // when D is pressed the player goes to the right
{
     if(texture.loadFromFile("Tilemap/BODY_skeleton.png"))
    {
        int XIndex = 0;
        int YIndex = 3;
        m_sprite.setTexture(texture);
        m_sprite.setTextureRect(sf::IntRect(XIndex * size.x, YIndex * size.y, size.x, size.y));
    }
    m_sprite.setPosition(position + sf::Vector2f(1,0) * playerSpeed * (float)deltaTime);
}

if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) // when W is pressed the player goes to the top
{
     if(texture.loadFromFile("Tilemap/BODY_skeleton.png"))
    {
        int XIndex = 0;
        int YIndex = 0;
        m_sprite.setTexture(texture);
        m_sprite.setTextureRect(sf::IntRect(XIndex * size.x, YIndex * size.y, size.x, size.y));
    }
    m_sprite.setPosition(position + sf::Vector2f(0,-1) * playerSpeed * (float)deltaTime);
}

if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) // when S is pressed the player goes to the bottom
{
     if(texture.loadFromFile("Tilemap/BODY_skeleton.png"))
    {
        int XIndex = 0;
        int YIndex = 2;
        m_sprite.setTexture(texture);
        m_sprite.setTextureRect(sf::IntRect(XIndex * size.x, YIndex * size.y, size.x, size.y));
    }
    m_sprite.setPosition(position + sf::Vector2f(0,1) * playerSpeed* (float)deltaTime);
}
 // responsible for switching sides of the player when crossing the bounds of the window
if(position.x > window.getSize().x)
{
    m_sprite.setPosition(0 - m_sprite.getGlobalBounds().width, position.y);
}

else if(position.x < 0 - m_sprite.getGlobalBounds().width)
{
    m_sprite.setPosition(window.getSize().x, position.y);
}

if(position.y > window.getSize().y)
{
    m_sprite.setPosition(position.x, 0 - m_sprite.getGlobalBounds().height);
}

else if(position.y < 0 - m_sprite.getGlobalBounds().height)
{
    m_sprite.setPosition(position.x, window.getSize().y);
}

// responsible for creating darts
fireRateTimer += deltaTime;

if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && fireRateTimer >= maxFireRate) // if the left button is pressed and fireRateTime is >1s then you can shoot again (change to a shorter amount of time)
{
    bullets.push_back(Bullet());
    int i = bullets.size() - 1;
    bullets[i].Initialize(m_sprite.getPosition(), mousePosition, 0.5f);
    fireRateTimer = 0;
}

for(size_t i = 0; i<bullets.size(); i++)
{

    bullets[i].Update(deltaTime);

    if(enemy.health > 0)
    {
        if(Vector::DidRectCollide(bullets[i].GetGlobalBounds(), enemy.sprite.getGlobalBounds())) // checking collision of the dart with enemy
        {
            enemy.ChangeHealth(-10);
            bullets.erase(bullets.begin() + i);
        }
    }
}
boundingRectangle.setPosition(m_sprite.getPosition());
}

void Player1::Draw(sf::RenderWindow& window)
{
    window.draw(m_sprite);
    window.draw(boundingRectangle);

    for(size_t i = 0; i<bullets.size(); i++)
    {
        bullets[i].Draw(window);
    }
}