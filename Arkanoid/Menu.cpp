#include "Menu.h"

#include <SFML/Window/Event.hpp>


    
void Menu::MoveUp()
{
    if (selectedItemIndex > 0) {
        buttons[selectedItemIndex]->setColor(sf::Color(200, 200, 200));
        selectedItemIndex--;
        buttons[selectedItemIndex]->setColor(sf::Color::Yellow);
    }
}

void Menu::MoveDown()
{
    if (selectedItemIndex < 2) {
        buttons[selectedItemIndex]->setColor(sf::Color(200, 200, 200));
        selectedItemIndex++;
        buttons[selectedItemIndex]->setColor(sf::Color::Yellow);
    }
}

void Menu::createButtons(sf::Font& font)
{
    buttons.emplace_back(new Button("PLAY", sf::Vector2f(GlobalObj::windowWidth / 3, GlobalObj::windowHeight / 9), font));
    buttons[0]->setColor(sf::Color::Yellow);
    buttons.emplace_back(new Button("RANKING", sf::Vector2f(GlobalObj::windowWidth / 3, GlobalObj::windowHeight / 9 * 4), font));
    buttons.emplace_back(new Button("EXIT", sf::Vector2f(GlobalObj::windowWidth / 3, GlobalObj::windowHeight / 9 * 7), font));
}

void Menu::Draw(sf::RenderWindow& window)
{
    for (auto& button : buttons)
    {
        button->Draw(window);
    }
}




