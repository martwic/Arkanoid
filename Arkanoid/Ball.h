#ifndef BALL_H_
#define BALL_H_

#include <SFML/Graphics.hpp>
#include "Block.h"
#include "GlobalObj.h"
#include "Paddle.h"

class Ball
{
private:
    sf::CircleShape circle;
    float speed;
    sf::Vector2f velocity;

    void setAngle(float ang);
    float getAngle();

public:
    Ball(float radius, const sf::Vector2f& position, const sf::Color& color, float speed, float angle);

    bool checkColission(const Block& block);
    bool checkColission(const Paddle& paddle);
    bool exist() { return bottom() < GlobalObj::windowHeight; }

    void Update(float deltaTime);

    void Draw(sf::RenderWindow& window);

    float left()   const { return circle.getPosition().x - circle.getRadius(); }
    float rigth()  const { return circle.getPosition().x + circle.getRadius(); }
    float top()    const { return circle.getPosition().y - circle.getRadius(); }
    float bottom() const { return circle.getPosition().y + circle.getRadius(); }

    float getX() const { return circle.getPosition().x; }
    float getY() const { return circle.getPosition().y; }
    sf::Vector2f getPosition() const { return circle.getPosition(); }
    float getRadius() const { return circle.getRadius(); }
    sf::Vector2f getVelocity() const { return velocity; }
};

#endif // BALL_H_
