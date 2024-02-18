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
        std::cout << "Loaded prison tilesheet!" << std::endl;;
        
        for (size_t i = 0; i < NUMBER_OF_SPRITES; i++) {
            sprites[i].setTexture(tileSheetTexture);
            sprites[i].setTextureRect(sf::IntRect(i * tileWidth, i * tileHeight, tileWidth, tileHeight));
            sprites[i].setScale(sf::Vector2f(5.0f, 5.0f));
            sprites[i].setPosition(sf::Vector2f(100 + tileWidth * i * 5, 100));
        }
    }
    else
    {
        std::cout << "Failed to load prison tilesheet!" << std::endl;
    }
}

void Map::Update(float deltaTime)
{
}

void Map::Draw(sf::RenderWindow& window)
{
    for (size_t i = 0; i < NUMBER_OF_SPRITES; i++) {
        window.draw(sprites[i]);
    }
}
