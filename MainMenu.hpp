// #pragma once
// #include <SFML/Graphics.hpp>
// #include <iostream>

// class MainMenu
// {
// private:
//     sf::RenderWindow& m_window;
//     sf::Font m_font;
//     sf::Color m_selectedItemColor;
//     sf::Color m_defaultItemColor;
//     std::vector<sf::Text> m_items;
//     int m_selectedIndex;
    
     
// public:     
//     MainMenu(sf::RenderWindow& window);

//     void AddItem(const std::string& itemText);
//     void Draw();
//     void MoveUp();
//     void MoveDown();
//     int GetSelectedItem() const
//     {
//         return m_selectedIndex; // inline declaration
//     };
//     void HiglightSelectedMenuItem();

   
// }; 

// enum class GameStateChoice // enum for switching between the menu and game "window"
// { 
//     Menu, 
//     Game, 
//     Exit
// };


#pragma once
#include <SFML/Graphics.hpp>

#define MAX_NR_ITEMS 4

class MainMenu
{
private: 
    int m_selectedItemIndex;
    sf::Font m_font;
    sf::Text m_text[MAX_NR_ITEMS];

public: 
    MainMenu(float width, float height);
    ~MainMenu();

    void Draw(sf::RenderWindow& window);
    void MoveUp();
    void MoveDown();

    int selectedItem()
    {
        return m_selectedItemIndex;
    }

};

