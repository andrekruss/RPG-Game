#include "Player.h"
#include "VectorMath.h"
#include <iostream>

void Player::Initialize()
{
}

void Player::Load()
{
    int xSpriteIndex = 4, ySpriteIndex = 2;
    int spriteWidth = 64, spriteHeight = 64;
    if (texture.loadFromFile("Assets/Player/Textures/spritesheet.png"))
    {
        std::cout << "Player texture succesfully loaded!" << std::endl;
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(64 * xSpriteIndex, 64 * ySpriteIndex, spriteWidth, spriteHeight));
        sprite.scale(sf::Vector2f(3.0f, 3.0f));
    }
    else
    {
        std::cout << "Player image failed to load!" << std::endl;
    }
}

void Player::Update(Skeleton& skeleton)
{
    sf::Vector2f previousPosition = sprite.getPosition();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        sprite.setPosition(previousPosition + sf::Vector2f(1, 0));

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        sprite.setPosition(previousPosition + sf::Vector2f(-1, 0));

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        sprite.setPosition(previousPosition + sf::Vector2f(0, 1));

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        sprite.setPosition(previousPosition + sf::Vector2f(0, -1));

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        bullets.push_back(sf::RectangleShape(sf::Vector2f(50.0f, 25.0f)));
        int lastBulletIndex = bullets.size() - 1;
        bullets[lastBulletIndex].setPosition(sprite.getPosition());
    }

    for (size_t i = 0; i < bullets.size(); i++)
    {
        sf::Vector2f bulletDirection;
        sf::Vector2f enemyPosition = skeleton.sprite.getPosition();
        bulletDirection = enemyPosition - bullets[i].getPosition();
        sf::Vector2f normalizedBulletDirection = VectorMath::normalizeVector(bulletDirection);
        bullets[i].setPosition(bullets[i].getPosition() + normalizedBulletDirection);
    }
}

void Player::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
    for (size_t i = 0; i < bullets.size(); i++)
    {
        window.draw(bullets[i]);
    }
}
