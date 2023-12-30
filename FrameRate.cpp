#include "FrameRate.hpp"
#include <iostream>


FrameRate::FrameRate() : timer(0) //gdy tworzony jest obiekt, timer jest inicjalizowany i ustawiany na 0
{
}

FrameRate::~FrameRate()
{
}

void FrameRate::Initialize()
{
}

void FrameRate::Load()
{

if(font.loadFromFile("font/font.ttf"))
{
    std::cout<<"Font has been loaded successfully"<<std::endl;
    frameRateText.setFont(font);
}

else
{
    std::cout<<"Failed to load the font"<<std::endl;
}
}

void FrameRate::Update(double deltaTime)
{
    timer += deltaTime; // 16.667?
    
    if(timer>=100.0)
    {
        double fps = 1000.0 / deltaTime;
        frameRateText.setString("FPS: " + std::to_string((int)fps) + " Frame time: " + std::to_string((int)(deltaTime)));
        timer = 0;
    }
}

void FrameRate::Draw(sf::RenderWindow& window)
{
    window.draw(frameRateText);
}