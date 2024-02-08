#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Skeleton.h"
#include "FrameRate.h"

int main()
{
    //-------------------------------INITIALIZATION-------------------------------//
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    int windowWidth = 1280, windowHeight = 800;
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "RPG Game", sf::Style::Default, settings);
    window.setFramerateLimit(60);

    Player player;
    player.Initialize();
    player.Load();
    player.sprite.setPosition(sf::Vector2f(windowWidth / 2.0, windowHeight / 2.0));

    Skeleton skeleton;
    skeleton.Initialize();
    skeleton.Load();

    FrameRate frameRate;
    frameRate.Initialize();
    frameRate.Load();
    //-------------------------------INITIALIZATION-------------------------------//

    sf::Clock clock;
    sf::Time timer;
    double deltaTime;
    // Game Loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        timer = clock.restart();
        deltaTime = timer.asMicroseconds() / 1000.0;

        frameRate.Update(deltaTime);
        skeleton.Update(deltaTime);
        player.Update(deltaTime, skeleton);

        window.clear(sf::Color::Black);
        player.Draw(window);
        skeleton.Draw(window);
        frameRate.Draw(window);
        window.display();
    }

    return 0;
}

