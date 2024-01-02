#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class MainMenu
{
private:
    sf::RenderWindow& m_window;
    sf::Font m_font;
    sf::Color m_selectedItemColor;
    sf::Color m_defaultItemColor;
    std::vector<sf::Text> m_items;
    int m_selectedIndex;
    
     
public:     
    MainMenu(sf::RenderWindow& window);

    void AddItem(const std::string& itemText);
    void Draw();
    void MoveUp();
    void MoveDown();
    int GetSelectedItem() const
    {
        return m_selectedIndex; // inline declaration
    };
    void HiglightSelectedMenuItem();

   
}; 

enum class GameStateChoice // enum for switching between the menu and game "window"
{ 
    Menu, 
    Game, 
    Exit
};
