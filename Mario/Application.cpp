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
    sf::CircleShape incircle;
    incircle.setRadius(80.f);
    incircle.setFillColor(sf::Color(32,32,32));
    incircle.setPosition(570,270);
    
    sf::CircleShape midcircle;
    midcircle.setRadius(150.f);
    midcircle.setFillColor(sf::Color(145,149,203));
    midcircle.setPosition(500,200);

    sf::CircleShape outcircle;
    outcircle.setRadius(200.f);
    outcircle.setFillColor(sf::Color(120,192,240));
    outcircle.setPosition(450,150);

    sf::CircleShape outmcircle;
    outmcircle.setRadius(250.f);
    outmcircle.setFillColor(sf::Color(136,148,227));
    outmcircle.setPosition(400,100);
   

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(41, 41, 41));
        window.draw(outmcircle);
        window.draw(outcircle);
        window.draw(midcircle);
        window.draw(incircle);
        window.display();
    }

    return 0;
}