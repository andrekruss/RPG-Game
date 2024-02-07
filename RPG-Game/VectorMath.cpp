#include "VectorMath.h"

sf::Vector2f VectorMath::normalizeVector(sf::Vector2f vector)
{
    float magnitude = sqrt(vector.x * vector.x + vector.y * vector.y);
    float speed = 0.1f; // using to make the projectile a bit slower
    return sf::Vector2f(speed * vector.x / magnitude, speed * vector.y / magnitude);
}

bool VectorMath::CheckCollision(sf::FloatRect rect1, sf::FloatRect rect2)
{
    if (rect1.left + rect1.width > rect2.left &&
        rect2.left + rect1.width > rect1.left &&
        rect2.top + rect2.height > rect1.top &&
        rect1.top + rect1.height > rect2.top)
        return true;

    return false;

}
