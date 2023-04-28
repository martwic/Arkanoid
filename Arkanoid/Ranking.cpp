#include "Ranking.h"

void Ranking::askForName(sf::Font& font)
{
    sf::RenderWindow askkingWindow(sf::VideoMode(GlobalObj::windowWidth, GlobalObj::windowHeight/2), "Arkanoid - What is your name?", sf::Style::Close | sf::Style::Titlebar);
    sf::Event event;
    sf::Text question("WHAT IS YOUR NAME?", font);
    typedName.setString(name);
    typedName.setFont(font);
    typedName.setPosition(sf::Vector2f(0, GlobalObj::windowHeight / 5));
    while (askkingWindow.isOpen())
    {
        while (askkingWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                askkingWindow.close();
            if (event.type == sf::Event::TextEntered)
            {
                name += event.text.unicode;
                typedName.setString(name);
            }
        }
        askkingWindow.clear(sf::Color::Black);
        askkingWindow.draw(typedName);
        askkingWindow.draw(question);
        askkingWindow.display();
    }
}

void  Ranking::updatePoints()
{
    int p = 1;
    std::regex statement("marta");
    std::smatch compatibility;
    if (regex_search(name, compatibility, statement)) {
        p *= 3;
    }
    points += p;
}

void Ranking::updateRanking()
{
    file.open("ranking.txt",  std::ios::out | std::ios::app);
    if (file.good() == true)
    {
        file << name << "\n" << points << "\n";
        file.close();
    }
}

void Ranking::showRanking(sf::Font& font) {
std::vector < std::pair < std::string, int >> rank;
std::string line;
    file.open("ranking.txt", std::ios::in);
    if (file.good() == true)
    {
        while (file) {
            std::string x;
            getline(file, x);
            std::string n = x;
            getline(file, x);
            int s = atoi(x.c_str());
            std::pair<std::string, int> p(n, s);
            rank.push_back(p);
        }
        sort(rank.begin(), rank.end(), [](std::pair < std::string, int > a, std::pair < std::string, int > b)
            {
                return a.second > b.second;
            });
        file.close();
    }
    sf::RenderWindow rankingWindow(sf::VideoMode(GlobalObj::windowWidth, GlobalObj::windowHeight), "Arkanoid - ranking", sf::Style::Close | sf::Style::Titlebar);
    sf::Event event;
    sf::Text r[3];
    r[0].setPosition(50,50);
    r[1].setPosition(50, GlobalObj::windowHeight/3+50);
    r[2].setPosition(50, GlobalObj::windowHeight/3*2+50);    
    for (int i = 0; i < 3; i++) {
        std::string x = std::to_string(rank[i].second);
        line = std::to_string(i+1) + ".  " + rank[i].first + " :     " + std::to_string(rank[i].second);
        r[i].setString(line);
        r[i].setFont(font);
    }
    while (rankingWindow.isOpen())
    {
        while (rankingWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                rankingWindow.close();
        }
        rankingWindow.clear(sf::Color::Black);
        rankingWindow.draw(r[0]);
        rankingWindow.draw(r[1]);
        rankingWindow.draw(r[2]);
        rankingWindow.display();
    }
}
