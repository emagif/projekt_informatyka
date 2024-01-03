#include <SFML/Graphics.hpp>
#include <iostream>

#include "Player.hpp"
#include "Enemy.hpp"
#include "FrameRate.hpp"
#include "Map.hpp"
#include "MainMenu.hpp"
#include "LineDrawer.hpp"


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
FrameRate frameRate; // creating frame rate object to show frames
Map map; // creating map object to render the map
Player player; // creating the player
Enemy enemy; // creating the enemy 
MainMenu menu(Play.getSize().x, Play.getSize().y); // creating the menu

LineDrawer LineDrawer;
LineDrawer.addLine(sf::Vector2f(250, 0), sf::Vector2f(250, 160), sf::Color::Red); //top left corner building borders
LineDrawer.addLine(sf::Vector2f(250, 160), sf::Vector2f(710, 160), sf::Color::Blue);
LineDrawer.addLine(sf::Vector2f(710, 160), sf::Vector2f(710, 0), sf::Color::Green);


LineDrawer.addLine(sf::Vector2f(1120, 0), sf::Vector2f(1120, 240), sf::Color::White); // top right corner building borders
LineDrawer.addLine(sf::Vector2f(1120, 240), sf::Vector2f(1280, 240), sf::Color::White);



LineDrawer.addLine(sf::Vector2f(240, 320), sf::Vector2f(320, 320), sf::Color::White); // left wooden piece borders
LineDrawer.addLine(sf::Vector2f(320, 320), sf::Vector2f(320, 240), sf::Color::White);
LineDrawer.addLine(sf::Vector2f(320, 240), sf::Vector2f(240, 240), sf::Color::White);
LineDrawer.addLine(sf::Vector2f(240, 240), sf::Vector2f(240, 320), sf::Color::White);

LineDrawer.addLine(sf::Vector2f(480, 320), sf::Vector2f(560, 320), sf::Color::White); // middle wooden piece borders
LineDrawer.addLine(sf::Vector2f(560, 320), sf::Vector2f(560, 240), sf::Color::White);
LineDrawer.addLine(sf::Vector2f(560, 240), sf::Vector2f(480, 240), sf::Color::White);
LineDrawer.addLine(sf::Vector2f(480, 240), sf::Vector2f(480, 320), sf::Color::White);

LineDrawer.addLine(sf::Vector2f(720, 400), sf::Vector2f(800, 400), sf::Color::White); // right wooden piece borders
LineDrawer.addLine(sf::Vector2f(800, 400), sf::Vector2f(800, 320), sf::Color::White);
LineDrawer.addLine(sf::Vector2f(800, 320), sf::Vector2f(720, 320), sf::Color::White);
LineDrawer.addLine(sf::Vector2f(720, 320), sf::Vector2f(720, 400), sf::Color::White);

LineDrawer.addLine(sf::Vector2f(970, 390), sf::Vector2f(1030, 390), sf::Color::White); // sharp point borders
LineDrawer.addLine(sf::Vector2f(1030, 390), sf::Vector2f(1030, 330), sf::Color::White);
LineDrawer.addLine(sf::Vector2f(1030, 330), sf::Vector2f(970, 330), sf::Color::White);
LineDrawer.addLine(sf::Vector2f(970, 330), sf::Vector2f(970, 390), sf::Color::White);


LineDrawer.addLine(sf::Vector2f(0, 810), sf::Vector2f(240, 810), sf::Color::White); // left bottom building borders
LineDrawer.addLine(sf::Vector2f(240, 810), sf::Vector2f(240, 960), sf::Color::White);

LineDrawer.addLine(sf::Vector2f(1280, 810), sf::Vector2f(1120, 810), sf::Color::White); // right bottom building borders
LineDrawer.addLine(sf::Vector2f(1120, 810), sf::Vector2f(1120, 960), sf::Color::White);

LineDrawer.addLine(sf::Vector2f(240, 410), sf::Vector2f(720, 410), sf::Color::White); // middle building borders
LineDrawer.addLine(sf::Vector2f(720, 410), sf::Vector2f(720, 630), sf::Color::White);
LineDrawer.addLine(sf::Vector2f(720, 630), sf::Vector2f(240, 630), sf::Color::White);
LineDrawer.addLine(sf::Vector2f(240, 630), sf::Vector2f(240, 410), sf::Color::White);




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
    enemy.Draw(Play); // drawing the enemy
    player.Draw(Play); // drawing the player
    frameRate.Draw(Play); // drawing frame rate, should add points and timer
    Play.display();

}

    return 0;
}