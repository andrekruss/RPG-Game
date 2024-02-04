#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

int main()
{
    //-------------------------------INITIALIZATION-------------------------------//
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    int windowWidth = 1280, windowHeight = 800;
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "RPG Game", sf::Style::Default, settings);
    //-------------------------------INITIALIZATION-------------------------------//

    //-------------------------------LOAD-------------------------------//
    sf::Texture skeletonTexture;
    sf::Sprite skeletonSprite;
    sf::Texture playerTexture;
    sf::Sprite playerSprite;
    int xPlayerSpriteIndex = 4, yPlayerSpriteIndex = 2;
    int xSkeletonSpriteIndex = 2, ySkeletonSpriteIndex = 3;
    int spriteWidth = 64, spriteHeight = 64;


    if (skeletonTexture.loadFromFile("Assets/Skeleton/Textures/spritesheet.png")) 
    {
        std::cout << "Skeleton texture succesfully loaded!" << std::endl;
        skeletonSprite.setTexture(skeletonTexture);

        skeletonSprite.setTextureRect(sf::IntRect(64 * xSkeletonSpriteIndex, 64 * ySkeletonSpriteIndex, spriteWidth, spriteHeight));
        skeletonSprite.scale(sf::Vector2f(3.0f, 3.0f));
        skeletonSprite.setPosition(sf::Vector2f(400.0f, 400.0f));
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
        }

         //-------------------------------UPDATE-------------------------------//

         //-------------------------------DRAW-------------------------------//
            window.clear(sf::Color::Black);
            window.draw(playerSprite);
            window.draw(skeletonSprite);
            window.display();
            //-------------------------------DRAW-------------------------------//
    }

    return 0;
}