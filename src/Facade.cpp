#include "Facade.h"
#include "SFML/Audio/Music.hpp"
#include <iostream>
#include <map>
#include <chrono>
#include <thread>

const sf::Time Facade::TimePerFrame = sf::seconds(1.f/60.f); // The game is running at 60 FPS
const float Facade::xVelocity = 10; //movement of the pizzas

Facade::Facade(){

    score = 0;
    lives = 3;

    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    unsigned int screenWidth = desktopMode.width;
    unsigned int screenHeight = desktopMode.height;

    // Create the SFML window with the screen size
    window.create(sf::VideoMode(screenWidth, screenHeight), "My little kitchen");

    //Background
    sf::Texture bois = loadTextureFromFile("resources/bois1.jpg");
    sprite_background.setTexture(bois);
    // Calculate the scale factors to fill the window
    float scaleX = static_cast<float>(window.getSize().x) / bois.getSize().x;
    float scaleY = static_cast<float>(window.getSize().y) / bois.getSize().y;
    sprite_background.setScale(scaleX, scaleY); // Set the scale of the sprite to fill the window

    //Characters
    sf::Texture madame_texture = loadTextureFromFile("resources/madame_tete_en_lair.png");
    madame.setTexture(madame_texture);
    madame.setScale(0.9,0.9);
    madame.setPosition(sf::Vector2f(-200,window.getSize().y/6));
    sf::Texture monsieur_texture = loadTextureFromFile("resources/monsieur_glouton.png");
    monsieur.setTexture(monsieur_texture);
    monsieur.setScale(0.7, 0.7);
    monsieur.setPosition(sf::Vector2f(window.getSize().x/3,window.getSize().y/3));
    sf::Texture texture_arm = loadTextureFromFile("resources/arm_monsieur.png");
    monsieur_arm.setTexture(texture_arm);
    monsieur_arm.setScale(0.7, 0.7);
    monsieur_arm.setPosition(sf::Vector2f(window.getSize().x/3,window.getSize().y/3));

    //setting textures
    sf::Texture cheese_jar = loadTextureFromFile("resources/storage_cheese.png");
    sf::Texture tomatoe_jar = loadTextureFromFile("resources/storage_tomatoe.png");
    sf::Texture pepperoni_jar = loadTextureFromFile("resources/storage_pepperoni.png");
    sf::Texture grater = loadTextureFromFile("resources/grater.png");
    sf::Texture pot = loadTextureFromFile("resources/pot.png");
    sf::Texture cut = loadTextureFromFile("resources/cutting_board.png");
    sf::Texture cooked_cheese = loadTextureFromFile("resources/cooked-cheese.png");
    sf::Texture check = loadTextureFromFile("resources/check_mark.png");
    sf::Texture timer = loadTextureFromFile("resources/stopwatch.png");
    sf::Texture sound_on = loadTextureFromFile("resources/sound_on.png");
    sf::Texture sound_off = loadTextureFromFile("resources/sound_off.png");
    sf::Texture lives3 = loadTextureFromFile("resources/3.png");
    sf::Texture lives2 = loadTextureFromFile("resources/2.png");
    sf::Texture lives1 = loadTextureFromFile("resources/1.png");
    textures.insert(std::make_pair("cheese_jar", cheese_jar));
    textures.insert(std::make_pair("tomatoe_jar", tomatoe_jar));
    textures.insert(std::make_pair("pepperoni_jar", pepperoni_jar));
    textures.insert(std::make_pair("grater", grater));
    textures.insert(std::make_pair("pot", pot));
    textures.insert(std::make_pair("cut", cut));
    textures.insert(std::make_pair("cooked_cheese", cooked_cheese));\
    textures.insert(std::make_pair("check", check));
    textures.insert(std::make_pair("timer", timer));
    textures.insert(std::make_pair("sound_on", sound_on));
    textures.insert(std::make_pair("sound_off", sound_off));
    textures.insert(std::make_pair("lives3", lives3));
    textures.insert(std::make_pair("lives2", lives2));
    textures.insert(std::make_pair("lives1", lives1));

    //Create ingredients and filling the pizza pool
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
    pool.emplace(PizzaPool(pizzaIngredients));


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
    pizzaGenerator();
    draw_init( window.getSize().x, window.getSize().y);

    //Main part of the game
    while(window.isOpen()){

        sf::Time elapsedTime = clock.restart();
        timeSinceLastUpdate += elapsedTime;
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
            update(window.getSize().x, window.getSize().y); //Update the infos of the game
        }

        for(auto &pair: pizzas){
            if(pair.second.pizza.getCirclePosition().x > window.getSize().x*0.65) { //we are at the end of the line
                //circlePosition = sf::Vector2f(0,5*screenHeight/10);
                //saucePosition = sf::Vector2f(200*screenWidth/2500-170*screenWidth/2500,5*screenHeight/10+200*screenWidth/2500-170*screenWidth/2500);
                //pizzas.front().invisible();
                if(!pair.second.pizza.getComplete()) { // If the pizza is not completed with all ingredients
                    score -= 10;
                    lives-=1;
                }
                else {
                    score +=10;
                }
                releasePizza(pair.second.pizza);
                if(lives == 2) {
                    lifeline.setTexture(textures.at("lives2"));
                }
                else if (lives ==1) {
                    lifeline.setTexture(textures.at("lives1"));
                }
                if (lives == 0){
                    cout << "Perdu";
                    window.close();
                }
                break;


            }else if(pair.second.pizza.getCirclePosition().x > window.getSize().x*0.2){ //we need to display a new pizza
                if (pair.second.newPizzaGenerated == false){
                    pizzaGenerator();
                    pair.second.newPizzaGenerated = true;
                }
                unsigned int cPosition = pair.second.pizza.getCirclePosition().x + xVelocity;
                pair.second.pizza.setDough(window.getSize().x, window.getSize().y, cPosition, xVelocity, textures.at("cooked_cheese"), pair.second.pizza.getIngredientStatus("tomatoe"), pair.second.pizza.getIngredientStatus("cheese"), pair.second.pizza.getIngredientStatus("pepperoni")) ;

            }
            else {
                unsigned int cPosition = pair.second.pizza.getCirclePosition().x + xVelocity;
                pair.second.pizza.setDough(window.getSize().x, window.getSize().y, cPosition, xVelocity, textures.at("cooked_cheese"), pair.second.pizza.getIngredientStatus("tomatoe"), pair.second.pizza.getIngredientStatus("cheese"), pair.second.pizza.getIngredientStatus("pepperoni")) ;
            }

        }

        render();

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

}

void Facade::init(){

    //Set up the storages and preparations
    int i = 0;
    for (const auto &ingredient: ingredients){
        Storage storage(ingredient.second.ingredient, 0);
        Preparation preparation1(ingredient.second.ingredient, 1);
        Preparation preparation2(ingredient.second.ingredient, 2);
        storages.push_back(storage);
        preparations.push_back(preparation1);
        preparations.push_back(preparation2);

    }

}

void Facade::draw_init(unsigned int screenWidth, unsigned int screenHeight) {

    cout << "WIDTH" << screenWidth << endl;
    cout << "HEIGHT" << screenHeight << endl;

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
    scoreText.setString("Your Score: " + std::to_string(score));

    //Set up the sound
    sound.setTexture(textures.at("sound_on"));
    sound.setScale(0.09,0.09);
    sound.setPosition(screenWidth*14/15, 0);

    //Set up the conveyor belt
    belt.setSize(sf::Vector2f(screenWidth,screenHeight/3));
    belt.setPosition(0, 6*screenHeight/10-20);
    sf::Color greyColor(105, 105, 105);
    belt.setFillColor(greyColor);

    //Set up the lives
    lifeline.setTexture(textures.at("lives3"));
    lifeline.setScale(0.15,0.15);
    lifeline.setPosition(0,score_board.getPosition().y + score_board.getSize().y - 20);

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
            storage.setSprite(textures.at("tomatoe_jar"), scaleFactorJar, positionTomatoe, screenWidth, sprite_background, 0.0, 0.0, textures.at("timer"));
            spriteTomatoe = storage.getSprite();
            cout << spriteTomatoe.getTextureRect().height << std::endl;
        }
        else if (storage.getIngredient().getlabel() == "cheese") {
            storage.setSprite(textures.at("cheese_jar"), scaleFactorJar, positionCheese, screenWidth, sprite_background, 0.0, 0.0, textures.at("timer"));
            spriteCheese = storage.getSprite();
        }
        else if (storage.getIngredient().getlabel() == "pepperoni") {
            storage.setSprite(textures.at("pepperoni_jar"), scaleFactorJar, positionPepperoni, screenWidth, sprite_background, 0.0, 0.0, textures.at("timer"));
            spritePepperoni = storage.getSprite();
        }
    }

    //create a pot
    //sf::Texture pot = loadTextureFromFile("resources/pot.png");
    float scaleFactorPot = 0.2f*screenWidth/2500;
    float potLine = 20 + 1.2f * spriteTomatoe.getTextureRect().height*scaleFactorJar;

    //create a cutting board
    //sf::Texture cut = loadTextureFromFile("resources/cutting_board.png");

    //create a grater
    //sf::Texture grater = loadTextureFromFile("resources/grater.png");
    float scaleFactorGrater = 0.1f*screenWidth/2500;

    //random sprite used for preparations
    for(Preparation& preparation : preparations) {
        if(preparation.getIngredient().getlabel() == "tomatoe") {
            preparation.setSprite(textures.at("pot"), scaleFactorPot, positionTomatoe, screenWidth, spriteTomatoe, scaleFactorJar, potLine, textures.at("timer"), textures.at("check"));
        }
        else if (preparation.getIngredient().getlabel() == "cheese") {
            preparation.setSprite(textures.at("grater"), scaleFactorGrater, positionCheese+1.5, screenWidth, spriteCheese, scaleFactorJar, potLine, textures.at("timer"), textures.at("check"));
        }
        else if (preparation.getIngredient().getlabel() == "pepperoni") {
            preparation.setSprite(textures.at("cut"), scaleFactorPot, positionPepperoni, screenWidth, spritePepperoni, scaleFactorJar, potLine, textures.at("timer"), textures.at("check"));
        }
    }

    float circlePositionX = 0;

    for (auto pair: pizzas){
        pair.second.pizza.setDough(screenWidth, screenHeight, circlePositionX, xVelocity, textures.at("cooked_cheese"), pair.second.pizza.getIngredientStatus("tomatoe"), pair.second.pizza.getIngredientStatus("cheese"), pair.second.pizza.getIngredientStatus("pepperoni"));
    }

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


void Facade::addIngredient(Pizza pizza){
    if (selected_type == "preparation") {
        score += pizza.addIngredient(selected->getIngredient());
        ingredients.at(selected->getIngredient().getlabel()).added = true;
        for(Preparation prep : preparations) {
            if(selected->getIngredient() == prep.getIngredient() && prep.getSelected() == true && selected->getPrepId() == prep.getPrepId()) {
                prep.reset();
            }
        }
    }
}

void Facade::addRandomIngredient(Pizza pizza, Ingredient ingredient) {
    pizza.addIngredient(ingredient);
    ingredients.at(ingredient.getlabel()).added = true;

}

void Facade::render() {

    window.clear();
    window.draw(sprite_background);
    for(Storage& storage : storages) {
        storage.draw(window);
    }
    for(Preparation& preparation : preparations) {
        preparation.draw(window);
    }

    window.draw(score_board);
    scoreText.setString("Your Score: " + std::to_string(score));
    window.draw(scoreText);

    window.draw(lifeline);

    window.draw(madame);
    window.draw(belt);
    window.draw(monsieur);


    for (auto &pair: pizzas) {
        window.draw(pair.second.pizza.getDough());
        window.draw(pair.second.pizza.getSauce());
        window.draw(pair.second.pizza.getCheese());
        for (size_t i = 0; i < pair.second.pizza.getPepperoni().size(); i++) {
            window.draw(pair.second.pizza.getPepperoni()[i]);
        }
    }

    window.draw(monsieur_arm);

    window.draw(sound);

    window.display();

}

void Facade::update(unsigned int screenWidth, unsigned int screenHeight) {

    bool isTouched = false; //to test if an object was touched

    //Update the preparations preparing
    for (Preparation prep : preparations) {
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
                for (Storage &storage: storages) {
                    if (storage.getSprite().getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        cout << storage.getIngredient() << endl;
                        selected.emplace(storage);
                        selected_type = "storage";
                        isTouched = true;
                        break; // Exit the loop if a storage is clicked
                    }
                }
                //Check for preparation click
                for (Preparation &preparation: preparations) {
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

                for (auto pair: pizzas){
                    if (pair.second.pizza.getDough().getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        addIngredient(pair.second.pizza);
                    }
                    //if (pizza.getSprite().getGlobalBounds().contains(mousePos.x, mousePos.y))
                }

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

void Facade::pizzaGenerator(){
    Pizza pizza = pool->acquirePizza();
    randomIngr(pizza);
    Piz piz = {pizza, false};

    pizzas.insert(std::make_pair(pizza.getId(), piz));
    pizza.setDough(window.getSize().x, window.getSize().y, 0, xVelocity, textures.at("cooked_cheese"), pizza.getIngredientStatus("tomatoe"), pizza.getIngredientStatus("cheese"), pizza.getIngredientStatus("pepperoni"));

}


void Facade::releasePizza(Pizza pizza){
    pizza.resetPizza();
    int pizzasIndex = 0;
    for (auto &pair: pizzas){
        if(pair.second.pizza == pizza){
            pizzas.erase(pair.first);
            break;
        }
        pizzasIndex++;
    }
    pool->releasePizza(pizza);
}

void Facade::randomIngr(Pizza pizza){
    std::random_device rd;
    std::mt19937 mt(rd());
    std::vector<int> values = {0, 1};
    std::uniform_int_distribution<int> distribution(0, 1);
    int randomIndex = distribution(mt);
    int numIngredients = values[randomIndex];
    if (numIngredients == 1){
        std::vector<Ingredient> ingrs;
        for (auto& ingredient: ingredients){
            ingrs.push_back(ingredient.second.ingredient);
        }
        std::random_device rd1;
        std::mt19937 mt1(rd1());

        std::uniform_int_distribution<int> distribution(0, ingredients.size() - 1);
        int randomIndex1 = distribution(mt1);
        Ingredient ingredient = ingrs[randomIndex1];

        addRandomIngredient(pizza, ingredient);
    }


}





