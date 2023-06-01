#include <iostream>
#include <map>
#include "myMain.h"
#include "Drawing.h"
#include "colors.h"
#include <SFML/Graphics.hpp>

using namespace std;

int myMain()
{
    sf::RenderWindow window(sf::VideoMode(1280,720), "My Program");
    window.setFramerateLimit(60);
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed) window.close();

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
        }

    }
    return 0;
}
