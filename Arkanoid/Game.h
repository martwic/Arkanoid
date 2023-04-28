#pragma once
#include <SFML/Graphics.hpp>
#include <sstream>
#include "GlobalObj.h"
#include "BlockField.h"
#include "Paddle.h"
#include "Bar.h"
#include "Arkanoid.h"
#include "Menu.h"
#include "Ranking.h"

class Game {
	sf::Text points;
	sf::Text level;

public:
	static void menu(sf::Font& font);
	static void game(sf::Font& font);
	static void gameOver(sf::Font& font);
	static void youWin(sf::Font& font);
};