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
    int x  = mousePosition.x / (16 * 10); // dividing mouse position and then multiplying it to lose the decimal point and lose data from float
    int xx = x * (16 * 10);

    int y = mousePosition.y / (16 * 10);
    int yy = y * (16 * 10);

    tile.setPosition(sf::Vector2f(xx, yy)); // new position of the tile
}

void MouseTile::Draw(sf::RenderWindow& window)
{
    window.draw(tile);
}

1h53 minuty 