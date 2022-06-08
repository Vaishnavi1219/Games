#include<SFML/Graphics.hpp>
#include<SFML/Main.hpp>
#include<SFML/OpenGL.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<SFML/Window/ContextSettings.hpp>
#include<vector>
#include<iostream>
#include"CurvedText"

using namespace std;
using namespace sf;

int main(int argc, char** argv)
{
    std::cout << argv[0] << endl;
    int elapsed = 0;
    sf::RenderWindow window(sf::VideoMode(1366,768,32), "SFML works!",sf::Style::Close, sf::ContextSettings(24, 8, 4));
    window.clear(sf::Color(55,55,55));
    window.setFramerateLimit(60);


    
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

    sf::Font font;

    if (!font.loadFromFile("C:/Users/vaishanavi/source/repos/Vaishnavi1219/Games/x64/Debug/BubblegumSans.ttf")) 
    { std::cerr << "ERROR loading Font.ttf" << std::endl; }
    CurvedText cText("Curved Hello", 4, 1, font, 20);
    cText.setPosition(100, 300);
    cText.SetColor(sf::Color(255, 255, 255));
    
    sf::Text day("Monday",font);
    
    day.setCharacterSize(24);
    day.setPosition(600,300);
    day.setFillColor(sf::Color(255,255,255));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

         if (elapsed++ % 60 == 59)
           sechand.rotate(6.f);

        if (elapsed % 3600 == 3599)
             minhand.rotate(6.f);

         if (elapsed % 216000 == 215999)
             hrhand.rotate(6.f);
                
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
        window.draw(day);
        window.draw(cText);
        window.display();
    }

    return 0;
} 
