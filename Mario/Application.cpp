#include <SFML/Graphics.hpp>
#include<SFML/Main.hpp>
#include<SFML/OpenGL.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<vector>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1366, 768), "SFML works!");
    window.clear(sf::Color(41, 41, 41));
    sf::CircleShape circle;
    circle.setRadius(60.f);
    circle.setFillColor(sf::Color(32,32,32));
    circle.setPosition(600,300);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(41, 41, 41));
        window.draw(circle);
        window.display();
    }

    return 0;
}