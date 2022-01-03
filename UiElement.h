#pragma once

#include <iostream>
#include <string>
#include "SFML/Graphics.hpp"

class UiElement
{
protected:
	const std::string m_NAME;
	const unsigned int m_CHARACTER_SIZE;
	const sf::Color m_TEXT_COLOR;
	const sf::Vector2f m_POSITION;
	const sf::Vector2f m_DIMENSIONS;
	sf::Font m_FONT;

public:
	sf::RectangleShape m_frame;
	sf::Text m_caption;

	UiElement(const std::string name, const sf::Font &font, const float X, const float Y, const float WIDTH = 120, const float HEIGHT = 40);
	~UiElement();

	void Init();
	void Update();
	void Render(sf::RenderWindow* target);
	std::string Identify(const int x, const int y);
};

