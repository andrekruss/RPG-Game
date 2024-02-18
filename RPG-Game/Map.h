#pragma once
#include <SFML/Graphics.hpp>

#define NUMBER_OF_SPRITES 10

class Map
{
private:
	sf::Texture tileSheetTexture;
	sf::Sprite sprites[NUMBER_OF_SPRITES];
	int tileWidth;
	int tileHeight;
	int totalTilesX;
	int totalTilesY;
public:
	Map();
	~Map();
	void Initialize(); // called only once
	void Load(); // called onde per APP start
	void Update(float deltaTime); // once per frame
	void Draw(sf::RenderWindow& window); // once per frame
};

