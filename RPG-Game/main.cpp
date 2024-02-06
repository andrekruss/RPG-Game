#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Skeleton.h"

int main()
{
    //-------------------------------INITIALIZATION-------------------------------//
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    int windowWidth = 1280, windowHeight = 800;
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "RPG Game", sf::Style::Default, settings);

    Player player;
    player.Initialize();
    player.Load();
    player.sprite.setPosition(sf::Vector2f(windowWidth / 2.0, windowHeight / 2.0));

    Skeleton skeleton;
    skeleton.Initialize();
    skeleton.Load();
    //-------------------------------INITIALIZATION-------------------------------//

    // Game Loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        skeleton.Update();
        player.Update(skeleton);

        window.clear(sf::Color::Black);
        player.Draw(window);
        skeleton.Draw(window);
        window.display();
    }

    return 0;
}

