#include <SFML/Graphics.hpp>
#include <iostream>

#include "Player.hpp"
#include "Enemy.hpp"
#include "FrameRate.hpp"
#include "Map.hpp"


int main()
{
//STREFA INICJALIZACJI
// stworzenie okna głównego
sf::RenderWindow Play(sf::VideoMode(1280, 960), "Best game ever!");
Play.setFramerateLimit(360);

//stworzenie kul do strzelania
std::vector<sf::RectangleShape> bullets;
float bulletSpeed = 0.05f;

//utworzenie gracza
FrameRate frameRate;
Map map;
Player player; 
Enemy enemy;



//Strefa inicjalizacji przeciwnika i gracza
frameRate.Initialize();
map.Initialize();
player.Initialize();
enemy.Initialize();

// Strefa ładowania przeciwnika i gracza
frameRate.Load();
map.Load("Level1.rmap");
player.Load();
enemy.Load();

sf::Clock clock;

//główna pętla
while(Play.isOpen())
{
    //tworzenie niezależności poruszania się zawodnika od klatek
    sf::Time deltaTimeTimer = clock.restart();
    double deltaTime = deltaTimeTimer.asMicroseconds() / 1000.0;

    // obsługa zdarzeń 
    sf::Event event;
    while(Play.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            Play.close();
        }
        //zamykanie okna Esc
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
    enemy.Update(deltaTime);
    player.Update(deltaTime, enemy, mousePosition);
    
// Tutaj jestem przed końcem while'a 
    Play.clear(sf::Color::Black);
    map.Draw(Play);
    enemy.Draw(Play);
    player.Draw(Play);
    frameRate.Draw(Play);
    Play.display();

}

    return 0;
}