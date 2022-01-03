#include "MenuUI.h"

MenuUI::MenuUI(const std::string name, sf::Font& font)
	: m_NAME(name), m_actionID("")
{
	this->Init(font);
}

MenuUI::~MenuUI()
{
}

void MenuUI::Init(sf::Font& font)
{
	m_BUTTON_LIST.clear();
	m_UI_TEXT_LIST.clear();

	/* FONT now managed globally
	if (!font.loadFromFile("res/Calibri.ttf"))
		std::cout << "Could not load font" << '\n'; // Error
	*/

	m_BUTTON_LIST.reserve(2);
	m_BUTTON_LIST.emplace_back("JOUER", font, 540.0f, 320.0f);
	m_BUTTON_LIST.emplace_back("QUITTER", font, 540.0f, 480.0f);

	if (!mainMenuLogoTexture.loadFromFile("res/D2D-logo.png"))
		std::cout << "Could not load image" << '\n'; // Error
	else
		mainMenuLogoSprite.setTexture(mainMenuLogoTexture);
}

void MenuUI::EventHandler(const sf::Event& event, bool& menu_isOpen, sf::RenderWindow* target)
{
	if (event.type == sf::Event::EventType::MouseButtonReleased)
		for (auto& button : this->m_BUTTON_LIST)
			if ((m_actionID == "") && (button.Identify(event.mouseButton.x, event.mouseButton.y) != ""))
					m_actionID = button.Identify(event.mouseButton.x, event.mouseButton.y);

	if (m_actionID == "JOUER")
		menu_isOpen = false;

	if (m_actionID == "QUITTER")
		target->close();
		
	// User menu commands console log
	if (m_actionID != "")
		std::cout << m_actionID << '\n';
}

void MenuUI::Update(sf::RenderWindow* target)
{
	if (mainMenuLogoSprite.getTexture())
	{
		mainMenuLogoSprite.setPosition(sf::Vector2f(
			target->getSize().x / 2.f - mainMenuLogoSprite.getGlobalBounds().width / 2.f,
			20.f));
	}
}

void MenuUI::Render(sf::RenderWindow* target)
{
	Update(target);

	if (mainMenuLogoSprite.getTexture())
		target->draw(mainMenuLogoSprite);

	for (auto& button : this->m_BUTTON_LIST)
		button.Render(target);
}