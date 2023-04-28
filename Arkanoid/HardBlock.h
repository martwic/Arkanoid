#pragma once
#include "Block.h"

class HardBlock :public Block {
    sf::RectangleShape rect;
    int number = 3;
public:
    HardBlock(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color& color) : Block(size, position, color) {};
    int getNumber() { return this->number; };
};