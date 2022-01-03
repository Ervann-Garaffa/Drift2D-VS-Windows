#pragma once

#include "SFML/Graphics.hpp"

class Display
{

private:
	bool m_isActive;
	const char* m_NAME;
	const sf::Vector2u m_DIMENSIONS;
	
	sf::VertexBuffer m_vertexBuffer;

public:
	
	Display(const char name[], const unsigned int width, const unsigned int height);
	~Display();
	void Render();
};

