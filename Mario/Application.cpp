#include <SFML/Graphics.hpp>
#include<SFML/Main.hpp>
#include<SFML/OpenGL.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<vector>

int main()
{
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
    sechand.setOrigin(0,0);
    sechand.setSize(sf::Vector2f(2,75));
    sechand.setPosition(653, 350);
    sechand.setRotation(180.f);
    sechand.setFillColor(sf::Color(170, 170, 170));

    sf::RectangleShape minhand;
    minhand.setOrigin(0, 0);
    minhand.setSize(sf::Vector2f(4,69));
    minhand.setPosition(650, 350);
    minhand.setRotation(45.f);
    minhand.setFillColor(sf::Color(204, 204, 204));
    
    sf::RectangleShape hrhand;
    hrhand.setOrigin(0, 0);
    hrhand.setSize(sf::Vector2f(5, 50));
    hrhand.setPosition(650, 350);
    hrhand.setRotation(0.f);
    hrhand.setFillColor(sf::Color(255, 255, 255));


    sf::Text day;
    day.setString("Mon");
    day.setFillColor(sf::Color(85,85,85));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(55,55,55));
        window.draw(outmcircle);
        window.draw(outcircle);
        window.draw(midcircle);
        window.draw(incircle);
        window.draw(temperature);
        window.draw(graph);
        window.draw(minhand);
        window.draw(hrhand);
        window.draw(sechand);
        window.draw(day);
        window.display();
    }

    return 0;
}