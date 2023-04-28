#include <iostream>
#include "BlockField.h"

BlockField::BlockField(const sf::Vector2f& s, const sf::Vector2f& p,  int c, int r) : size(s), position(p), columns(c), rows(r)
{
    sf::Vector2f blockSize(s.x / columns, s.y / rows);
    for (int i = 0; i < columns; i++)
    {
        int j = 0;
        for (j; j < rows - 4; j++)
        {
            blocks.emplace_back(new HardBlock(blockSize - sf::Vector2f(4.f, 4.f), position + sf::Vector2f(blockSize.x * i + 2.f, blockSize.y * j + 2.f), sf::Color::Red));
        }
        for (j; j < rows - 2; j++)
        {
            blocks.emplace_back(new MediumBlock(blockSize - sf::Vector2f(4.f, 4.f), position + sf::Vector2f(blockSize.x * i + 2.f, blockSize.y * j + 2.f), sf::Color::Yellow));
        }
        for (j; j < rows ; j++)
        {
            blocks.emplace_back(new EasyBlock(blockSize - sf::Vector2f(4.f, 4.f), position + sf::Vector2f(blockSize.x * i + 2.f, blockSize.y * j + 2.f), sf::Color(20, 180, 40)));
        }
    }
}

void BlockField::Update(Ball& ball, Ranking& ranking)
{
    sf::Vector2f blockSize(size.x / columns, size.y / rows);
    for (std::list < std::unique_ptr<Block>>::iterator it = blocks.begin(); it != blocks.end(); it++) {
        auto it2 = it;
        bool colision = ball.checkColission(**it);
        if (colision) {
            if ((*it)->getNumber() == 3) {
                blocks.emplace(it, new MediumBlock(blockSize - sf::Vector2f(4.f, 4.f), position + sf::Vector2f((*it)->left(), (*it)->top()), sf::Color::Yellow));
                blocks.erase(it);
                ranking.updatePoints();
                return;
            }
            else if ((*it)->getNumber() == 2) {
                blocks.emplace(it, new EasyBlock(blockSize - sf::Vector2f(4.f, 4.f), position + sf::Vector2f((*it)->left(), (*it)->top()), sf::Color(20, 180, 40)));
                blocks.erase(it);
                ranking.updatePoints();
                return;
            }
            else {
                blocks.erase(it);
                ranking.updatePoints();
                return;
            }
        }
    }
}

void BlockField::Draw(sf::RenderWindow& window)
{
    for (auto& block : blocks)
    {
        block->Draw(window);
    }
}

bool BlockField::Empty()
{
    if (blocks.empty())
        return true;
    return false;
}

