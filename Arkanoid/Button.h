#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include "GlobalObj.h"

    class Button {
        sf::RectangleShape button;
        sf::Color backgroundNormal = sf::Color(200, 200, 200);
        sf::Color textNormal= sf::Color(0,0,0);
        sf::Vector2f size = sf::Vector2f(GlobalObj::windowWidth / 3, GlobalObj::windowWidth / 9);
        sf::Vector2f position;
        sf::Text text;
    public:
        Button(std::string st, const sf::Vector2f& p, sf::Font& f);
        void Draw(sf::RenderWindow& window);
        void setColor(const sf::Color& color);
    };

#endif // BUTTON_HPP
