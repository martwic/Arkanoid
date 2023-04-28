#pragma once
#include "Block.h"

class EasyBlock :public Block{
    sf::RectangleShape rect;
    int number = 1;
public:
    EasyBlock(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color& color) : Block(size, position, color) {};
    int getNumber() { return this->number; };
};