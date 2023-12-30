#include "menu.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>



Menu::Menu(float width, float height)
{
    if(!font.loadFromFile("font.ttf"))
    {
        std::cout<<"No font is here"<<std::endl;
    }
    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::White);
    menu[0].setString("Play");
    menu[0].setCharacterSize(40);
    menu[0].setPosition(200,200);

    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("About the project");
    menu[1].setCharacterSize(40);
    menu[1].setPosition(200,300);


    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color::White); 
    menu[2].setString("About the author");
    menu[2].setCharacterSize(40);
    menu[2].setPosition(200,400);


    menu[3].setFont(font);
    menu[3].setFillColor(sf::Color::White);
    menu[3].setString("Exit");
    menu[3].setCharacterSize(40);   
    menu[3].setPosition(200,500);   


    MenuSelected =-1;

}

Menu::~Menu()
{

}


void Menu::draw(sf::RenderWindow& window)
{
    for(int i=0; i<MAX_NUMBER_OF_ITEMS; i++)
    {
        window.draw(menu[i]);
    }
}


void Menu::MoveUp()
{
    if((MenuSelected -1)>=0 )
    {
        menu[MenuSelected].setFillColor(sf::Color::White);

        MenuSelected--;

        if(MenuSelected ==-1)
        {
            MenuSelected = 2;
        
        }
    
    menu[MenuSelected].setFillColor(sf::Color::Red);
    }

}

void Menu::MoveDown()
{
    if(MenuSelected +1<=MAX_NUMBER_OF_ITEMS)
    {
        menu[MenuSelected].setFillColor(sf::Color::White);
        MenuSelected++;

        if(MenuSelected==4)
        {
            MenuSelected=0;
        }

        menu[MenuSelected].setFillColor(sf::Color::Red);
    }
}
