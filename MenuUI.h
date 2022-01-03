#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"
#include "Button.h"

class MenuUI
{
private:
	const std::string m_NAME;

	sf::Texture mainMenuLogoTexture;
	sf::Sprite mainMenuLogoSprite;

public:
	std::vector<UiElement> m_BUTTON_LIST;
	std::vector<sf::Text> m_UI_TEXT_LIST;
	std::string m_actionID;

	MenuUI(const std::string name, sf::Font& font);
	~MenuUI();

	void Init(sf::Font& font);

	void EventHandler(const sf::Event& event, bool& menu_isOpen, sf::RenderWindow* target);
	void Update(sf::RenderWindow* target);
	void Render(sf::RenderWindow* target);
};