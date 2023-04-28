#ifndef ARKANOID_H_
#define ARKANOID_H_

#include <SFML/Graphics.hpp>
#include "BlockField.h"


class Arkanoid
{
private:
    static Ball* ball;
    static Paddle* paddle;
    static Bar* bar;
    static sf::RenderWindow mainWindow;

public:
    Arkanoid() { sf::RenderWindow mainWindow(sf::VideoMode(GlobalObj::windowWidth + GlobalObj::barWidth, GlobalObj::windowHeight), "Arkanoid", sf::Style::Close | sf::Style::Titlebar); };
    static void createBall(const Ball& bll) { ball = new Ball(bll); }
    static void createPaddle(const Paddle& padd) { paddle = new Paddle(padd); }
    static void createBar(const Bar& barr) { bar = new Bar(barr); }
    static bool Update(float deltaTime, BlockField& blocksField, Ranking& ranking);
    static void Draw(sf::RenderWindow& window);
    ~Arkanoid();
};

#endif // ARKANOID_H_
