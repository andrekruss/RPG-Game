#pragma once
#include <SFML/Graphics.hpp>

class Skeleton
{
private:
	sf::Texture texture;
	int sizeScaling = 3;
	int spriteWidth = 64, spriteHeight = 64;
	int xSpriteIndex = 4, ySpriteIndex = 2;
	sf::Vector2i size;
	sf::RectangleShape boundingRectangle;
public:
	sf::Sprite sprite;
public:
	void Initialize();
	void Load();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
};

