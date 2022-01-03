#pragma once

#include "UiElement.h"

class Button : public UiElement
{
private:

public:
	
	Button(const std::string name, const sf::Font& font, const float X, const float Y, const float WIDTH, const float HEIGHT);
	~Button();

	void Init();
};