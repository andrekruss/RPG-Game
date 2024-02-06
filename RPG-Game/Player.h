#pragma once
#include "Skeleton.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Player
{
private:
	sf::Texture texture;
	float bulletSpeed = 0.5f;
	std::vector<sf::RectangleShape> bullets;
public:
	sf::Sprite sprite;
public:
	void Initialize(); // called only once
	void Load(); // called onde per APP start
	void Update(Skeleton& skeleton); // once per frame
	void Draw(sf::RenderWindow& window); // once per frame
};