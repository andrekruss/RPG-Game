#include "Player.h"
#include "VectorMath.h"
#include <iostream>

Player::Player() :
    speed(3.0f),
    xSpriteIndex(4),
    ySpriteIndex(2),
    spriteWidth(64),
    spriteHeight(64),
    sizeScaling(3),
    maxFireRate(500.0f),
    fireRateTimer(0)
{
}

Player::~Player()
{
}

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

void Player::Update(float deltaTime, Skeleton& skeleton, sf::Vector2f& mousePosition)
{
    sf::Vector2f previousPosition = sprite.getPosition();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        sprite.setPosition(previousPosition + sf::Vector2f(1, 0) * deltaTime * speed);

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        sprite.setPosition(previousPosition + sf::Vector2f(-1, 0) * deltaTime * speed);

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        sprite.setPosition(previousPosition + sf::Vector2f(0, 1) * deltaTime * speed);

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        sprite.setPosition(previousPosition + sf::Vector2f(0, -1) * deltaTime * speed);

    fireRateTimer += deltaTime;
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && fireRateTimer >= maxFireRate)
    {
        bullets.push_back(Bullet());
        int lastBulletIndex = bullets.size() - 1;
        bullets[lastBulletIndex].Initialize(sprite.getPosition(), mousePosition, 2.5f);
        fireRateTimer = 0;
    }

    for (size_t i = 0; i < bullets.size(); i++)
    {
        //sf::Vector2f bulletDirection;
        ////sf::Vector2f enemyPosition = skeleton.sprite.getPosition();
        //bulletDirection = mousePosition - bullets[i].getPosition();
        //sf::Vector2f normalizedBulletDirection = VectorMath::normalizeVector(bulletDirection);
        //bullets[i].setPosition(bullets[i].getPosition() + normalizedBulletDirection * bulletSpeed * deltaTime);

        bullets[i].Update(deltaTime);
        if (skeleton.health > 0)
        {
            if (VectorMath::CheckCollision(bullets[i].GetGlobalBounds(), skeleton.sprite.getGlobalBounds()))
            {
                skeleton.ChangeHealth(-10);
                bullets.erase(bullets.begin() + i);
            }
        }
    }

    boundingRectangle.setPosition(sprite.getPosition());
}

void Player::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
    window.draw(boundingRectangle);
    for (size_t i = 0; i < bullets.size(); i++)
    {
        bullets[i].Draw(window);
    }
}
