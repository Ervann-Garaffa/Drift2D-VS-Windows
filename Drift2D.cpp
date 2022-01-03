#include "MenuUI.h"
#include "GameUI.h"

int main()
{
	// Create program window
	const sf::Vector2u WINDOW_DIMENSIONS = {1200, 800};
	sf::RenderWindow window(sf::VideoMode(WINDOW_DIMENSIONS.x, WINDOW_DIMENSIONS.y, sf::Style::None), "Drift2D");
	window.setVerticalSyncEnabled(true);
	window.setKeyRepeatEnabled(false);

	// Load window logo
	sf::Image icon;
	icon.loadFromFile("res/gt-86-logo.png");
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	// Load global game font
	sf::Font FONT;
	if (!FONT.loadFromFile("res/Calibri.ttf"))
		std::cout << "Could not load font" << '\n'; // Error

	MenuUI menuUI("Menu", FONT);
	GameUI gameUI(FONT);

	// Variable to switch between Menu and Game screens
	bool menu_isOpen = true;

	while (window.isOpen())
	{
		// Reset window and actions
		window.clear(sf::Color::White);
		menuUI.m_actionID = "";
		gameUI.m_actionID = "";

		// Event handlers, depending on active screen (Game or Menu)
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (menu_isOpen)
				menuUI.EventHandler(event, menu_isOpen, &window);
			else
				gameUI.EventHandler(event, menu_isOpen, &window);
		}

		// Render window content
		if (menu_isOpen)
			menuUI.Render(&window);
		else
			gameUI.Render(&window);

		window.display();
	}

	return EXIT_SUCCESS;
}