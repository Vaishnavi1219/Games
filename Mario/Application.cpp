#include <SFML/Graphics.hpp>
#include<SFML/Main.hpp>
#include<SFML/OpenGL.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<vector>
#include<iostream>
using namespace std;

int main()
{
    int elapsed = 0;
    sf::RenderWindow window(sf::VideoMode(1366, 768), "SFML works!");
    window.clear(sf::Color(55,55,55));
   
    sf::CircleShape incircle;
    incircle.setRadius(90.f);
    incircle.setOutlineThickness(5.f);
    incircle.setOutlineColor(sf::Color(55, 55, 55));
    incircle.setFillColor(sf::Color(32,32,32));
    incircle.setPosition(560,260);
    
    sf::CircleShape midcircle;
    midcircle.setRadius(150.f);
    midcircle.setOutlineThickness(7.f);
    midcircle.setOutlineColor(sf::Color(55, 55, 55));
    midcircle.setFillColor(sf::Color(32, 32, 32));
    midcircle.setPosition(500,200);

    sf::CircleShape outcircle;
    outcircle.setRadius(200.f);
    outcircle.setOutlineThickness(9.f);
    outcircle.setOutlineColor(sf::Color(55, 55, 55));
    outcircle.setFillColor(sf::Color(32, 32, 32));
    outcircle.setPosition(450,150);

    sf::CircleShape outmcircle;
    outmcircle.setRadius(250.f);
    outmcircle.setFillColor(sf::Color(32, 32, 32));
    outmcircle.setPosition(400,100);

    sf::CircleShape temperature;
    temperature.setRadius(80.f);
    temperature.setFillColor(sf::Color(32,32,32));
    temperature.setPosition(100, 300);
   
    sf::CircleShape graph;
    graph.setRadius(80.f);
    graph.setFillColor(sf::Color(32, 32, 32));
    graph.setPosition(1050, 300);

    sf::RectangleShape sechand;
    sechand.setOrigin(1,75);
    sechand.setSize(sf::Vector2f(2,75));
    sechand.setPosition(650,350);
    sechand.setRotation(0.f);
    sechand.setFillColor(sf::Color(255,204,0));

    sf::RectangleShape minhand;
    minhand.setOrigin(2,69);
    minhand.setSize(sf::Vector2f(4,69));
    minhand.setPosition(650,350);
    minhand.setRotation(0.f);
    minhand.setFillColor(sf::Color(255,60,94));
    
    sf::RectangleShape hrhand;
    hrhand.setOrigin(2.5,50);
    hrhand.setSize(sf::Vector2f(5, 50));
    hrhand.setPosition(650,350);
    hrhand.setRotation(0.f);
    hrhand.setFillColor(sf::Color(108,108, 255));


    /*sf::Font font;
    font.loadFromFile("SugarpunchDEMO.otf");
    sf::Text day;
    day.setFont(font);
    day.setCharacterSize(24);
    day.setPosition(100,200);
    day.setFillColor(sf::Color(255,255,255));*/

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

         if (elapsed++ % 60 == 59)
           sechand.rotate(5.3);

        /* if (elapsed++ % 15 == 0)
             minhand.rotate(20.f);

         if (elapsed++ % 15 == 0)
             hrhand.rotate(20.f);*/
                
        window.clear(sf::Color(55,55,55));
        window.draw(outmcircle);
        window.draw(outcircle);
        window.draw(midcircle);
        window.draw(incircle);
        window.draw(temperature);
        window.draw(graph);
        window.draw(hrhand);
        window.draw(minhand);
        window.draw(sechand);
      //  window.draw(day);
        window.display();
    }

    return 0;
}