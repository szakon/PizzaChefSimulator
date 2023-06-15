#include "Facade.h"
#include <unordered_map>
#include <iostream>

const sf::Time Facade::TimePerFrame = sf::seconds(1.f/60.f); // On considère que le jeu tourne à 60 FPS
const float Facade::xVelocity = 6; //movement

Facade::Facade(){
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    unsigned int screenWidth = desktopMode.width;
    unsigned int screenHeight = desktopMode.height;

    // Create the SFML window with the screen size
    window.create(sf::VideoMode(screenWidth, screenHeight), "My Program");

    sf::Texture bois = loadTextureFromFile("resources/bois1.jpg");
    sprite_background.setTexture(bois);
    // Calculate the scale factors to fill the window
    float scaleX = static_cast<float>(window.getSize().x) / bois.getSize().x;
    float scaleY = static_cast<float>(window.getSize().y) / bois.getSize().y;
    // Set the scale of the sprite to fill the window
    sprite_background.setScale(scaleX, scaleY);


    //setting textures
    sf::Texture cheese_jar = loadTextureFromFile("resources/storage_cheese.png");
    sf::Texture tomatoe_jar = loadTextureFromFile("resources/storage_tomatoe.png");
    sf::Texture pepperoni_jar = loadTextureFromFile("resources/storage_pepperoni.png");
    sf::Texture grater = loadTextureFromFile("resources/grater.png");
    sf::Texture pot = loadTextureFromFile("resources/pot.png");
    sf::Texture cut = loadTextureFromFile("resources/cutting_board.png");
    textures.insert(std::make_pair("cheese_jar", cheese_jar));
    textures.insert(std::make_pair("tomatoe_jar", tomatoe_jar));
    textures.insert(std::make_pair("pepperoni_jar", pepperoni_jar));
    textures.insert(std::make_pair("grater", grater));
    textures.insert(std::make_pair("pot", pot));
    textures.insert(std::make_pair("cut", cut));



    run();
}

void Facade::run() {

    // Set up the clock
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    /*
    // Get the screen resolution
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    unsigned int screenWidth = desktopMode.width;
    unsigned int screenHeight = desktopMode.height;


    // Create the SFML window with the screen size
    window.create(sf::VideoMode(screenWidth, screenHeight), "My Program");
     */

    //Initialize the game
    init();
    sf::Vector2f cPosition = draw_init( window.getSize().x, window.getSize().y);

    while(window.isOpen()){
        sf::Time elapsedTime = clock.restart();
        timeSinceLastUpdate += elapsedTime;
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;

            update(TimePerFrame, window.getSize().x, window.getSize().y);

        }
        cPosition.x += xVelocity;
        sf::Texture cooked_cheese = loadTextureFromFile("resources/cooked-cheese.png");
        pizzas[0].setDough(window.getSize().x, cPosition, xVelocity, cooked_cheese, ingredients.at("tomatoe").added, ingredients.at("cheese").added, ingredients.at("pepperoni").added) ;

        render();
    }

    cout_test();



}

void Facade::init(){

    //Set up the pizzas
    Ingredient tomatoe("tomatoe");
    Ingredient cheese("cheese");
    Ingredient pepperoni("pepperoni");
    Ingr tom = {tomatoe, false};
    Ingr che = {cheese, false};
    Ingr pep = {pepperoni, false};
    ingredients.insert(std::make_pair("tomatoe", tom));
    ingredients.insert(std::make_pair("cheese", che));
    ingredients.insert(std::make_pair("pepperoni", pep));
    std::vector<Ingredient> pizzaIngredients = {tomatoe, cheese, pepperoni};
    Pizza pizza(pizzaIngredients);
    pizzas.push_back(pizza);

    //Set up the storages and preparations
    int i = 0;
    for (const auto &ingredient: ingredients){
        Storage storage(ingredient.second.ingredient);
        Preparation preparation1(ingredient.second.ingredient, 1);
        Preparation preparation2(ingredient.second.ingredient, 2);
        storages.push_back(storage);
        preparations.push_back(preparation1);
        preparations.push_back(preparation2);
    }

}

sf::Vector2f Facade::draw_init(unsigned int screenWidth, unsigned int screenHeight) {

    cout << "WIDTH" << screenWidth << endl;
    cout << "HEIGHT" << screenHeight << endl;

    window.setFramerateLimit(60);
    sf::Vector2u windowSize = window.getSize();

    //Draw the background
    //sf::Texture bois = loadTextureFromFile("resouces/bois1.jpg");
    /*
    sprite_background.setTexture(bois);
    // Calculate the scale factors to fill the window
    float scaleX = static_cast<float>(window.getSize().x) / bois.getSize().x;
    float scaleY = static_cast<float>(window.getSize().y) / bois.getSize().y;
    // Set the scale of the sprite to fill the window
    sprite_background.setScale(scaleX, scaleY);*/

    float scaleFactorJar = 0.9f*screenWidth/2500;

    //create the cheese jar
    //sf::Texture cheese_jar = loadTextureFromFile("resources/storage_cheese.png");
    float positionCheese = 3.0f;
    sf::Sprite spriteCheese;

    //create the tomatoe jar
    //sf::Texture tomatoe_jar = loadTextureFromFile("resources/storage_tomatoe.png");
    float positionTomatoe = 1.5f;
    sf::Sprite spriteTomatoe;

    //create the pepperoni jar
    //sf::Texture pepperoni_jar = loadTextureFromFile("resources/storage_peperoni.png");
    float positionPepperoni = 0;
    sf::Sprite spritePepperoni;

    for(Storage& storage : storages) {
        if(storage.getIngredient().getlabel() == "tomatoe") {
            storage.setSprite(textures.at("tomatoe_jar"), scaleFactorJar, positionTomatoe, screenWidth, sprite_background, 0.0, 0.0);
            spriteTomatoe = storage.getSprite();
            cout << spriteTomatoe.getTextureRect().height << std::endl;
        }
        else if (storage.getIngredient().getlabel() == "cheese") {
            storage.setSprite(textures.at("cheese_jar"), scaleFactorJar, positionCheese, screenWidth, sprite_background, 0.0, 0.0);
            spriteCheese = storage.getSprite();
        }
        else if (storage.getIngredient().getlabel() == "pepperoni") {
            storage.setSprite(textures.at("pepperoni_jar"), scaleFactorJar, positionPepperoni, screenWidth, sprite_background, 0.0, 0.0);
            spritePepperoni = storage.getSprite();
        }
    }

    //create a pot
    //sf::Texture pot = loadTextureFromFile("resources/pot.png");
    float scaleFactorPot = 0.2f*screenWidth/2500;
    float potLine = 20 + 1.2f * spriteTomatoe.getTextureRect().height*scaleFactorJar;
    cout << spriteTomatoe.getTextureRect().height << std::endl;
    cout << potLine << std::endl;


    //create a cutting board
    //sf::Texture cut = loadTextureFromFile("resources/cutting_board.png");
    cout << spriteTomatoe.getTextureRect().height << std::endl;
    cout << potLine << std::endl;


    //create a grater
    //sf::Texture grater = loadTextureFromFile("resources/grater.png");
    float scaleFactorGrater = 0.1f*screenWidth/2500;

    //random sprite used for preparations
    for(Preparation& preparation : preparations) {
        if(preparation.getIngredient().getlabel() == "tomatoe") {
            preparation.setSprite(textures.at("pot"), scaleFactorPot, positionTomatoe, screenWidth, spriteTomatoe, scaleFactorJar, potLine);
            cout << "TOMATOE" << endl;
        }
        else if (preparation.getIngredient().getlabel() == "cheese") {
            cout << "Position cheese" << positionCheese << endl;
            preparation.setSprite(textures.at("grater"), scaleFactorGrater, positionCheese+1.5, screenWidth, spriteCheese, scaleFactorJar, potLine);
            cout << "CHEESE" << endl;
        }
        else if (preparation.getIngredient().getlabel() == "pepperoni") {
            preparation.setSprite(textures.at("cut"), scaleFactorPot, positionPepperoni, screenWidth, spritePepperoni, scaleFactorJar, potLine);
            cout << "PEPPERONI" << endl;
        }
    }


    //create a PIZZA
    //TEST TO BE CHANGED LATER!!!!!!!!!!!!!!
    //dough
    sf::CircleShape pizzaShape;
    sf::Vector2f circlePosition(0,5*screenHeight/10);

    //texture
    sf::Texture cooked_cheese = loadTextureFromFile("resources/cooked-cheese.png");
    pizzas[0].setPosition(circlePosition);
    pizzas[0].setDough(screenWidth,circlePosition, xVelocity, cooked_cheese, ingredients.at("tomatoe").added, ingredients.at("cheese").added, ingredients.at("pepperoni").added);

    return circlePosition;

}

void Facade::startCooking(Preparation preparation){
    cout << "START COOKING" << endl;
    if (selected.has_value()){ //is something selected
        cout << "Selected is the following: " << selected.value().getIngredient() << endl;
        if (selected_type == "storage"){  //if the last selected object is a storage
            if (selected.value().getIngredient() == preparation.getIngredient()){ //if the selected storage corresponds to the right ingredient
                selected.emplace(preparation);
                selected_type = "preparation";
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

void Facade::addIngredient(Pizza pizza){
    cout << 1 << endl;
    if (selected_type == "preparation") {
        cout << 2 << endl;
        pizza.addIngredient(selected->getIngredient());
        ingredients.at(selected->getIngredient().getlabel()).added = true;
        cout << "PLEASE WORK!!!!!"<< selected->getIngredient() << "and we have" << ingredients.at(selected->getIngredient().getlabel()).added <<endl;
    }
}

void Facade::cout_test() {
    //test
    std::cout << "The ingredient list is: ";
    int i=0;
    for (const auto &ingredient: ingredients){
        std::cout << "the ingredient number " << i << " is " << ingredient.second.ingredient.getlabel() <<std::endl;
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


void Facade::render() {

    //render
    window.clear();
    window.draw(sprite_background);
    for(Storage& storage : storages) {
        storage.draw(window);
    }
    for(Preparation& preparation : preparations) {
        preparation.draw(window);
    }

    window.draw(pizzas[0].getDough());
    window.draw(pizzas[0].getSauce());
    window.draw(pizzas[0].getCheese());
    for (size_t i = 0; i<pizzas[0].getPepperoni().size(); i++) {
        window.draw(pizzas[0].getPepperoni()[i]);
    }

    window.display();

}

void Facade::update(const sf::Time time, unsigned int screenWidth, unsigned int screenHeight) {
    bool isTouched = false; //to test if an object was touched
    sf::Event event;
    while(window.pollEvent(event)){
        if(event.type == sf::Event::Closed) window.close();
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();

        else if (event.type == sf::Event::MouseButtonPressed) {

            cout << "PRESSED" << endl;
            if (event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                cout << "MOUSE POSITION x: " << mousePos.x << "AND y: "<< mousePos.y << endl;
                // Check for storage click
                for (Storage &storage: storages) {
                    if (storage.getSprite().getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        cout << "WE ARE TOUCHING" << endl;
                        cout << storage.getIngredient() << endl;
                        selected.emplace(storage);
                        selected_type = "storage";
                        cout << "SELECTED HAS CHANGED TO: " << selected.value().getIngredient() << endl;
                        pizzas[0].getDough().setFillColor(sf::Color::Blue); // TO BE REMOVED
                        isTouched = true;
                        break; // Exit the loop if a storage is clicked
                    }
                }

                for (Preparation &preparation: preparations) {
                    if (preparation.getSprite().getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        cout << "WE ARE PREPARING ";
                        cout << preparation.getIngredient() << endl;
                        pizzas[0].getDough().setFillColor(sf::Color::Green);  //TO BE REMOVED
                        startCooking(preparation);
                        isTouched = true;
                        break; // Exit the loop if a preparation is clicked
                    }
                }

                for (Pizza &pizza: pizzas){
                    if (pizza.getDough().getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        cout << "!!DOUGH HIT !!"<< endl;
                        addIngredient(pizza);
                    }
                    //if (pizza.getSprite().getGlobalBounds().contains(mousePos.x, mousePos.y))
                }

                if (!isTouched){
                    selected.reset();
                    selected_type = "nothing";
                    cout << "!!!touched the back !!!: " << endl;
                }
            }

            //physics
            /*
            auto circlePosition = pizzas[0].getPosition();
            pizzas[0].setPosition(sf::Vector2f(circlePosition.x + xVelocity, circlePosition.y));


            //texture
            sf::Texture cooked_cheese;
            if (!cooked_cheese.loadFromFile("resources/cooked-cheese.png")) {
                cout << "ERROR cooked-cheese IMAGE DIDN'T LOAD" << std::endl;
            }
            pizzas[0].setDough(screenWidth,circlePosition, xVelocity, cooked_cheese, ingredients.at("tomatoe").added, ingredients.at("cheese").added, ingredients.at("pepperoni").added) ;
            */
        }
    }

}

sf::Texture Facade::loadTextureFromFile(const std::string& filePath) {
    sf::Texture texture;
    if (!texture.loadFromFile(filePath)) {
        cout << "ERROR loading texture from file: " << filePath << std::endl;
    }
    return texture;
}

void pizzaGenerator(){

}




