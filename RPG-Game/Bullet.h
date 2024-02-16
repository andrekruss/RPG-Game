#pragma once

#include <SFML/Graphics.hpp>

class Bullet
{
private:
	sf::RectangleShape rectangleShape;
	sf::Vector2f direction;
public:
	float speed;
public:
	Bullet();
	~Bullet();
	void Initialize(const sf::Vector2f& position, const sf::Vector2f& target, float speed); 
	void Load(); 
	void Update(float deltaTime); 
	void Draw(sf::RenderWindow& window); 

	inline const sf::FloatRect& GetGlobalBounds() { return rectangleShape.getGlobalBounds();  }
};

