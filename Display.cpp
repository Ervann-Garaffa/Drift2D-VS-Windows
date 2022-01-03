#include "Display.h"

void Display::Init()
{
	
}

Display::Display(const char name[], const unsigned int width, const unsigned int height)
	: m_isActive(false), m_NAME(name), m_DIMENSIONS({(unsigned int)width, (unsigned int)height})
{
	if (m_NAME == "Menu")
	{
		m_isActive = true;

		sf::RectangleShape b_play;
		b_play.setOutlineColor(sf::Color::Red);
		b_play.setPosition(120, 200);
		b_play.setSize(sf::Vector2f(80, 40));

		m_displayedObjects.clear();
		m_displayedObjects.emplace_back(b_play);

		std::cout << "Init 1st button" << std::endl;
	}
	else
	{

	}
}

Display::~Display()
{
}


std::vector<sf::RectangleShape> Display::RenderButtons()
{
	return m_displayedObjects;
}

std::vector<sf::Text> Display::RenderTexts()
{
	return m_displayedTexts;
}
