#include "Facade.h"
#include "SFML/Audio/Music.hpp"
#include <iostream>
#include <map>
#include <chrono>
#include <thread>

const sf::Time Facade::TimePerFrame = sf::seconds(1.f/60.f); // The game is running at 60 FPS

Facade::Facade()
    :pizzaManager()
{
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    unsigned int screenWidth = desktopMode.width;
    unsigned int screenHeight = desktopMode.height;

    // Create the SFML window with the screen size
    window.create(sf::VideoMode(screenWidth, screenHeight), "Pizza Glouton");
    window.setVerticalSyncEnabled(true);

    //setting textures
    std::vector<std::string> vect = {"bois","storage_cheese", "you_lost","storage_tomatoe", "storage_pepperoni", "preparation_tomatoe", "preparation_pepperoni", "preparation_cheese", "cooked_cheese", "check_mark", "sound_on", "sound_off", "timer", "3", "2", "1", "madame", "monsieur", "arm", "tomato_sauce", "pepperonis"};
    for (auto& element : vect) {
        textures.insert(addTextureFromFile(element));
    }

    //Background
    sprite_background.setTexture(textures.at("bois"));
    // Calculate the scale factors to fill the window
    float scaleX = static_cast<float>(window.getSize().x) / textures.at("bois").getSize().x;
    float scaleY = static_cast<float>(window.getSize().y) / textures.at("bois").getSize().y;
    sprite_background.setScale(scaleX, scaleY); // Set the scale of the sprite to fill the window


    //Create ingredients and filling the pizza pool
    Ingredient tomatoe("tomatoe",0, (170*screenWidth-20)/2500, textures.at("tomato_sauce"));
    Ingredient cheese("cheese", 1, (170*screenWidth-20)/2500, textures.at("cooked_cheese"));
    Ingredient pepperoni("pepperoni", 2, (170*screenWidth-20)/2500, textures.at("pepperonis"));
    ingredients.push_back(tomatoe);
    ingredients.push_back(cheese);
    ingredients.push_back(pepperoni);
    std::vector<Ingredient> pizzaIngredients = {tomatoe, cheese, pepperoni};
    pool.emplace(PizzaPool(pizzaIngredients));
    pizzaManager.setPool(*pool);
    pizzaManager.setIngredients(ingredients);


    //Set up the score
    sf::Font font;
    if (!font.loadFromFile("resources/font.ttf")) {
        cout << "ERROR FONT DIDN'T LOAD";
    }
    scoreText.setFont(font);

    //Set up the music
    if (!music.openFromFile("resources/music.ogg")) {
        cout << "ERROR MUSIC DIDN'T LOAD";
    }
    music.setVolume(20.0);
    music.play();
    sound_on_off = true;

    run();
}

void Facade::run() {

    // Set up the clock
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    //Initialize the game
    init();
    pizzaManager.pizzaGenerator();
    draw_init( window.getSize().x, window.getSize().y);

    //Main part of the game
    while (window.isOpen()) {

        //In case of game over
        if(pizzaManager.getLives()<0) window.close();

        sf::Time elapsedTime = clock.restart();
        timeSinceLastUpdate += elapsedTime;
        while (timeSinceLastUpdate > TimePerFrame) {
            timeSinceLastUpdate -= TimePerFrame;
            update(window.getSize().x, window.getSize().y); //Update the infos of the game
        }
        //cout << "here 1" << endl;
        pizzaManager.movePizzas(window, lifeline, textures);
        //cout << "here 3" << endl;
        //move();
        render();

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    if(pizzaManager.getLives()<=0){
        renderLost();
    }

}

void Facade::init(){

    //Set up the storages and preparations
    int i = 0;
    for (const auto &ingredient: ingredients){
        Storage storage(ingredient, 0);
        Preparation preparation1(ingredient, 1);
        Preparation preparation2(ingredient, 2);
        storages.insert(std::make_pair(ingredient.getLabel(), storage));
        preparations.push_back(preparation1);
        preparations.push_back(preparation2);
    }

}

void Facade::draw_init(unsigned int screenWidth, unsigned int screenHeight) {


    window.setFramerateLimit(60);
    sf::Vector2u windowSize = window.getSize();

    //Score
    score_board.setSize(sf::Vector2f (400,100));
    score_board.setPosition(20,20);
    score_board.setFillColor(sf::Color::Black);
    score_board.setOutlineColor(sf::Color::White);
    score_board.setOutlineThickness(3);

    scoreText.setCharacterSize(50);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(40, 30);
    scoreText.setString("Your Score: " + std::to_string(pizzaManager.getScore()));

    //Set up the sound
    setTextureScalePosition(sound, textures.at("sound_on"), 0.09, screenWidth*14/15,0);

    //Set up the conveyor belt
    belt.setSize(sf::Vector2f(screenWidth,screenHeight/3));
    belt.setPosition(0, 6*screenHeight/10-20);
    sf::Color greyColor(105, 105, 105);
    belt.setFillColor(greyColor);

    //Set up the lives
    setTextureScalePosition(lifeline, textures.at("3"), 0.15, 0,score_board.getPosition().y + score_board.getSize().y - 20 );

    //Characters
    setTextureScalePosition(madame, textures.at("madame"), 0.7*screenWidth/2500, 0, belt.getPosition().y-textures.at("madame").getSize().y*0.7*screenWidth/2500);

    monsieur.setTexture(textures.at("monsieur"));
    float scaleFactorMonsieur = 1.1*screenWidth/2500;
    sf::Vector2f monsieurPosition(window.getSize().x * 0.65-monsieur.getTextureRect().height*scaleFactorMonsieur/3,belt.getPosition().y-monsieur.getTextureRect().height*scaleFactorMonsieur/4);
    monsieur.setScale(scaleFactorMonsieur, scaleFactorMonsieur);
    monsieur.setPosition(monsieurPosition);

    setTextureScalePosition(monsieur_arm, textures.at("arm"), scaleFactorMonsieur, monsieurPosition.x, monsieurPosition.y);

    float scaleFactorJar = 0.9f*screenWidth/2500;

    //create the cheese jar
    sf::Sprite spriteCheese;

    //create the tomatoe jar
    sf::Sprite spriteTomatoe;


    for(auto& storage : storages) {
        storage.second.setSprite(textures.at("storage_"+storage.second.getIngredient().getLabel()), scaleFactorJar, screenWidth, sprite_background, 0.0, 0.0, textures.at("timer"));

    }

    //create a pot
    float scaleFactorPot = 0.2f*screenWidth/2500;
    float potLine = 20 + 1.2f * storages.at("tomatoe").getSprite().getTextureRect().height*scaleFactorJar;

    //random sprite used for preparations
    for(auto& preparation : preparations) {
        preparation.setSprite(textures.at("preparation_"+preparation.getIngredient().getLabel()), scaleFactorPot, screenWidth, spriteTomatoe, scaleFactorJar, potLine, textures.at("timer"), textures.at("check_mark"));
    }

    float circlePositionX = 0;

}

void Facade::startCooking(Preparation &preparation){
    if (selected.has_value()){ //is something selected
        cout << "Selected: " << selected.value().getIngredient() << endl;
        if (selected_type == "storage"){  //if the last selected object is a storage
            if (selected.value().getIngredient() == preparation.getIngredient()){ //if the selected storage corresponds to the right ingredient
                preparation.setStatus("inprep");
                cout << "Beginning prep : change status to : " << preparation.getStatus() << endl;
                selected.emplace(preparation);
                selected_type = "preparation";

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

void Facade::selectReady(Preparation &preparation) {
    selected.emplace(preparation);
    selected_type = "preparation";
    preparation.setSelected(true);
}

void Facade::render() {

    window.clear();
    window.draw(sprite_background);
    for(auto& storage : storages) {
        storage.second.draw(window);
    }
    for(auto& preparation : preparations) {
        preparation.draw(window);
    }

    window.draw(score_board);
    scoreText.setString("Your Score: " + std::to_string(pizzaManager.getScore()));
    window.draw(scoreText);

    if (pizzaManager.getLives() == 2) {
        lifeline.setTexture(textures.at("2"));
    } else if (pizzaManager.getLives() == 1) {
        lifeline.setTexture(textures.at("1"));
    }
    if (pizzaManager.getLives() == 0) {
        cout << "Perdu";
        window.close();
    }
    window.draw(lifeline);

    window.draw(madame);
    window.draw(belt);
    window.draw(monsieur);


    pizzaManager.printPizza(window);

    window.draw(monsieur_arm);

    window.draw(sound);

    window.display();

}

void Facade::renderLost(){
    sf::VideoMode desktopMode2 = sf::VideoMode::getDesktopMode();
    unsigned int screenWidth2 = desktopMode2.width;
    unsigned int screenHeight2 = desktopMode2.height;
    sf::RenderWindow window2(sf::VideoMode(800, 600), "Window 2");

    window2.setFramerateLimit(60);
    window2.create(sf::VideoMode(screenWidth2, screenHeight2), "Lose window");
    while (window2.isOpen()) {
        sf::Texture dead = loadTextureFromFile("resources/you_lost.png");
        sf::Sprite death;
        death.setTexture(dead);
        //death.setScale(1, 1);
        float scaleX2 = static_cast<float>(window2.getSize().x) / dead.getSize().x;
        float scaleY2 = static_cast<float>(window2.getSize().y) / dead.getSize().y;
        death.setScale(scaleX2, scaleY2); // Set the scale of the sprite to fill the window
        //death.setPosition(window2.getSize().x/2.f - death.getScale().x, window2.getSize().y/2.f - death.getScale().y);
        //death.setPosition(500, 500);
        sf::Event event2;
        while(window2.pollEvent(event2)) {
            if (event2.type == sf::Event::Closed) window2.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window2.close();
        }
        window2.clear();
        window2.draw(death);
        window2.display();

    }
}

void Facade::update(unsigned int screenWidth, unsigned int screenHeight) {

    bool isTouched = false; //to test if an object was touched

    //Update the preparations preparing
    for (auto& prep : preparations) {
        prep.preparing_if_needed();
    }

    sf::Event event;
    while(window.pollEvent(event)){
        if(event.type == sf::Event::Closed) window.close();
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();

        else if (event.type == sf::Event::MouseButtonPressed) {

            if (event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                // Check for storage click
                for (auto &storage: storages) {
                    if (storage.second.getSprite().getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        cout << storage.second.getIngredient() << endl;
                        selected.emplace(storage.second);
                        selected_type = "storage";
                        isTouched = true;
                        break; // Exit the loop if a storage is clicked
                    }
                }
                //Check for preparation click

                for (auto&preparation: preparations) {
                    if (preparation.getSprite().getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        if(preparation.getStatus() == "ready") { //If the preparation is ready to be put on the pizza
                            selectReady(preparation);
                            isTouched = true;
                            //change sprite
                        }
                        else if (preparation.getStatus() == "notused"){ //If we need to cook the ingredient
                            cout << preparation.getIngredient() << endl;
                            startCooking(preparation);
                            isTouched = false;
                            selected = nullopt;
                        }
                        else {
                            isTouched = false;
                            selected = nullopt;
                        }

                    }
                }

                if (selected_type == "preparation") {
                    bool added = pizzaManager.checkPizzaClick(selected, mousePos);
                    if(added){
                        for (auto &prep: preparations) {
                            if (selected->getIngredient() == prep.getIngredient() &&
                                prep.getSelected() == true &&
                                selected->getPrepId() == prep.getPrepId()) {
                                prep.reset();
                            }
                        }
                    }
                }

                /*
                for (auto& pizza: pizzas){
                    if (pizza.getDough().getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        cout << "PIZZA TOUCHED: pizza id: " << pizza.getId() << endl;

                        if (selected_type == "preparation") {
                            score += pizza.addIngredient(selected->getIngredient());
                            for (auto &prep: preparations) {
                                if (selected->getIngredient() == prep.getIngredient() &&
                                    prep.getSelected() == true &&
                                    selected->getPrepId() == prep.getPrepId()) {
                                    prep.reset();
                                }
                            }
                        }
                        //cout << "circles length at the end of addIngredient in facade: " << pair.second.pizza.getCircles().size() << endl;
                    }
                    //if (pizza.getSprite().getGlobalBounds().contains(mousePos.x, mousePos.y))
                    //cout << "circles length at the end of addIngredient in facade 2: " << pair.second.pizza.getCircles().size() << endl;

                }*/

                if(sound.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    if(sound_on_off) {
                        sound_on_off = false;
                        sound.setTexture(textures.at("sound_off"));
                        music.pause();

                    }
                    else{
                        sound_on_off = true;
                        sound.setTexture(textures.at("sound_on"));
                        music.play();
                    }
                }

                if (!isTouched){
                    selected.reset();
                    selected_type = "nothing";
                }
            }

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


std::pair<std::string,sf::Texture> Facade::addTextureFromFile(const std::string& name) {
    sf::Texture texture;
    if (!texture.loadFromFile("resources/"+name+".png")) {
        cout << "ERROR loading texture from file: " << "resources/"+name+".png" << std::endl;
    }

    return std::make_pair(name, texture);
}

void Facade::setTextureScalePosition(sf::Sprite& sprite, sf::Texture& texture, double scale, double position_x, double position_y) {
    sprite.setTexture(texture);
    sprite.setScale(scale,scale);
    sprite.setPosition(position_x, position_y);
}



