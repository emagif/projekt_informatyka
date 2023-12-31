#include <SFML/Graphics.hpp>
#include <iostream>
#include "Grid.hpp"

int main()
{
//STREFA INICJALIZACJI
// stworzenie okna głównego
sf::RenderWindow Window(sf::VideoMode(1280, 960), "Your own map editor :)");
Window.setFramerateLimit(360);


Grid grid(sf::Vector2f(0, 0), sf::Vector2i(10, 5), sf::Vector2i(16, 16), sf::Vector2i(5, 5), sf::Color(255, 0, 0, 255), 2); // specifying all the attributes of the lines and the cells

// INICJALIZACJA
grid.Initialize(); // inicjalizacja siatki

// ŁADOWANIE
grid.Load(); // ładowanie siatki

sf::Clock clock;

//główna pętla
while(Window.isOpen())
{
    sf::Time deltaTimeTimer = clock.restart();
    double deltaTime = deltaTimeTimer.asMicroseconds() / 1000.0;

    // obsługa zdarzeń 
    sf::Event event;
    while(Window.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            Window.close();
        }
        //zamykanie okna Esc
        if(event.type == sf::Event::KeyPressed)
        {
        if(event.key.code == sf::Keyboard::Escape)
        {
            Window.close();
        }
        }
    }

    sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(Window));
    grid.Update(deltaTime); // aktualizacja siatki
    
// Tutaj jestem przed końcem while'a 
    Window.clear(sf::Color::Black);
    grid.Draw(Window); // rysowanie siatki
    Window.display();

}

    return 0;
}