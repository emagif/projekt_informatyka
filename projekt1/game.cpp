#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <sstream> 
#include <iomanip>
#include "menu.hpp" 
#include "tile.hpp" // base sprite header file
#include "gameWorld.hpp"
#include "help.hpp"
#include "map.hpp"


#define MAX_NUMBER_OF_ITEMS 4



int main()
{
sf::Clock clock;
sf::Texture playerTexture;
sf::Sprite playerSprite;
Map map;
map.Initialize();
map.Load();

if(playerTexture.loadFromFile("Tiles/player.png"))
{
playerSprite.setTexture(playerTexture);
playerSprite.scale(sf::Vector2f(3,3));
}

//Tworzy obiekt klasy VideoMode, który przechowuje rozdzielczość ekranu
sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
//Tworzy okno MENU
    sf::RenderWindow MENU(sf::VideoMode(1080,720), "Main menu! Welcome to the industrial process simulation", sf::Style::Default); 
//tworzy obiekt klasy Menu
    Menu menu(MENU.getSize().x, MENU.getSize().y);
    GameWorld gameWorld = GameWorld();

    //ustawia background
    sf::RectangleShape background;
    background.setSize(sf::Vector2f(1080, 720));
    //tworzenie tekstury do backgroundu
    sf::Texture MainTexture;
    MainTexture.loadFromFile("Tiles/background.png");
    background.setTexture(&MainTexture);

    if(!MainTexture.loadFromFile("Tiles/background.png"))
    {
        std::cout<<"There is no background, someone that created me is a bad Software Developer :("<<std::endl;
    }

//tworzenie backgroundu do gry
sf::RectangleShape Pbackground; 
sf::Font font;

if(!font.loadFromFile("font.ttf"))
{
    std::cout<<"No font is here"<<std::endl;

}

sf::Text text_author;
text_author.setFont(font);
text_author.setFillColor(sf::Color::White);
text_author.setString("Hi! My name is Emanuel Gifuni. I am a 21 year old Robotics Engineering student at the Gdańsk University of Technology. \n I am passionate about programming, robotics and embeded systems. '\n' I am currently looking for an internship in the field of robotics. If you are interested in my person, please contact me at the following email address: emanuelgifuni@yahoo.ie");
text_author.setCharacterSize(20);
text_author.setPosition(10,10);

sf::Text text_project;
text_project.setFont(font);
text_project.setFillColor(sf::Color::White);
text_project.setString("Hi!");
text_project.setCharacterSize(20);
text_author.setPosition(10,10);



//pętla obsługująca okno MENU
   while(MENU.isOpen())
   {
    sf::Event event;

//obsługa zdarzeń
    while(MENU.pollEvent(event))
    {
        if(event.type==sf::Event::Closed)
        {
            MENU.close();
        
        }
//obsługa klawiatury
        if(event.type==sf::Event::KeyReleased)
        {
            //obsługa klawiszy strzałek
            if(event.key.code ==sf::Keyboard::Up)
            {
                menu.MoveUp();
                break;
            
            }

            if(event.key.code ==sf::Keyboard::Down)
            {
                menu.MoveDown();
                break;

            }
//obsługa klawisza enter
            if(event.key.code ==sf::Keyboard::Return)
            {
                sf::RenderWindow Play(sf::VideoMode(1280, 720), "Lets play!");
                sf::RenderWindow About_the_project(sf::VideoMode(1280, 720), "About the project");
                sf::RenderWindow About_the_author(sf::VideoMode(1280, 720), "About the author");
                

                int x=menu.MenuPressed();
                if(x==0)
                {
                    
                    while(Play.isOpen())
                    {
                        sf::Time deltaTimeTimer = clock.restart();
                        sf::Event aevent;
                        while(Play.pollEvent(aevent))
                        {
                            if(aevent.type==sf::Event::Closed)
                            {
                                Play.close();
                            }
                            // if(aevent.type == sf::Event::KeyPressed)
                            // {
                            //     if(aevent.key.code == sf::Keyboard::D)
                            //     {

                            //     sf::Vector2f position = playerSprite.getPosition();

                            //     playerSprite.setPosition(position + sf::Vector2f(10,0));
                            //     }
                                
                            }

                            if(aevent.type==sf::Event::KeyPressed)
                            {
                                if(aevent.key.code ==sf::Keyboard::Escape)
                                {
                                    Play.close();
                                }
                            }
                            sf::Vector2f position = playerSprite.getPosition();
                            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                            {
                                playerSprite.setPosition(position + sf::Vector2f(1,0));
                            }

                            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                            {
                                playerSprite.setPosition(position + sf::Vector2f(0,-1));
                            }

                             if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                            {
                                playerSprite.setPosition(position + sf::Vector2f(0,1));
                            }

                             if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                            {
                                playerSprite.setPosition(position + sf::Vector2f(-1,0));
                            }
                        }
                        
                        About_the_project.close();
                        About_the_author.close();
                        Play.clear();
                        // for (int i=0; i<gameWorld.gridLength; i++)
                        // {
                        //     for( int j=0; j<gameWorld.gridLength; j++)
                        //     {
                        //         Play.draw(gameWorld.tiles[i][j]->sprite);
                        //     }
                        // }
                        Play.draw(playerSprite);
                        Play.display();
                    }
                
                if(x==1)
                {
                   while(About_the_project.isOpen())
                   {
                    sf::Event aevent;
                    while(About_the_project.pollEvent(aevent))
                    {
                        if(aevent.type==sf::Event::Closed)
                        {
                            About_the_project.close();
                        }

                        if(aevent.type==sf::Event::KeyPressed)
                        {
                            if(aevent.key.code ==sf::Keyboard::Escape)
                            {
                                About_the_project.close();
                            }
                        }
                    }
                    Play.close();
                    About_the_author.close();
                    About_the_project.clear();
                    About_the_project.display();
                
                   } 
                }


                if(x==2)
                {
                    while(About_the_author.isOpen())
                    {
                        sf::Event aevent;
                        while(About_the_author.pollEvent(aevent))
                        {
                            if(aevent.type==sf::Event::Closed)
                            {
                                About_the_author.close();
                            }

                            if(aevent.type ==sf::Event::KeyPressed)
                            {
                                if(aevent.key.code==sf::Keyboard::Escape)
                                {
                                    About_the_author.close();
                                }
                            }
                        }
                        Play.close();
                        About_the_project.close();
                        About_the_author.clear();
                        About_the_author.display();
                    }
                }

                if(x==3)
                {
                    MENU.close();
                }
                break;
            }           
        }
    }
    MENU.clear();
    MENU.draw(background);
    menu.draw(MENU);
    MENU.display();
   }

    return 0;
}
