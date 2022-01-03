#pragma once

#include <iostream>

#include "SFML/Graphics.hpp"

class Game
{
private:
	bool m_isActive;
	const char* m_State;

public:
	Game();
	~Game();

	void Update();
};

