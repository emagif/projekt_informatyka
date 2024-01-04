#include <SFML/Graphics.hpp>
#include <iostream>

#include "Player.hpp"
#include "Enemy.hpp"
#include "FrameRate.hpp"
#include "Map.hpp"
#include "MainMenu.hpp"
#include "LineDrawer.hpp"
#include "CheckCollision.hpp"
#include "DrawRectangles.hpp"

int main()
{
// INITIALIZATIZE
// creating main window object
sf::RenderWindow Play(sf::VideoMode(1280, 960), "Best game ever!");
Play.setFramerateLimit(360);

// creating bullets
std::vector<sf::RectangleShape> bullets;
float bulletSpeed = 0.05f;
sf::Color transparentColor = sf::Color(255, 255, 255, 0);

// creating objects
FrameRate frameRate; // creating frame rate object to show frames
Map map; // creating map object to render the map
Player player; // creating the player
Enemy enemy; // creating the enemy 
MainMenu menu(Play.getSize().x, Play.getSize().y); // creating the menu
LineDrawer LineDrawer;
CheckCollision collisionChecker;
DrawRectangles rectanglesDrawer;

rectanglesDrawer.addRectangle(250, 0, 460, 160, transparentColor); // top left corner building borders
rectanglesDrawer.addRectangle(1120, 0, 260, 240, transparentColor); // top right corner building borders
rectanglesDrawer.addRectangle(240, 240, 80, 80, transparentColor); // left wooden piece borders
rectanglesDrawer.addRectangle(480, 240, 80, 80, transparentColor); // middle wooden piece borders
rectanglesDrawer.addRectangle(720, 320, 80, 80, transparentColor); // right wooden piece borders
rectanglesDrawer.addRectangle(720, 320, 80, 80, transparentColor); // right wooden piece borders
rectanglesDrawer.addRectangle(970, 330, 60, 60, transparentColor); // right wooden piece borders
rectanglesDrawer.addRectangle(0, 810, 240, 150, transparentColor); // left bottom building borders
rectanglesDrawer.addRectangle(1120, 810, 160, 150, transparentColor); // right bottom building borders
rectanglesDrawer.addRectangle(240, 410, 480, 225, transparentColor); // middle building borders
rectanglesDrawer.addRectangle(1040, 410, 240, 230, transparentColor); // right building borders
rectanglesDrawer.addRectangle(1120, 640, 80, 55, transparentColor); 
rectanglesDrawer.addRectangle(400, 730, 480, 230, transparentColor); // middle bottom building borders

// creating the menu
// menu.AddItem("Start");
// menu.AddItem("Help");
// menu.AddItem("About the project");
// menu.AddItem("Exit");

// GameStateChoice state = GameStateChoice::Menu; // starting out with the menu on the screen

// Initializing player and enemy
frameRate.Initialize();
map.Initialize();
player.Initialize();
enemy.Initialize();

// Loading player and enemy
frameRate.Load();
map.Load("Level1.rmap"); // possible to load another map in the future
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
    menu.Draw(Play); // drawing the menu
    map.Draw(Play); // drawing the map
    Play.draw(LineDrawer);
    rectanglesDrawer.Draw(Play);
    enemy.Draw(Play); // drawing the enemy
    player.Draw(Play); // drawing the player
    frameRate.Draw(Play); // drawing frame rate, should add points and timer
    Play.display();
}

    return 0;
}