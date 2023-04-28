#pragma once
#include <SFML/Graphics.hpp>
#include "GlobalObj.h"
#include <string>
#include <iostream>
#include <fstream>
#include <regex>
#include <vector>
#include <iostream>
#include <sstream>

class Ranking {
	int points;
	std::string name;
	sf::Text typedName;
	std::fstream file;
	sf::Window rankingWindow;
public:
	Ranking() { points = 0; };
	std::string getName() { return name; };
	void setName(std::string n) { name = n; };
	void setPoints(int x) { points = x; };
	void askForName(sf::Font& font);
	void showRanking(sf::Font& font);
	void updatePoints();
	void updateRanking();
	int  getPoints() { return points; };
};