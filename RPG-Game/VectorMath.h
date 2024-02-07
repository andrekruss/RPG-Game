#pragma once
#include <SFML/Graphics.hpp>

static class VectorMath
{
public:
	static sf::Vector2f normalizeVector(sf::Vector2f vector);
	static bool CheckCollision(sf::FloatRect rect1, sf::FloatRect rect2);
};

