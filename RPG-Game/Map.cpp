#include "Map.h"
#include <iostream>

Map::Map() :
    tileHeight(16),
    tileWidth(16),
    totalTilesX(0),
    totalTilesY(0)
{
}

Map::~Map()
{
}

void Map::Initialize()
{
}

void Map::Load()
{
    if (tileSheetTexture.loadFromFile("Assets/World/Prison/tilesheet.png"))
    {

        totalTilesX = tileSheetTexture.getSize().x / tileWidth;
        totalTilesY = tileSheetTexture.getSize().y / tileHeight;

        numberOfTiles = totalTilesX * totalTilesY;

        tiles = new Tile[numberOfTiles];

        for (size_t y = 0; y < totalTilesY; y++) {
            for (size_t x = 0; x < totalTilesX; x++) {
                int i = x + y * totalTilesX;
                tiles[i].id = x;
                tiles[i].position = sf::Vector2i(x * tileWidth, y * tileHeight);
            }
        }
    }
    else
    {
        std::cout << "Failed to load prison tilesheet!" << std::endl;
    }

    for (size_t y = 0; y < 2; y++)
    {
        for (size_t x = 0; x < 3; x++)
        {
            int i = x + y * 3;
            int index = mapNumbers[i];
            mapSprites[i].setTexture(tileSheetTexture);
            mapSprites[i].setTextureRect(sf::IntRect(
                tiles[index].position.x,
                tiles[index].position.y,
                tileWidth,
                tileHeight
                ));
            mapSprites[i].setPosition(sf::Vector2f(x * 16 * 5, y * 16 * 5));
            mapSprites[i].setScale(sf::Vector2f(5, 5));
        }
    }
}

void Map::Update(float deltaTime)
{
}

void Map::Draw(sf::RenderWindow& window)
{
    for (size_t i = 0; i < 6; i++) {
        window.draw(mapSprites[i]);
    }
}
