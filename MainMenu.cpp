// #include "MainMenu.hpp"

// MainMenu::MainMenu(sf::RenderWindow& window) : m_window(window), m_selectedIndex(0)
// {
//     m_font.loadFromFile("/home/emmanuel/Pulpit/projekt_informatyka/font/font.ttf"); // loading the font
//     m_selectedItemColor = sf::Color::Red;
//     m_defaultItemColor = sf::Color::White;
// }

// void MainMenu::AddItem(const std::string& itemText)
// {
//     sf::Text menuItem;  // setting up the font for the options of the menu
//     menuItem.setFont(m_font);
//     menuItem.setString(itemText);
//     menuItem.setFillColor(m_defaultItemColor);
//     m_items.push_back(menuItem);
// }

// void MainMenu::Draw()
// {
//     for(int i = 0; i<m_items.size(); i++)
//     {
//         m_items[i].setPosition(100, 100 + i * 30);
//         m_window.draw(m_items[i]);
//     }
//     HiglightSelectedMenuItem(); // highlights the menu item that is currently available to choose
// }

// void MainMenu::MoveDown()
// {
//     if(m_selectedIndex < m_items.size() - 1)
//     {
//         m_items[m_selectedIndex].setFillColor(m_defaultItemColor);
//         m_selectedIndex++;
//         m_items[m_selectedIndex].setFillColor(m_selectedItemColor);
//     }
// }

// void MainMenu::MoveUp()
// {
//     if(m_selectedIndex > 0)
//     {
//         m_items[m_selectedIndex].setFillColor(m_defaultItemColor);
//         m_selectedIndex--;
//         m_items[m_selectedIndex].setFillColor(m_selectedItemColor);
//     }
// }

// void MainMenu::HiglightSelectedMenuItem() // allows to highlight the currently selected item in the array
// {
//     if(!m_items.empty())
//     {
//         m_items[m_selectedIndex].setFillColor(m_selectedItemColor);
//     }
// }


#include "MainMenu.hpp"

MainMenu::MainMenu(float width, float height)
{
    if(!m_font.loadFromFile("/home/emmanuel/Pulpit/projekt_informatyka/font/font.ttf"))
    {

    }

    m_text[0].setFont(m_font);
    m_text[0].setColor(sf::Color::Red);
    m_text[0].setString("Start playing");
    m_text[0].setPosition(sf::Vector2f(width / 2, height/ (MAX_NR_ITEMS + 1) * 1));

    m_text[1].setFont(m_font);
    m_text[1].setColor(sf::Color::White);
    m_text[1].setString("Help");
    m_text[1].setPosition(sf::Vector2f(width / 2, height/ (MAX_NR_ITEMS + 1) * 2));

    m_text[2].setFont(m_font);
    m_text[2].setColor(sf::Color::White);
    m_text[2].setString("About the project");
    m_text[2].setPosition(sf::Vector2f(width / 2, height/ (MAX_NR_ITEMS + 1) * 3));

    m_text[3].setFont(m_font);
    m_text[3].setColor(sf::Color::White);
    m_text[3].setString("Exit");
    m_text[3].setPosition(sf::Vector2f(width / 2, height/ (MAX_NR_ITEMS + 1) * 4));

    m_selectedItemIndex = 0;
}


void MainMenu::Draw(sf::RenderWindow& window)
{
    for(int i = 0; i < MAX_NR_ITEMS; i++)
    {
        window.draw(m_text[i]);
    }
}

void MainMenu::MoveUp()
{
    if(m_selectedItemIndex - 1 > 0)
    {
        m_text[m_selectedItemIndex].setColor(sf::Color::White);
        m_selectedItemIndex--;
        m_text[m_selectedItemIndex].setColor(sf::Color::Red);
    }
}


void MainMenu::MoveDown()
{
    if(m_selectedItemIndex + 1 < MAX_NR_ITEMS)
    {
        m_text[m_selectedItemIndex].setColor(sf::Color::White);
        m_selectedItemIndex++;
        m_text[m_selectedItemIndex].setColor(sf::Color::Red);
    }

}