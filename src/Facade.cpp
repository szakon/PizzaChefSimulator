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
    //unsigned int screenWidth = window.getSize().x;
    cout << "WIDTH" << screenWidth << endl;
    //unsigned int screenHeight = window.getSize().y;
    cout << "HEIGHT" << screenHeight << endl;

    window.setFramerateLimit(60);
    sf::Vector2u windowSize = window.getSize();

    sf::Texture texture;
    if (!texture.loadFromFile("image.png")) {
        cout << "ERROR wood IMAGE DIDN'T LOAD" << std::endl;
    }
    texture.loadFromFile("resources/bois1.jpg");
    sf::Sprite sprite;
    sprite.setTexture(texture);
    // Calculate the scale factors to fill the window
    float scaleX = static_cast<float>(window.getSize().x) / texture.getSize().x;
    float scaleY = static_cast<float>(window.getSize().y) / texture.getSize().y;
    // Set the scale of the sprite to fill the window
    sprite.setScale(scaleX, scaleY);

    float scaleFactorJar = 0.9f*screenWidth/2500;

    //create the cheese jar
    sf::Texture cheese_jar;
    if (!cheese_jar.loadFromFile("resources/storage_cheese.png")) {
        cout << "ERROR cheese jar IMAGE DIDN'T LOAD" << std::endl;
    }
    float positionCheese = 3.0f;


    //create the tomatoe jar
    sf::Texture tomatoe_jar;
    if (!tomatoe_jar.loadFromFile("resources/storage_tomatoe.png")) {
        cout << "ERROR tomatoe jar IMAGE DIDN'T LOAD" << std::endl;
    }
    float positionTomatoe = 1.5f;

    //create the pepperoni jar
    sf::Texture pepperoni_jar;
    if (!pepperoni_jar.loadFromFile("resources/storage_peperoni.png")) {
        cout << "ERROR pepperoni jar IMAGE DIDN'T LOAD" << std::endl;
    }
    float positionPepperoni = 0;

    sf::Sprite spriteTomatoe;
    sf::Sprite spriteCheese;
    sf::Sprite spritePepperoni;
    for(Storage& storage : storages) {
        if(storage.getIngredient().getlabel() == "tomatoe") {
            storage.setSprite(tomatoe_jar, scaleFactorJar, positionTomatoe, screenWidth, sprite, 0.0, 0.0);
            spriteTomatoe = storage.getSprite();
            cout << spriteTomatoe.getTextureRect().height << std::endl;
        }
        else if (storage.getIngredient().getlabel() == "cheese") {
            storage.setSprite(cheese_jar, scaleFactorJar, positionCheese, screenWidth, sprite, 0.0, 0.0);
            spriteCheese = storage.getSprite();
        }
        else if (storage.getIngredient().getlabel() == "pepperoni") {
            storage.setSprite(pepperoni_jar, scaleFactorJar, positionPepperoni, screenWidth, sprite, 0.0, 0.0);
            spritePepperoni = storage.getSprite();
        }
    }

    //create a pot
    sf::Texture pot;
    if (!pot.loadFromFile("resources/pot.png")) {
        cout << "ERROR pot IMAGE DIDN'T LOAD" << std::endl;
    }
    float scaleFactorPot = 0.2f*screenWidth/2500;
    float potLine = 20 + 1.2f * spriteTomatoe.getTextureRect().height*scaleFactorJar;
    cout << spriteTomatoe.getTextureRect().height << std::endl;
    cout << potLine << std::endl;


    //create a cutting board
    sf::Texture cut;
    if (!cut.loadFromFile("resources/cutting_board.png")) {
        cout << "ERROR cutting board IMAGE DIDN'T LOAD" << std::endl;
    }
    cout << spriteTomatoe.getTextureRect().height << std::endl;
    cout << potLine << std::endl;


    //create a grater
    sf::Texture grater;
    if (!grater.loadFromFile("resources/grater.png")) {
        cout << "ERROR grater IMAGE DIDN'T LOAD" << std::endl;
    }
    float scaleFactorGrater = 0.1f*screenWidth/2500;

    /*
    sf::Sprite spriteTest;
    spriteTest.setTexture(grater);
    spriteTest.setScale(scaleFactorPot/2,scaleFactorPot/2);
    sf::Vector2f position_sprite(500, 500);
    spriteTest.setPosition(position_sprite);
    cout << spriteTomatoe.getTextureRect().height << std::endl;
    cout << potLine << std::endl;*/


    //random sprite used for preparations
    for(Preparation& preparation : preparations) {
        if(preparation.getIngredient().getlabel() == "tomatoe") {
            preparation.setSprite(pot, scaleFactorPot, positionTomatoe, screenWidth, spriteTomatoe, scaleFactorJar, potLine);
            cout << "TOMATOE" << endl;
        }
        else if (preparation.getIngredient().getlabel() == "cheese") {
            cout << "Position cheese" << positionCheese << endl;
            preparation.setSprite(grater, scaleFactorGrater, positionCheese+1.5, screenWidth, spriteCheese, scaleFactorJar, potLine);
            cout << "CHEESE" << endl;
        }
        else if (preparation.getIngredient().getlabel() == "pepperoni") {
            preparation.setSprite(cut, scaleFactorPot, positionPepperoni, screenWidth, spritePepperoni, scaleFactorJar, potLine);
            cout << "PEPPERONI" << endl;
        }
    }


    //create a pizza
    sf::CircleShape pizza;
    sf::CircleShape sauce;
    sf::Vector2f circlePosition(0,5*screenHeight/10);
    sf::Vector2f saucePosition(200*screenWidth/2500-170*screenWidth/2500,5*screenHeight/10+200*screenWidth/2500-170*screenWidth/2500);
    pizza.setPosition(circlePosition);
    sauce.setPosition(sf::Vector2f(100,100));
    pizza.setRadius(200*screenWidth/2500);
    sauce.setRadius(170*screenWidth/2500);
    sf::Color customColor(255, 228, 181);
    pizza.setFillColor(customColor);
    sauce.setFillColor(sf::Color::Red);

    //movement
    float xVelocity = 1;

    bool isTouched = false; //to test if no object was touched
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed) window.close();

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();


            else if (event.type == sf::Event::MouseButtonPressed) {
                cout << "PRESSED" << endl;
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    cout << "MOUS POSITION x: " << mousePos.x << "AND y: "<< mousePos.y << endl;
                    // Check for storage click
                    for (Storage &storage: storages) {
                        if (storage.getSprite().getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                            cout << "WE ARE TOUCHING" << endl;
                            cout << storage.getIngredient() << endl;
                            selected.emplace(storage);
                            selected_type = "storage";
                            cout << "SELECTED HAS CHANGED TO: " << selected.value().getIngredient() << endl;
                            pizza.setFillColor(sf::Color::Blue);
                            isTouched = true;
                            break; // Exit the loop if a storage is clicked
                        }
                    }

                    for (Preparation &preparation: preparations) {
                        if (preparation.getSprite().getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                            cout << "WE ARE PREPARING ";
                            cout << preparation.getIngredient() << endl;
                            pizza.setFillColor(sf::Color::Green);
                            startCooking(preparation);
                            isTouched = true;
                            break; // Exit the loop if a preparation is clicked
                        }
                    }

                    if (!isTouched){
                        selected.reset();
                        selected_type = "nothing";
                    }
                }


            }
        }
        //physics
        circlePosition.x += xVelocity;
        saucePosition.x += xVelocity;
        pizza.setPosition(circlePosition);
        sauce.setPosition(saucePosition);

        //render
        window.clear();
        window.draw(sprite);
        for(Storage& storage : storages) {
            storage.draw(window);
        }
        for(Preparation& preparation : preparations) {
            preparation.draw(window);
        }
        window.draw(pizza);

        //window.draw(spriteTest);
        window.draw(sauce);

        window.display();

    }

}

void Facade::startCooking(Preparation preparation){
    cout << "START COOKING" << endl;
    if (selected.has_value()){ //is something selected
        cout << "Selected is the following: " << selected.value().getIngredient() << endl;
        if (selected_type == "storage"){  //if the last selected object is a storage
            if (selected.value().getIngredient() == preparation.getIngredient()){ //if the selected storage corresponds to the right ingredient
                selected.emplace(preparation);
                cout<< "SUCCESS" << preparation.getIngredient() << endl;

            }else{
                cout << "ERROR: you selected the wrong ingredient" << endl;
            }

        }else{
            cout << "ERROR: you didn't select a storage" << endl;
        }
    }else{
        cout << "ERROR: nothing was selected" << endl;
    }
}




