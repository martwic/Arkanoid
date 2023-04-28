#pragma once
#include "Block.h"

class MediumBlock :public Block {
    sf::RectangleShape rect;
    int number = 2;
public:
    MediumBlock(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color& color) : Block(size, position, color) {};
    int getNumber() { return this->number; };
};