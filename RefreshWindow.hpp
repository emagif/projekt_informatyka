#pragma once 
#include <SFML/Graphics.hpp>

class RefreshWindow 
{
private: 
    bool gameActive = true; // flag controlling the game activity

public: 
    RefreshWindow();
    void StopGame(sf::RenderWindow& window, sf::Event& event);
    bool IsGameActive() const;
};