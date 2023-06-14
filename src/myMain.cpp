#include <iostream>
#include <map>
#include "myMain.h"
#include "Drawing.h"
#include "colors.h"
#include <SFML/Graphics.hpp>
#include "Pizza.h"
#include "Facade.h"


using namespace std;


void onClick(sf::Event::MouseButtonEvent event, std::vector<sf::CircleShape*> objects) {
    if (event.button == sf::Mouse::Left) {
        int x = event.x;
        int y = event.y;

        // Parcourir tous les objets pour vérifier si le clic est à l'intérieur de leur zone
        for (sf::CircleShape *obj: objects) {
            sf::FloatRect bounds = obj->getGlobalBounds();
            if (bounds.contains(x, y)) {
                obj->setFillColor(sf::Color::Blue);
            }
        }
    }
}


int myMain()
{
    Facade f;

/*
    Ingredient cheese = Ingredient("cheese");
    cout << cheese << endl;
    Storage storage_cheese = Storage(cheese);
    cout << storage_cheese << endl;
    Preparation prep_cheese = Preparation(cheese);
    cout << prep_cheese << endl;



    sf::RenderWindow window(sf::VideoMode(1280,720), "My Program");
    window.setFramerateLimit(60);

    sf::Texture texture;
    texture.loadFromFile("resources/bois1.jpg");
    sf::Sprite sprite;
    sprite.setTexture(texture);

    sf::Texture pot1;
    texture.loadFromFile("resources/storage_cheese.png");
    sf::Sprite spritepot1;
    spritepot1.setTexture(pot1);
    spritepot1.setPosition(sf::Vector2f(200,200));

    sf::CircleShape pizza;
    sf::CircleShape tomate;
    sf::Vector2f circlePosition(0,350);
    sf::Vector2f tomatePosition(20,370);
    pizza.setPosition(circlePosition);
    tomate.setPosition(sf::Vector2f(100,100));
    pizza.setRadius(100);
    tomate.setRadius(80);
    sf::Color customColor(255, 228, 181);
    pizza.setFillColor(customColor);
    tomate.setFillColor(sf::Color::Red);

    //movement
    float xVelocity = 3;


    std::vector<sf::CircleShape*> objects;
    objects.push_back(&pizza);


    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed) window.close();
            else if (event.type == sf::Event::MouseButtonPressed) {
                onClick(event.mouseButton, objects);
        }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
        }
        //physics
        circlePosition.x += xVelocity;
        tomatePosition.x += xVelocity;
        pizza.setPosition(circlePosition);
        tomate.setPosition(tomatePosition);

        //render
        window.clear();
        window.draw(sprite);
        window.draw(spritepot1);
        window.draw(pizza);
        window.draw(tomate);
        window.display();

    }
    return 0;
*/
}




