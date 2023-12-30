#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <sstream> 
#include <iomanip>
#include "help.hpp"


void Help::run_and_shut()
{
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
            if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Escape)
                {
                    window.close();
                }
            }

            
        }
        window.clear();
// tutaj umieścić logikę wyświetlania elementów na ekranie
        text();
        window.display();
    }
}


Help::Help(sf::VideoMode(unsigned int width, unsigned int height, const std::string& title))
{
run_and_shut();
}


void Help::text()
{
helping.setFont(font);
helping.setFillColor(sf::Color::White);
helping.setString("This is a guide how to play this game. So basically speaking you are supposed to use the keys on your keyboard to avoid the green water. That's all!");
helping.setCharacterSize(15);
helping.setPosition(10,10);
}

