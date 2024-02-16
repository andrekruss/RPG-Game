#pragma once
#include "Skeleton.h"
#include "Bullet.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Player
{
private:
	sf::Texture texture;
	int sizeScaling;
	sf::Vector2i size;
	int spriteWidth, spriteHeight;
	int xSpriteIndex, ySpriteIndex;
	float maxFireRate;
	float fireRateTimer;
	float speed;
	std::vector<Bullet> bullets;
	sf::RectangleShape boundingRectangle;
public:
	sf::Sprite sprite;
public:
	Player();
	~Player();
	void Initialize(); // called only once
	void Load(); // called onde per APP start
	void Update(float deltaTime, Skeleton& skeleton, sf::Vector2f& mousePosition); // once per frame
	void Draw(sf::RenderWindow& window); // once per frame
};