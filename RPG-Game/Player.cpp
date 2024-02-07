#include "Player.h"
#include "VectorMath.h"
#include <iostream>

void Player::Initialize()
{
    size = sf::Vector2i(spriteWidth, spriteHeight);
    boundingRectangle.setSize(sf::Vector2f(sizeScaling * size.x, sizeScaling * size.y));
    boundingRectangle.setOutlineThickness(2.0f);
    boundingRectangle.setFillColor(sf::Color::Transparent);
    boundingRectangle.setOutlineColor(sf::Color::Blue);
}

void Player::Load()
{
    if (texture.loadFromFile("Assets/Player/Textures/spritesheet.png"))
    {
        std::cout << "Player texture succesfully loaded!" << std::endl;
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(xSpriteIndex * size.x, ySpriteIndex * size.y, spriteWidth, spriteHeight));
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

    boundingRectangle.setPosition(sprite.getPosition());

    if (VectorMath::CheckCollision(sprite.getGlobalBounds(), skeleton.sprite.getGlobalBounds()))
    {
        std::cout << "Collision!" << std::endl;
    }
}

void Player::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
    window.draw(boundingRectangle);
    for (size_t i = 0; i < bullets.size(); i++)
    {
        window.draw(bullets[i]);
    }
}
