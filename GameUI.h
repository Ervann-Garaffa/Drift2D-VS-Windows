#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"
#include "Button.h"
#include "Map.h"

class GameUI
{
private:
	bool m_moveAction[5];

	sf::Texture trackTexture;
	sf::Sprite trackSprite;

public:
	std::vector<UiElement> m_BUTTON_LIST;
	std::vector<sf::Text> m_UI_TEXT_LIST;
	std::string m_actionID;

	GameUI(sf::Font& font);
	~GameUI();

	void Init(sf::Font& font);

	void EventHandler(const sf::Event& event, bool& menu_isOpen, sf::RenderWindow* target);
	void Update(sf::RenderWindow* target);
	void Render(sf::RenderWindow* target);
};