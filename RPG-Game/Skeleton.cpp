#include "Skeleton.h"
#include <iostream>

void Skeleton::Initialize()
{
}

void Skeleton::Load()
{
    int xSpriteIndex = 2, ySpriteIndex = 3;
    int spriteWidth = 64, spriteHeight = 64;

    if (texture.loadFromFile("Assets/Skeleton/Textures/spritesheet.png"))
    {
        std::cout << "Skeleton texture succesfully loaded!" << std::endl;
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(64 * xSpriteIndex, 64 * ySpriteIndex, spriteWidth, spriteHeight));
        sprite.scale(sf::Vector2f(3.0f, 3.0f));
    }

    else
    {
        std::cout << "Skeleton image failed to load!" << std::endl;
    }
}

void Skeleton::Update()
{
}

void Skeleton::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}
