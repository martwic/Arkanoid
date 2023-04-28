#include "Arkanoid.h"
#include <iostream>

Ball* Arkanoid::ball = nullptr;
Paddle* Arkanoid::paddle = nullptr;
Bar* Arkanoid::bar = nullptr;

bool Arkanoid::Update(float deltaTime, BlockField& blocksField, Ranking& ranking)
{
    if (paddle != nullptr)
        paddle->Update(deltaTime);

    if (ball != nullptr && ball->exist())
    {
        ball->Update(deltaTime);
        ball->checkColission(*paddle);
        blocksField.Update(*ball, ranking);
        return true;
    }
    else
    {
        return false;
    }
}

void Arkanoid::Draw(sf::RenderWindow& window)
{
    if (ball != nullptr)
        ball->Draw(window);
    if (paddle != nullptr)
        paddle->Draw(window);
    if (bar != nullptr)
        bar->Draw(window);
}

Arkanoid::~Arkanoid() {
    delete ball;
    ball = nullptr;
}
