#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

#include "Player1.hpp"
#include "Enemy.hpp"
#include "FrameRate.hpp"
#include "Map.hpp"
#include "MainMenu.hpp"
#include "LineDrawer.hpp"
#include "CheckCollision.hpp"
#include "DrawRectangles.hpp"
#include "CheckCollisionEnemy.hpp"
#include "Points.hpp"
#include "SavingAndReadingFromFile.hpp"
#include "RefreshWindow.hpp"

int main()
{
// INITIALIZATIZE
// creating main window object
sf::RenderWindow Play(sf::VideoMode(1280, 960), "Best game ever!");
Play.setFramerateLimit(360);

sf::RenderWindow Menu(sf::VideoMode(1280, 960), "Menu :)");
Menu.setFramerateLimit(360);

sf::RenderWindow Help(sf::VideoMode(1280, 960), "Help");
Help.setFramerateLimit(360);

sf::RenderWindow Difficulty(sf::VideoMode(1280, 960), "Difficulty");
Difficulty.setFramerateLimit(360);

// creating bullets
std::vector<sf::RectangleShape> bullets;
float bulletSpeed = 0.05f;
sf::Color transparentColor = sf::Color(255, 255, 255, 0); // setting transparency of the rectangles

// creating objects
FrameRate frameRate; // creating frame rate object to show frames
Map map; // creating map object to render the map
Player1 player; // creating player1
Enemy enemy; // creating the enemy 
Enemy enemy1;
MainMenu menu(Play.getSize().x, Play.getSize().y); // creating the menu
LineDrawer LineDrawer;
DrawRectangles rectanglesDrawer;
CheckCollision collisionChecker(rectanglesDrawer.m_rectangles); // object for checking collision between the player and obstacles
CheckCollisionEnemy checker(rectanglesDrawer.m_rectangles);
Points points;
SavingAndReadingFromFile SaverAndReader;
RefreshWindow stopWindow;

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

// Initializing player and enemy
frameRate.Initialize();
map.Initialize();
player.Initialize();
enemy.Initialize(); // initializing first enemy
enemy1.Initialize(); // initializing second enemy

// Loading player and enemy
frameRate.Load();
map.Load("Level1.rmap"); // possible to load another map in the future
player.Load();
enemy.Load(sf::Vector2f(400, 300));  // loading first enemy
enemy1.Load(sf::Vector2f(800, 400)); // loading second enemy
points.SetPosition(1000, 20);

sf::Clock clock;

// main loop
while(Play.isOpen())
{
    // creating player movement that is independent of the frame rate, should have done it in Player class
    sf::Time deltaTimeTimer = clock.restart();
    double deltaTime = deltaTimeTimer.asMicroseconds() / 1000.0;

    // event handling
    sf::Event event;

    stopWindow.StopGame(Play, event); // stopping the window

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

    if(stopWindow.IsGameActive()) // checks if the flag
    {   
        sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(Play));

        frameRate.Update(deltaTime);
        map.Update(deltaTime);
        enemy.Update(deltaTime, player.boundingRectangle.getPosition()); // updating the posiiton of the enemy
        enemy1.Update(deltaTime, player.boundingRectangle.getPosition());
        player.Update(deltaTime, enemy, mousePosition, Play); // updating the position of the player
        collisionChecker.checkCollision(player.boundingRectangle, deltaTime, player);
        checker.checkCollisionBetweenPlayerAndEnemy(player, deltaTime, enemy, Play, clock, points); // checks the collision between player and enemy and closes the game window
        checker.checkCollisionBetweenPlayerAndEnemy(player, deltaTime, enemy1, Play, clock, points); // checks the collision between player and enemy and closes the game window
        points.IncreaseScore(clock); // increases the score
        SaverAndReader.SaveToFile(Play, points, player, event); // saves to file

// before the ending of the main loop
        Play.clear(sf::Color::Black);
        menu.Draw(Play); // drawing the menu
        map.Draw(Play); // drawing the map
        // Play.draw(LineDrawer);
        points.Draw(Play);
        enemy.Draw(Play); // drawing the enemy
        enemy1.Draw(Play); // drawing the enemy
        player.Draw(Play); // drawing the player
        rectanglesDrawer.Draw(Play);
        frameRate.Draw(Play); // drawing frame rate, should add points and timer
        Play.display();

    }
}
    return 0;
}