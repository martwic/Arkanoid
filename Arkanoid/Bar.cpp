#include "Bar.h"

Bar::Bar(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color& color)
{
    bar.setSize(size);
    bar.setPosition(position);
    bar.setFillColor(color);
}

void Bar::Draw(sf::RenderWindow& window)
{
    window.draw(bar);
}
