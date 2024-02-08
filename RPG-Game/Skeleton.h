#pragma once
#include <SFML/Graphics.hpp>

class Skeleton
{
private:
	sf::Texture texture;
	int sizeScaling;
	int spriteWidth, spriteHeight;
	int xSpriteIndex, ySpriteIndex;
	sf::Vector2i size;
	sf::RectangleShape boundingRectangle;
public:
	sf::Sprite sprite;
public:
	Skeleton();
	~Skeleton();
	void Initialize();
	void Load();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
};

