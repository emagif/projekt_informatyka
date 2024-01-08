#include "RefreshWindow.hpp"

RefreshWindow::RefreshWindow()
{

}

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
            }

            if(event.key.code == sf::Keyboard::P)
            {
                gameActive = true;
                window.setActive(true);
            }
        }
    }
}

bool RefreshWindow::IsGameActive() const
{
    return gameActive;
}