#include <SFML/Graphics.hpp>

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(800, 600), "RPG Game", sf::Style::Default, settings);

    sf::CircleShape circle(50.0f);
    circle.setFillColor(sf::Color::Red);
    circle.setPosition(sf::Vector2f(100.0f, 100.0f)); //POSITION IS ALWAYS TOP-LEFT IN SFML
    circle.setOutlineThickness(10.0f);
    circle.setOutlineColor(sf::Color::Blue);

    sf::RectangleShape rectangle(sf::Vector2f(40.0f, 40.0f));
    rectangle.setFillColor(sf::Color::Magenta);
    rectangle.setPosition(sf::Vector2f(200.0f, 200.0f));
    rectangle.setOutlineThickness(5.0f);
    rectangle.setOutlineColor(sf::Color::Cyan);
    //rectangle.rotate(45.0f);

    // Regular polygons(triangle, square, octagons, etc) can be represented by using CircleShape class
    sf::CircleShape triangle(50.0f, 3);
    triangle.setFillColor(sf::Color::Yellow);
    triangle.setPosition(sf::Vector2f(350.0f, 350.0f));

    

    // Game Loop
    while (window.isOpen())
    {
        //-------------------------------UPDATE-------------------------------//
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
         //-------------------------------UPDATE-------------------------------//

         //-------------------------------DRAW-------------------------------//
            window.clear(sf::Color::Black);
            window.draw(circle);
            window.draw(rectangle);
            window.draw(triangle);
            window.display();
            //-------------------------------DRAW-------------------------------//
        }
    }

    return 0;
}