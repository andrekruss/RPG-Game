#include "Skeleton.h"
#include <iostream>

Skeleton::Skeleton() : 
    xSpriteIndex(6),
    ySpriteIndex(3),
    spriteWidth(64),
    spriteHeight(64),
    sizeScaling(3),
    health(100)
{
}

Skeleton::~Skeleton()
{
}

void Skeleton::Initialize()
{
    size = sf::Vector2i(spriteWidth, spriteHeight);
    boundingRectangle.setSize(sf::Vector2f(sizeScaling * size.x, sizeScaling * size.y));
    boundingRectangle.setOutlineThickness(2.0f);
    boundingRectangle.setFillColor(sf::Color::Transparent);
    boundingRectangle.setOutlineColor(sf::Color::Red);
}

void Skeleton::Load()
{
    if (!font.loadFromFile("assets/fonts/arial.ttf"))
    {
        std::cout << "Error loading font" << std::endl;
    }
    else
    {
        healthText.setFont(font);
        healthText.setString(std::to_string(health));
    }

    if (texture.loadFromFile("Assets/Skeleton/Textures/spritesheet.png"))
    {
        std::cout << "Skeleton texture succesfully loaded!" << std::endl;
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(size.x * xSpriteIndex, size.y * ySpriteIndex, spriteWidth, spriteHeight));
        sprite.scale(sf::Vector2f(3.0f, 3.0f));
        sprite.setPosition(sf::Vector2f(200.0f, 200.0f));
        healthText.setPosition(sprite.getPosition());
    }

    else
    {
        std::cout << "Skeleton image failed to load!" << std::endl;
    }

}

void Skeleton::Update(float deltaTime)
{
    if (health > 0) {
        boundingRectangle.setPosition(sprite.getPosition());
        healthText.setPosition(sprite.getPosition());
    }
}

void Skeleton::Draw(sf::RenderWindow& window)
{
    if (health > 0) {
        window.draw(boundingRectangle);
        window.draw(sprite);
        window.draw(healthText);
    }
}

void Skeleton::ChangeHealth(int hp)
{
    health += hp;
    healthText.setString(std::to_string(health));
}
