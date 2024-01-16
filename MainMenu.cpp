
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
    m_text[0].setCharacterSize(50);


    m_text[1].setFont(m_font);
    m_text[1].setColor(sf::Color::White);
    m_text[1].setString("Help");
    m_text[1].setPosition(sf::Vector2f(width / 2, height/ (MAX_NR_ITEMS + 1) * 2));
    m_text[1].setCharacterSize(50);


    m_text[2].setFont(m_font);
    m_text[2].setColor(sf::Color::White);
    m_text[2].setString("About the project");
    m_text[2].setPosition(sf::Vector2f(width / 2, height/ (MAX_NR_ITEMS + 1) * 3));
    m_text[2].setCharacterSize(50);


    m_text[3].setFont(m_font);
    m_text[3].setColor(sf::Color::White);
    m_text[3].setString("Exit");
    m_text[3].setPosition(sf::Vector2f(width / 2, height/ (MAX_NR_ITEMS + 1) * 4));
    m_text[3].setCharacterSize(50);


    m_selectedItemIndex = 0;
}

MainMenu::~MainMenu()
{
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
    if(m_selectedItemIndex - 1 >= 0)
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