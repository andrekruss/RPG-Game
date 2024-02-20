#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.h"

class Map
{
private:
	sf::Texture tileSheetTexture;
	Tile* tiles;
	int numberOfTiles;
	int tileWidth;
	int tileHeight;
	int totalTilesX;
	int totalTilesY;
	int mapNumbers[6] = { 	1, 1, 1, 25, 27, 30};
	sf::Sprite mapSprites[6];
public:
	Map();
	~Map();
	void Initialize(); // called only once
	void Load(); // called onde per APP start
	void Update(float deltaTime); // once per frame
	void Draw(sf::RenderWindow& window); // once per frame
};

