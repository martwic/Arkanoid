#pragma once
#ifndef BAR_H_
#define BAR_H_

#include <SFML/Graphics.hpp>
#include "GlobalObj.h"

class Bar
{
private:
    sf::RectangleShape bar;
public:
    Bar(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color& color);
    void Draw(sf::RenderWindow& window);
};

#endif // BAR_H_