#include "Game.h"
Ranking ranking;

void Game::menu(sf::Font& font)
{
    sf::Event event;
    sf::RenderWindow menuWindow(sf::VideoMode(GlobalObj::windowWidth, GlobalObj::windowHeight), "Arkanoid", sf::Style::Close | sf::Style::Titlebar);
    Menu menu;
    menu.createButtons(font);


    while (menuWindow.isOpen())
    {
        while (menuWindow.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::KeyReleased:
                switch (event.key.code)
                {
                case sf::Keyboard::Up:
                    menu.MoveUp();
                    break;

                case sf::Keyboard::Down:
                    menu.MoveDown();
                    break;

                case sf::Keyboard::Return:
                    switch (menu.GetPressedItem())
                    {
                    case 0:
                        menuWindow.close();
                        ranking.askForName(font);
                        game(font);
                        break;
                    case 1:
                        ranking.showRanking(font);
                        break;
                    case 2:
                        menuWindow.close();
                        break;
                    }
                    break;
                }
                break;
            case sf::Event::Closed:
                menuWindow.close();
                break;
            }
        }
        menuWindow.clear(sf::Color::Black);
        menu.Draw(menuWindow);
        menuWindow.display();
    }
}

void Game::game(sf::Font& font)
{
    sf::Event event;
    sf::RenderWindow mainWindow(sf::VideoMode(GlobalObj::windowWidth + GlobalObj::barWidth, GlobalObj::windowHeight), "Arkanoid", sf::Style::Close | sf::Style::Titlebar);
    BlockField blocksField(sf::Vector2f(GlobalObj::windowWidth, 200.f), sf::Vector2f(0.f, 0.f), 9, 5);
    Arkanoid::createBall(Ball(10.f, sf::Vector2f(225.0710f, 400.f), sf::Color::Black, 200.f, 100.f));
    Arkanoid::createPaddle(Paddle(sf::Vector2f(100.f, 10.f), sf::Vector2f(GlobalObj::windowWidth / 2, GlobalObj::windowHeight - 50), sf::Color::Black, 200.f));
    Arkanoid::createBar(Bar(sf::Vector2f(GlobalObj::barWidth, GlobalObj::windowHeight), sf::Vector2f(GlobalObj::windowWidth, 0.f), sf::Color::Black));
    sf::Text name(ranking.getName(), font);
    name.setPosition(GlobalObj::windowWidth+10, 10);
    sf::Text textPoints("POINTS", font);
    textPoints.setPosition(GlobalObj::windowWidth + 10, GlobalObj::windowHeight / 2-40);
    sf::Text points("0", font);
    std::string points_s;
    points.setPosition(GlobalObj::windowWidth + 10, GlobalObj::windowHeight / 2);

    sf::Clock clock;
    float deltaTime;

    while (mainWindow.isOpen())
    {
        deltaTime = clock.restart().asSeconds();

        while (mainWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                mainWindow.close();
                gameOver(font);
                menu(font);
            }
        }

        if (Arkanoid::Update(deltaTime, blocksField, ranking)) {
            if (blocksField.Empty()) {
                mainWindow.close();
                youWin(font);
                menu(font);
            }
            else {
                mainWindow.clear(sf::Color::Cyan);
                blocksField.Draw(mainWindow);
                Arkanoid::Draw(mainWindow);
                mainWindow.draw(name);
                std::stringstream ss;
                ss << ranking.getPoints();
                points_s = ss.str();
                points.setString(points_s);
                mainWindow.draw(textPoints);
                mainWindow.draw(points);
                mainWindow.display();
            }        }
        else {
            mainWindow.close();
            gameOver(font);
            menu(font);
        }
    }
}

void Game::gameOver(sf::Font& font)
{
    sf::RenderWindow overWindow(sf::VideoMode(GlobalObj::windowWidth/2, GlobalObj::windowHeight / 4), "Arkanoid - Game Over!", sf::Style::Close | sf::Style::Titlebar);
    sf::Event event;
    sf::Text text("GAME OVER", font);
    text.setPosition(50, 50);
    while (overWindow.isOpen())
    {
        while (overWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                ranking.updateRanking();
                ranking.setName("");
                ranking.setPoints(0);
                overWindow.close();
            }
        }
        overWindow.clear(sf::Color::Black);
        overWindow.draw(text);
        overWindow.display();
    }
}

void Game::youWin(sf::Font& font)
{
    sf::RenderWindow winWindow(sf::VideoMode(GlobalObj::windowWidth / 2, GlobalObj::windowHeight / 4), "Arkanoid - You Win!", sf::Style::Close | sf::Style::Titlebar);
    sf::Event event;
    sf::Text text("YOU WIN!!!", font);
    text.setPosition(50, 50);
    while (winWindow.isOpen())
    {
        while (winWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                ranking.updateRanking();
                ranking.setName("");
                ranking.setPoints(0);
                winWindow.close();
            }
        }
        winWindow.clear(sf::Color::Black);
        winWindow.draw(text);
        winWindow.display();
    }
}
