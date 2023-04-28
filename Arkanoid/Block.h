#ifndef BLOCK_H_
#define BLOCK_H_

#include <cmath>
#define M_PI 3.14159265358979323846

#include <SFML/Graphics.hpp>

class Block
{
    sf::RectangleShape rect;
    int number;
public:
    Block(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color& color);
    ~Block() {};
    virtual int getNumber() = 0;
    void Draw(sf::RenderWindow& window);
    float left()   const { return rect.getPosition().x; }
    float rigth()  const { return rect.getPosition().x + rect.getSize().x; }
    float top()    const { return rect.getPosition().y; }
    float bottom() const { return rect.getPosition().y + rect.getSize().y; }
};

#endif // BLOCK_H_
