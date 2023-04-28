#include "Button.h"

void Button::Draw(sf::RenderWindow& window)
{
    window.draw(button);
    window.draw(text);
}

Button::Button(std::string st, const sf::Vector2f& p, sf::Font& f) : position(p)
{

    button.setSize(size);
    button.setPosition(position);
    button.setFillColor(backgroundNormal);
    text.setFont(f);
    text.setPosition(position+(sf::Vector2f(40, 20)));
    text.setString(st);
    text.setFillColor(textNormal);
    //text.setCharacterSize(50);

}

void Button::setColor(const sf::Color& color)
{
    button.setFillColor(color);
}
