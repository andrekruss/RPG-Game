#pragma once
#include <SFML/Graphics.hpp>

class FrameRate
{
private:
	sf::Text text;
	sf::Font font;
public:
	std::string frameRateInfo;
	double timer = 0;
public:
	FrameRate();
	~FrameRate();

	void Initialize();
	void Load();
	void Update(double deltaTime);
	void Draw(sf::RenderWindow& window);
};

