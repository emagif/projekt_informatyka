#include "MainMenu.hpp"

MainMenu::MainMenu(sf::RenderWindow& window) : m_window(window), m_selectedIndex(0)
{
    m_font.loadFromFile("/home/emmanuel/Pulpit/projekt_informatyka/font/font.ttf"); // loading the font
    m_selectedItemColor = sf::Color::Red;
    m_defaultItemColor = sf::Color::White;
}

void MainMenu::AddItem(const std::string& itemText)
{
    sf::Text menuItem;  // setting up the font for the options of the menu
    menuItem.setFont(m_font);
    menuItem.setString(itemText);
    menuItem.setFillColor(m_defaultItemColor);
    m_items.push_back(menuItem);
}

void MainMenu::Draw()
{
    for(int i = 0; i<m_items.size(); i++)
    {
        m_items[i].setPosition(100, 100 + i * 30);
        m_window.draw(m_items[i]);
    }
    HiglightSelectedMenuItem(); // highlights the menu item that is currently available to choose
}

void MainMenu::MoveDown()
{
    if(m_selectedIndex < m_items.size() - 1)
    {
        m_items[m_selectedIndex].setFillColor(m_defaultItemColor);
        m_selectedIndex++;
        m_items[m_selectedIndex].setFillColor(m_selectedItemColor);
    }
}

void MainMenu::MoveUp()
{
    if(m_selectedIndex > 0)
    {
        m_items[m_selectedIndex].setFillColor(m_defaultItemColor);
        m_selectedIndex--;
        m_items[m_selectedIndex].setFillColor(m_selectedItemColor);
    }
}

void MainMenu::HiglightSelectedMenuItem() // allows to highlight the currently selected item in the array
{
    if(!m_items.empty())
    {
        m_items[m_selectedIndex].setFillColor(m_selectedItemColor);
    }
}