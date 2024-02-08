#include "FrameRate.h"
#include <iostream>

#define UPDATE_TIME 100.0

FrameRate::FrameRate() : 
    timer(0)
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
    if (!font.loadFromFile("assets/fonts/arial.ttf"))
    {
        std::cout << "Error loading font" << std::endl;
    }
    else
    {
        text.setFont(font);
    }
}

void FrameRate::Update(double deltaTime)
{
    timer += deltaTime;

    if (!(timer >= UPDATE_TIME))
    {
        return;
    }

    frameRateInfo = "FPS: "
        + std::to_string(int(1000.0 / deltaTime))
        + " FrameTime: "
        + std::to_string(int(deltaTime));
    text.setString(frameRateInfo);

    timer = 0;
}

void FrameRate::Draw(sf::RenderWindow& window)
{
    window.draw(text);
}
