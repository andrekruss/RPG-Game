#include "VectorMath.h"

sf::Vector2f VectorMath::normalizeVector(sf::Vector2f vector)
{
    float magnitude = sqrt(vector.x * vector.x + vector.y * vector.y);
    float speed = 0.1f; // using to make the projectile a bit slower
    return sf::Vector2f(speed * vector.x / magnitude, speed * vector.y / magnitude);
}
