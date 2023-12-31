#include "MouseTile.hpp"

MouseTile::MouseTile()
{

}

MouseTile::~MouseTile()
{

}

void MouseTile::Initialize()
{

}

void MouseTile::Load()
{
    tileSheet.loadFromFile("/home/emmanuel/Pulpit/projekt_informatyka/Tilemap/tilemap_packed.png");
    tile.setTexture(tileSheet);
    tile.setTextureRect(sf::IntRect(32, 0, 16, 16));
    tile.setScale(sf::Vector2f(5, 5));

}

void MouseTile::Update(double deltaTime, sf::Vector2f mousePosition)
{
    tile.setPosition(mousePosition);
}

void MouseTile::Draw(sf::RenderWindow& window)
{
    window.draw(tile);
}