#include "Bullet.h"
#include "VectorMath.h"

Bullet::Bullet() :
	speed(0)
{
}

Bullet::~Bullet()
{
}

void Bullet::Initialize(const sf::Vector2f& position, const sf::Vector2f& target, float speed)
{
	this->speed = speed;
	rectangleShape.setSize(sf::Vector2f(50.0f, 50.0f));
	rectangleShape.setPosition(position);
	direction = VectorMath::normalizeVector(target - position);
}

void Bullet::Load()
{
}

void Bullet::Update(float deltaTime)
{
	rectangleShape.setPosition(rectangleShape.getPosition() + direction * speed * deltaTime);
}

void Bullet::Draw(sf::RenderWindow& window)
{
	window.draw(rectangleShape);
}
