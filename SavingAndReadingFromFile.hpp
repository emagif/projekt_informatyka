#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "Points.hpp"
#include "Player1.hpp"

class SavingAndReadingFromFile
{
private: 

public: 
    SavingAndReadingFromFile();
    void SaveToFile(sf::RenderWindow& window, Points& points, Player1& player, sf::Event& event);
    void ReadFromFile(sf::RenderWindow& window);
};