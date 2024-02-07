#pragma once
#include "Skeleton.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Player
{
private:
	sf::Texture texture;
	int sizeScaling = 3;
	sf::Vector2i size;
	int spriteWidth = 64, spriteHeight = 64;
	int xSpriteIndex = 4, ySpriteIndex = 2;
	float bulletSpeed = 0.5f;
	std::vector<sf::RectangleShape> bullets;
	sf::RectangleShape boundingRectangle;
public:
	sf::Sprite sprite;
public:
	void Initialize(); // called only once
	void Load(); // called onde per APP start
	void Update(Skeleton& skeleton); // once per frame
	void Draw(sf::RenderWindow& window); // once per frame
};