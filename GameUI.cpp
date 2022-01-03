#include "GameUI.h"

GameUI::GameUI(sf::Font& font)
	: m_actionID(""), m_moveAction{ false, false, false, false, false }
{
	this->Init(font);
}

GameUI::~GameUI()
{
}

void GameUI::Init(sf::Font& font)
{
	m_BUTTON_LIST.clear();
	m_UI_TEXT_LIST.clear();

	/* FONT now managed globally
	if (!font.loadFromFile("res/Calibri.ttf"))
		std::cout << "Could not load font" << '\n'; // Error
	*/

	m_BUTTON_LIST.reserve(1);
	m_BUTTON_LIST.emplace_back("MENU", font, 30.0f, 740.0f);

	m_UI_TEXT_LIST.reserve(10);

	if (!trackTexture.loadFromFile("res/circuit-terre.jpg"))
		std::cout << "Could not load image" << '\n'; // Error
	else
		trackSprite.setTexture(trackTexture);
}

void GameUI::EventHandler(const sf::Event& event, bool& menu_isOpen, sf::RenderWindow* target)
{
	if (event.type == sf::Event::EventType::MouseButtonReleased)
		for (auto& button : this->m_BUTTON_LIST)
			if ((m_actionID == "") && (button.Identify(event.mouseButton.x, event.mouseButton.y) != ""))
				m_actionID = button.Identify(event.mouseButton.x, event.mouseButton.y);

	if (m_actionID == "MENU")
		menu_isOpen = true;

	// m_moveAction Bool table allows for multiple key presses while playing

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		m_moveAction[0] = true;
	else
		m_moveAction[0] = false;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		m_moveAction[1] = true;
	else
		m_moveAction[1] = false;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		m_moveAction[2] = true;
	else
		m_moveAction[2] = false;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		m_moveAction[3] = true;
	else
		m_moveAction[3] = false;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		m_moveAction[4] = true;
	else
		m_moveAction[4] = false;

	// User driving commands console log
	for (int i = 0; i < sizeof(m_moveAction); i++)
		std::cout << m_moveAction[i];
	std::cout << '\n';

	// User menu commands console log
	if (m_actionID != "")
		std::cout << m_actionID << '\n';
}

void GameUI::Update(sf::RenderWindow* target)
{
	if (trackSprite.getTexture())
	{
		trackSprite.setScale(8.f, 8.f);
		trackSprite.setPosition(sf::Vector2f(
			target->getSize().x / 2.f - trackSprite.getGlobalBounds().width / 2.f,
			0.f));
	}
}

void GameUI::Render(sf::RenderWindow* target)
{
	Update(target);

	if (trackSprite.getTexture())
		target->draw(trackSprite);

	for (auto& button : this->m_BUTTON_LIST)
		button.Render(target);
}
