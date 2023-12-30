// wyświetla ekran pomocy-
#pragma once 
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <sstream> 
#include <iomanip>


class Help
{
public: 
    Help(sf::VideoMode(unsigned int width, unsigned int height, const std::string& title));
    void run_and_shut();
    void text();

private: 
    sf::RenderWindow window;
    sf::Text helping;
    sf::Font font;
};
