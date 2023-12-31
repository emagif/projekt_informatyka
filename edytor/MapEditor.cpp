#include <SFML/Graphics.hpp>
#include <iostream>
#include "Grid.hpp"
#include "MouseTile.hpp"

int main()
{
// INITIALIZING
// creating the main loop/window
sf::RenderWindow Window(sf::VideoMode(1280, 960), "Your own map editor :)");
Window.setFramerateLimit(360);


Grid grid(sf::Vector2f(0, 0), sf::Vector2i(10, 5), sf::Vector2i(16, 16), sf::Vector2i(5, 5), sf::Color(255, 0, 0, 255), 2); // specifying all the attributes of the lines and the cells
MouseTile mouseTile;

// INITIALIZING
grid.Initialize(); // initializing the grid
mouseTile.Initialize();


// LOADING
grid.Load(); // loading the grid
mouseTile.Load(); 

sf::Clock clock;

// main loop
while(Window.isOpen())
{
    sf::Time deltaTimeTimer = clock.restart();
    double deltaTime = deltaTimeTimer.asMicroseconds() / 1000.0;

    // handling events
    sf::Event event;
    while(Window.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            Window.close();
        }
        // closing window with ESC
        if(event.type == sf::Event::KeyPressed)
        {
        if(event.key.code == sf::Keyboard::Escape)
        {
            Window.close();
        }
        }
    }

    sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(Window));
    grid.Update(deltaTime); // grid update literally 
    mouseTile.Update(deltaTime, mousePosition);
    
// Here I'm before the end of the main loop 
    Window.clear(sf::Color::Black);
    grid.Draw(Window); // drawing the grid
    mouseTile.Draw(Window);
    Window.display();

}

    return 0;
}