#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

sf::Vector2f normalizeVector(sf::Vector2f vector);

int main()
{
    //-------------------------------INITIALIZATION-------------------------------//
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    int windowWidth = 1280, windowHeight = 800;
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "RPG Game", sf::Style::Default, settings);
    //-------------------------------INITIALIZATION-------------------------------//

    //-------------------------------LOAD-------------------------------//
    sf::Texture playerTexture;
    sf::Sprite playerSprite;
    sf::Texture skeletonTexture;
    sf::Sprite skeletonSprite;
    std::vector<sf::RectangleShape> bullets;
    //sf::RectangleShape bullet(sf::Vector2f(50.0f, 25.0f));
    int xPlayerSpriteIndex = 4, yPlayerSpriteIndex = 2;
    int xSkeletonSpriteIndex = 2, ySkeletonSpriteIndex = 3;
    int spriteWidth = 64, spriteHeight = 64;


    if (skeletonTexture.loadFromFile("Assets/Skeleton/Textures/spritesheet.png")) 
    {
        std::cout << "Skeleton texture succesfully loaded!" << std::endl;
        skeletonSprite.setTexture(skeletonTexture);
        skeletonSprite.setTextureRect(sf::IntRect(64 * xSkeletonSpriteIndex, 64 * ySkeletonSpriteIndex, spriteWidth, spriteHeight));
        skeletonSprite.scale(sf::Vector2f(3.0f, 3.0f));
    }

    else
    {
        std::cout << "Skeleton image failed to load!" << std::endl;
    }

    if (playerTexture.loadFromFile("Assets/Player/Textures/spritesheet.png"))
    {
        std::cout << "Player texture succesfully loaded!" << std::endl;
        playerSprite.setTexture(playerTexture);
        playerSprite.setTextureRect(sf::IntRect(64 * xPlayerSpriteIndex, 64 * yPlayerSpriteIndex, spriteWidth, spriteHeight));
        playerSprite.scale(sf::Vector2f(3.0f, 3.0f));
    }
    else
    {
        std::cout << "Player image failed to load!" << std::endl;
    }
    //-------------------------------LOAD-------------------------------//
    playerSprite.setPosition(sf::Vector2f(windowWidth / 2.0, windowHeight / 2.0));
    //skeletonSprite.setPosition(sf::Vector2f(400.0f, 400.0f));
    //bullet.setPosition(playerSprite.getPosition());
  
    sf::Vector2f enemyPosition;
    sf::Vector2f normalizedBulletDirection;
    // Game Loop
    while (window.isOpen())
    {
        //-------------------------------UPDATE-------------------------------//
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            sf::Vector2f previousPosition = playerSprite.getPosition();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                playerSprite.setPosition(previousPosition + sf::Vector2f(5, 0));

            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                playerSprite.setPosition(previousPosition + sf::Vector2f(-5, 0));         

            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                playerSprite.setPosition(previousPosition + sf::Vector2f(0, 5));

            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                playerSprite.setPosition(previousPosition + sf::Vector2f(0, -5));         

            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            {
                bullets.push_back(sf::RectangleShape(sf::Vector2f(50.0f, 25.0f)));
                int lastBulletIndex = bullets.size() - 1;
                bullets[lastBulletIndex].setPosition(playerSprite.getPosition());
            }
        }

        for (size_t i = 0; i < bullets.size(); i++)
        {
            sf::Vector2f bulletDirection;
            enemyPosition = skeletonSprite.getPosition();
            bulletDirection = enemyPosition - bullets[i].getPosition();
            normalizedBulletDirection = normalizeVector(bulletDirection);
            bullets[i].setPosition(bullets[i].getPosition() + normalizedBulletDirection);
        }

         //-------------------------------UPDATE-------------------------------//

         //-------------------------------DRAW-------------------------------//
            window.clear(sf::Color::Black);
            window.draw(playerSprite);
            window.draw(skeletonSprite);
            for (size_t i = 0; i < bullets.size(); i++)
            {
                window.draw(bullets[i]);
            }
            window.display();
            //-------------------------------DRAW-------------------------------//
    }

    return 0;
}

sf::Vector2f normalizeVector(sf::Vector2f vector) {
    float magnitude = sqrt(vector.x * vector.x + vector.y * vector.y);
    float speed = 0.1f; // using to make the projectile a bit slower
    return sf::Vector2f(speed * vector.x / magnitude, speed * vector.y / magnitude);
}