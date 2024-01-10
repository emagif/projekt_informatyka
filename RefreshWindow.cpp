#include "RefreshWindow.hpp"
#include <iostream>


RefreshWindow::RefreshWindow()
{

}

// wrócić do tego 
void RefreshWindow::StopGame(sf::RenderWindow& window, sf::Event& event)
{
    
    while(window.pollEvent(event))
    {
        if(event.type == sf::Event::KeyPressed)
        {
            if(event.key.code == sf::Keyboard::F1)
            {
                gameActive = false;
                window.setActive(false);
                
                sf::RenderWindow helpWindow(sf::VideoMode(918, 515), "Help window");
                sf::Font font;
                sf::Texture backgroundTexture;
                backgroundTexture.loadFromFile("Tiles/background.png");
                sf::Sprite backgroundSprite(backgroundTexture);

                if(!font.loadFromFile("font/font.ttf"))
                {
                    std::cout<<"The programmer made a mistake"<<std::endl;
                }

                sf::Text text1("Aby wrocic do gry wcisnij P", font, 30);
                text1.setColor(sf::Color::Red);

                sf::Text text2("A - ruch w lewo", font, 30);
                text2.setColor(sf::Color::Red);

                sf::Text text3("D - ruch w prawo", font, 30);
                text3.setColor(sf::Color::Red);

                sf::Text text4("W - ruch do gory", font, 30);
                text4.setColor(sf::Color::Red);

                sf::Text text5("S - ruch do dolu", font, 30);
                text5.setColor(sf::Color::Red);

                sf::Text text6("K - zapisz wynik do pliku", font, 30);
                text6.setColor(sf::Color::Red);

                text1.setPosition(300, 50);
                text2.setPosition(300, 100);
                text3.setPosition(300, 150);
                text4.setPosition(300, 200);
                text5.setPosition(300, 250);
                text6.setPosition(300, 300);

                while(helpWindow.isOpen())
                {
                    sf::Event event;

                    while(helpWindow.pollEvent(event))
                    {
                        if(event.type == sf::Event::Closed)
                        {
                            helpWindow.close();
                        }
                    }

                    helpWindow.clear();
                    helpWindow.draw(backgroundSprite);
                    helpWindow.draw(text1);
                    helpWindow.draw(text2);
                    helpWindow.draw(text3);
                    helpWindow.draw(text4);
                    helpWindow.draw(text5);
                    helpWindow.draw(text6);
                    helpWindow.display();
                }


            }

        }

            if(event.key.code == sf::Keyboard::P)
            {
                gameActive = true;
                window.setActive(true);
            }
    }
}

bool RefreshWindow::IsGameActive() const
{
    return gameActive;
}

// void RefreshWindow::StopGame(sf::RenderWindow& window, sf::Event& event)
// {
//     while (window.pollEvent(event))
//     {
//         if (event.type == sf::Event::KeyPressed)
//         {
//             if (event.key.code == sf::Keyboard::F1)
//             {
//                 if(event.key.code == sf::Keyboard::Escape)
//                 {
//                     window.close();
//                 }
//                 // Tutaj dodać kod wyświetlający pomoc w bieżącym oknie gry
//                 // Użyć np. tekstu, sprite'ów lub innych elementów interfejsu

//                 // Przykładowo:
//                 sf::Font font;
//                 font.loadFromFile("font/font.ttf");
//                 sf::Text helpText("Pomoc - nacisnij P, aby kontynuowac", font, 24);
//                 sf::Text layer1("A - ruch w lewo", font, 24);
//                 sf::Text layer2("D - ruch w prawo", font, 24);
//                 sf::Text layer3("W - ruch do gory", font, 24);
//                 sf::Text layer4("S - ruch do dolu", font, 24);
//                 helpText.setPosition(50, 50);
//                 layer1.setPosition(50, 100);
//                 layer2.setPosition(50,150);
//                 layer3.setPosition(50,200);
//                 layer4.setPosition(50,250);
//                 window.setActive(false);

//                 bool showHelp = true;
//                 while (showHelp)
//                 {
//                     window.clear();
//                     window.draw(helpText);
//                     window.draw(layer1);
//                     window.draw(layer2);
//                     window.draw(layer3);
//                     window.draw(layer4);
//                     window.display();

//                     while (window.pollEvent(event))
//                     {
//                         if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P)
//                         {
//                             showHelp = false;
//                             window.setActive(true);
//                             if(event.key.code == sf::Keyboard::Escape)
//                             {
//                                 window.close();
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//     }
// }


// void RefreshWindow::StopGame(sf::RenderWindow& window, sf::Event& event)
// {
//     sf::RenderWindow help(sf::VideoMode(1280, 960), "Help");
//     sf::Font font;
//     font.loadFromFile("font/font.ttf");

//     sf::Text text1("Wcisnij P, aby wrocic do gry", font, 24);
//     sf::Text text2("A - ruch w lewo", font, 24);
//     sf::Text text3("D - ruch w prawo", font, 24);
//     sf::Text text4("W - ruch do gory", font, 24);
//     sf::Text text5("S - ruch do dolu", font, 24);

//     text1.setPosition(50, 50);
//     text2.setPosition(50, 100);
//     text3.setPosition(50, 150);
//     text4.setPosition(50, 200);
//     text5.setPosition(50, 250);

//     bool showHelp = false;

//     while (window.pollEvent(event))
//     {
//         if (event.type == sf::Event::KeyPressed)
//         {
//             if (event.key.code == sf::Keyboard::F1)
//             {
//                 showHelp = true;
//                 gameActive = false;
//                 window.setActive(false);
//             }
//         }
//     }

//     if (showHelp)
//     {
//         while (help.isOpen())
//         {
//             help.clear();
//             help.draw(text1);
//             help.draw(text2);
//             help.draw(text3);
//             help.draw(text4);
//             help.draw(text5);
//             help.display();

//             while (help.pollEvent(event))
//             {
//                 if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P)
//                 {
//                     help.close();
//                     gameActive = true;
//                     window.setActive(true);
//                 }
//             }
//         }
//     }
// }
