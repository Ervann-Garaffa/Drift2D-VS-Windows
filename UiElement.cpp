#include "UiElement.h"

UiElement::UiElement(const std::string name, const sf::Font &font, const float X, const float Y, const float WIDTH, const float HEIGHT)
	: m_NAME(name), m_CHARACTER_SIZE(25), m_TEXT_COLOR(sf::Color::Black), 
	m_POSITION(sf::Vector2f(X, Y)), m_DIMENSIONS(sf::Vector2f(WIDTH, HEIGHT)), 
	m_FONT(font)
{
	this->Init();
}

UiElement::~UiElement()
{
}

void UiElement::Init()
{
	m_frame.setFillColor(sf::Color::White);
	m_frame.setOutlineColor(sf::Color::Black);
	m_frame.setOutlineThickness(3.f);
	m_frame.setPosition(m_POSITION);
	m_frame.setSize(m_DIMENSIONS);

	m_caption.setFont(m_FONT);
	m_caption.setCharacterSize(m_CHARACTER_SIZE);
	m_caption.setFillColor(m_TEXT_COLOR);
	m_caption.setString(m_NAME);
	m_caption.setPosition(
		m_POSITION.x + m_DIMENSIONS.x / 2 - m_caption.getGlobalBounds().width / 2.f,
		m_POSITION.y + m_DIMENSIONS.y / 2 - m_caption.getGlobalBounds().height);
}

void UiElement::Update()
{
}

void UiElement::Render(sf::RenderWindow* target)
{
	target->draw(this->m_frame);
	target->draw(this->m_caption);
}

std::string UiElement::Identify(const int X, const int Y)
{
	if ((X > this->m_POSITION.x) && (X < (this->m_POSITION.x + this->m_DIMENSIONS.x)) &&
		(Y > this->m_POSITION.y) && (Y < (this->m_POSITION.y + this->m_DIMENSIONS.y)))

		return this->m_NAME;
	else
		return "";
}
