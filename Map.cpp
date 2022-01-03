#include "Map.h"

Map::Map(const std::string name)
	:m_NAME(name), m_pos({ 0,0 }), m_size({ 0,0 })
{
	if (!trackTexture.loadFromFile("res/circuit-terre.jpg"))
		std::cout << "Could not load image" << '\n'; // Error
	else
		trackSprite.setTexture(trackTexture);
}

Map::~Map()
{
}

void Map::UpdatePos()
{
}

void Map::Render(sf::RenderWindow* target)
{
}
