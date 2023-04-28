#ifndef MENU_H_
#define MENU_H_

#include <list>
#include <SFML/Graphics.hpp>
#include "Button.h"

class Menu 
{
private:
    std::vector<std::unique_ptr<Button>> buttons;
    int selectedItemIndex=0;
public:
    void MoveUp();
    void MoveDown();
    int GetPressedItem() { return selectedItemIndex; }
    void createButtons(sf::Font& font);
    void Draw(sf::RenderWindow& window);
};

#endif // MENU_H_