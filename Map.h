#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"

class Map
{
private:
	const std::string m_NAME;	
	struct coord { double X; double Y; };
	const coord m_size;

	sf::Texture trackTexture;
	sf::Sprite trackSprite;

public:
	coord m_pos;

	Map(const std::string name);
	~Map();

	void UpdatePos();
	void Render(sf::RenderWindow* target);
};
