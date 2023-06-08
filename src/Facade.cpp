//
// Created by Sarah Zakon on 06/06/2023.
//
#include "Facade.h"
#include <unordered_map>
#include <iostream>

Facade::Facade() {
    // Get the screen resolution
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    unsigned int screenWidth = desktopMode.width;
    unsigned int screenHeight = desktopMode.height;

    // Create the SFML window with the screen size
    window.create(sf::VideoMode(screenWidth, screenHeight), "My Program");

    init();
}

void Facade::init(){

    Ingredient tomatoe("tomatoe");
    Ingredient cheese("cheese");
    Ingredient pepperoni("pepperoni");
    ingredients.insert(std::make_pair("tomatoe", tomatoe));
    ingredients.insert(std::make_pair("cheese", cheese));
    ingredients.insert(std::make_pair("pepperoni", pepperoni));


    int i = 0;
    for (const auto &ingredient: ingredients){
        Storage storage(ingredient.second);
        Preparation preparation(ingredient.second);
        storages.push_back(storage);
        preparations.push_back(preparation);
    }

    draw_init();

    //test
    std::cout << "The ingredient list is: ";
    int n=0;
    for (const auto &ingredient: ingredients){
        std::cout << "the ingredient number " << i << " is " << ingredient.second.getlabel() <<std::endl;
        i++;
    }


    std::cout << "The storage list is: ";
    int j=0;
    for (auto &storage: storages){
        std::cout << "the storage number " << j << " is " << storage.getIngredient() <<std::endl;
        j++;
    }


    std::cout << "The preparation list is: ";
    int k=0;
    for (auto &preparation: preparations){
        std::cout << "the preparation number " << k << " is " << preparation.getIngredient() <<std::endl;
        k++;
    }


}

void Facade::draw_init() {
    // Get the screen resolution
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    unsigned int screenWidth = desktopMode.width;
    unsigned int screenHeight = desktopMode.height;

    window.setFramerateLimit(60);
    sf::Vector2u windowSize = window.getSize();

    sf::Texture texture;
    if (!texture.loadFromFile("image.png")) {
        cout << "ERROR IMAGE DIDN'T LOAD" << std::endl;
    }
    texture.loadFromFile("resources/bois1.jpg");
    sf::Sprite sprite;
    sprite.setTexture(texture);
    // Calculate the scale factors to fill the window
    float scaleX = static_cast<float>(window.getSize().x) / texture.getSize().x;
    float scaleY = static_cast<float>(window.getSize().y) / texture.getSize().y;
    // Set the scale of the sprite to fill the window
    sprite.setScale(scaleX, scaleY);


    //create the cheese jar
    sf::Texture cheese_jar;
    if (!cheese_jar.loadFromFile("resources/storage_cheese.png")) {
        cout << "ERROR IMAGE DIDN'T LOAD" << std::endl;
    }

    sf::Sprite spriteCJ;
    spriteCJ.setTexture(cheese_jar);
    float scaleFactorJar = 0.9f; // Example scale factor, adjust as needed
    //spriteCJ.setScale(scaleFactorJar, scaleFactorJar);
    sf::Vector2f cheeseJPosition(7*screenWidth/10, 20);
    spriteCJ.setPosition(cheeseJPosition);


    //create the tomatoe jar
    sf::Texture tomatoe_jar;
    if (!tomatoe_jar.loadFromFile("resources/storage_tomatoe.png")) {
        cout << "ERROR IMAGE DIDN'T LOAD" << std::endl;
    }

    sf::Sprite spriteTJ;
    spriteTJ.setTexture(tomatoe_jar);
    //spriteTJ.setScale(scaleFactorJar, scaleFactorJar);
    sf::Vector2f tomatoeJPosition(8*screenWidth/10, 20);
    spriteTJ.setPosition(tomatoeJPosition);


    //create the pepperoni jar
    sf::Texture pepperoni_jar;
    if (!pepperoni_jar.loadFromFile("resources/storage_peperoni.png")) {
        cout << "ERROR IMAGE DIDN'T LOAD" << std::endl;
    }
    sf::Sprite spritePJ;
    spritePJ.setTexture(pepperoni_jar);
    //spritePJ.setScale(scaleFactorJar, scaleFactorJar);
    sf::Vector2f pepperoniJPosition(9*screenWidth/10, 20);
    spritePJ.setPosition(pepperoniJPosition);

    //create a pot


    //create a pizza
    sf::CircleShape pizza;
    sf::CircleShape sauce;
    sf::Vector2f circlePosition(0,5*screenHeight/10);
    sf::Vector2f saucePosition(40,5*screenHeight/10+40);
    pizza.setPosition(circlePosition);
    sauce.setPosition(sf::Vector2f(100,100));
    pizza.setRadius(250);
    sauce.setRadius(210);
    sf::Color customColor(255, 228, 181);
    pizza.setFillColor(customColor);
    sauce.setFillColor(sf::Color::Red);

    //movement
    float xVelocity = 3;


    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed) window.close();

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
        }
        //physics
        circlePosition.x += xVelocity;
        saucePosition.x += xVelocity;
        pizza.setPosition(circlePosition);
        sauce.setPosition(saucePosition);

        //render
        window.clear();
        window.draw(sprite);
        window.draw(spriteCJ);
        window.draw(spriteTJ);
        window.draw(spritePJ);
        window.draw(pizza);
        window.draw(sauce);
        window.display();

    }

}




