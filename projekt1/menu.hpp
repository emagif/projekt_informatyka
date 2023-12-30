#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>    


#define MAX_NUMBER_OF_ITEMS 4

class Menu
{
    public: 
    Menu(float width, float height);

    void draw(sf::RenderWindow& window);
    void MoveUp();
    void MoveDown();

    int MenuPressed()
    {
        return MenuSelected;
    }
    ~Menu();

    private:
    int MenuSelected;
    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];

};
