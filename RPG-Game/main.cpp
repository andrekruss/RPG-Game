#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    //-------------------------------INITIALIZATION-------------------------------//
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(800, 600), "RPG Game", sf::Style::Default, settings);
    //-------------------------------INITIALIZATION-------------------------------//

    //-------------------------------LOAD-------------------------------//
    sf::Texture playerTexture;
    sf::Sprite playerSprite;

    if (playerTexture.loadFromFile("Assets/Player/Textures/spritesheet.png"))
    {
        std::cout << "Player texture succesfully loaded!" << std::endl;
        playerSprite.setTexture(playerTexture);

        int xIndex = 0, yIndex = 0;
        int width = 64, height = 64;

        playerSprite.setTextureRect(sf::IntRect(64 * xIndex, 64 * yIndex, width, height));
        playerSprite.scale(sf::Vector2f(3, 3));
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
            window.display();
            //-------------------------------DRAW-------------------------------//
    }

    return 0;
}