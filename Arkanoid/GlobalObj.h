#ifndef GLOBALOBJ_H_
#define GLOBALOBJ_H_

#include <SFML/Graphics.hpp>

class GlobalObj
{
private:
    GlobalObj() = delete;

public:
    static const float windowWidth, barWidth, windowHeight;
    //static sf::RenderWindow mainWindow;
    //static sf::RenderWindow menuWindow;
};

#endif // GLOBALOBJECTS_H_
