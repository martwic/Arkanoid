#ifndef BLOCKFIELD_H_
#define BLOCKFIELD_H_

#include <list>
#include "Ball.h"
#include "Bar.h"
#include "GlobalObj.h"
#include "HardBlock.h"
#include "MediumBlock.h"
#include "EasyBlock.h"
#include "Ranking.h"

class BlockField
{
private:
    std::list< std::unique_ptr<Block>> blocks;
    sf::Vector2f size;
    sf::Vector2f position;
    int columns;
    int rows;
public:
    BlockField(const sf::Vector2f& s, const sf::Vector2f& position, int columns, int rows);

    void Update(Ball& ball, Ranking& ranking);

    void Draw(sf::RenderWindow& window);

    bool Empty();
};

#endif // BLOCKFIELD_H_

