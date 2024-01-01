#include <SFML/Graphics.hpp>
#include <iostream>

#include "Player.hpp"
#include "Enemy.hpp"
#include "FrameRate.hpp"
#include "Map.hpp"


int main()
{
// INITIALIZATIZE
// creating main window object
sf::RenderWindow Play(sf::VideoMode(1280, 960), "Best game ever!");
Play.setFramerateLimit(360);

// creating bullets
std::vector<sf::RectangleShape> bullets;
float bulletSpeed = 0.05f;

// creating objects
FrameRate frameRate;
Map map;
Player player; 
Enemy enemy;



// Initializing player and enemy
frameRate.Initialize();
map.Initialize();
player.Initialize();
enemy.Initialize();

// Loading player and enemy
frameRate.Load();
map.Load("Level1.rmap");
player.Load();
enemy.Load();

sf::Clock clock;

// main loop
while(Play.isOpen())
{
    // creating player movement that is independent of the frame rate, should have done it in Player class
    sf::Time deltaTimeTimer = clock.restart();
    double deltaTime = deltaTimeTimer.asMicroseconds() / 1000.0;

    // event handling
    sf::Event event;
    while(Play.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            Play.close();
        }
        // closing window with ESC
        if(event.type == sf::Event::KeyPressed)
        {
        if(event.key.code == sf::Keyboard::Escape)
        {
            Play.close();
        }
        }
    }

    sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(Play));

    frameRate.Update(deltaTime);
    map.Update(deltaTime);
    enemy.Update(deltaTime); // updating the posiiton of the enemy
    player.Update(deltaTime, enemy, mousePosition, Play); // updating the position of the player
    
// before the ending of the main loop
    Play.clear(sf::Color::Black);
    map.Draw(Play); // drawing the map
    enemy.Draw(Play); // drawing the enemy
    player.Draw(Play); // drawing the player
    frameRate.Draw(Play); // drawing frame rate, should add points and timer
    Play.display();

}

    return 0;
}