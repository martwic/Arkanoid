#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#include <fstream>

int main()
{
    sf::Font font;
    font.loadFromFile("ethn.otf");
    Game::menu(font);
    
    return 0;
}