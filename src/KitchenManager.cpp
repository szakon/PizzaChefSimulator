//
// Created by Sarah Zakon on 11/09/2023.
//
#include "KitchenManager.h"
#include "SFML/Audio/Music.hpp"
#include <iostream>
#include <map>


KitchenManager::KitchenManager() {
}


void KitchenManager::setIngredients(std::vector<Ingredient> ingredients){
    this->ingredients = ingredients;
}

void KitchenManager::setTextures(std::map<std::string, sf::Texture> textures){
    this->textures = textures;
}

void KitchenManager::setSelected(Kitchen element){
    selected.emplace(element);
}

void KitchenManager::setSelectedType(std::string string){
    selected_type = string;
}

void KitchenManager::resetSelected(){
    selected.reset();
}

std::optional<Kitchen> KitchenManager::getSelected(){
    return selected;
}


std::string KitchenManager::getSelectedType(){
    return selected_type;
}

std::vector<Preparation> KitchenManager::getPreparations(){
    return preparations;
}



std::vector<Storage> KitchenManager::getStorages(){
    return storages;
}


void KitchenManager::initPrepAndStorage(){
    for (const auto &ingredient: ingredients){
        cout << ingredient.getStorage() << endl;
        cout << scaleFactorJar << endl;
        cout << "this? " << textures.at(ingredient.getStorage()).getSize().x << endl;
        Storage storage(ingredient, 0, textures.at(ingredient.getStorage()), scaleFactorJar);
        cout << 1 << endl;
        storages.push_back(storage);
        for (int i = 0; i<2*ingredient.getNumPreparations(); i++){
            Preparation preparation(ingredient, i, textures.at(ingredient.getPreparation()), scaleFactorPot, textures.at(ingredient.getPreparation2()));
            preparations.push_back(preparation);
        }
    }
}


void KitchenManager::startCooking(Preparation &preparation){
    if (selected.has_value()){ //is something selected
        cout << "Selected: " << selected.value().getIngredient() << endl;
        if (selected_type == "storage" || selected_type == "first preparation"){  //if the last selected object is a storage
            //if (selected.value().getIngredient() == preparation.getIngredient() && preparation.getPreparationOrder()!=1){
            if (selected.value().getIngredient() == preparation.getIngredient() && preparation.getPreparationOrder()!=2){ //if the selected storage corresponds to the right ingredient
                preparation.setStatus("inprep");
                selectReady(preparation);

            }else{
                cout << "ERROR: you selected the wrong ingredient" << endl;
            }

        } else {

            cout << "ERROR: you didn't select a storage" << endl;
        }
        if (preparation.getPreparationOrder() == 2){
            if(selected_type == "first preparation"){
                for (auto &prep: preparations) {
                    if (selected->getIngredient() == prep.getIngredient() &&
                        prep.getSelected() == true &&
                        selected->getPrepId()%2 == prep.getPrepId()%2) {
                        preparation.setStatus("inprep");
                        selectReady(preparation);
                        prep.reset();
                        cout << "HERE" << endl;
                        break;
                    }
                }
            }
        }

    } else {
        cout << "ERROR: nothing was selected" << endl;
    }
}


void KitchenManager::selectReady(Preparation &preparation) {
    selected.emplace(preparation);
    cout << "PREPARATION ORDER: " << preparation.getPreparationOrder() << endl;
    if (preparation.getPreparationOrder() == 1){
        selected_type = "first preparation";
        cout << "First preparation type attributed" << endl;
    }else{
        selected_type = "preparation";
        cout << "Regular preparation type attributed" << endl;
    }
    preparation.setSelected(true);
}

void KitchenManager::printKitchen(sf::RenderWindow& window){
    for(auto& storage : storages) {
        storage.draw(window);
    }
    for(auto& preparation : preparations) {
        preparation.draw(window);
    }
}

bool KitchenManager::onTouchedStorage(sf::Vector2i mousePos, sf::RenderWindow& window){
    bool isTouched = false;
    cout << "SELECTED TYPE: " << selected_type << endl;
    for (auto &storage: storages) {
        if (storage.getSprite().getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            cout << storage.getIngredient() << endl;
            selected.emplace(storage);
            selected_type = "storage";
            isTouched = true;
            break; // Exit the loop if a storage is clicked
        }
    }
    return isTouched;
}


bool KitchenManager::onTouchedPreparation(sf::Vector2i mousePos, sf::RenderWindow& window) {
    bool isTouched = false;
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
    return isTouched;
}

void KitchenManager::setSprites(){
    float scaleFactorJar = 0.9f*screenWidth/2500;

    //create the cheese jar
    sf::Sprite spriteCheese;

    //create the tomatoe jar
    sf::Sprite spriteTomatoe;

    for(auto& storage : storages) {
        storage.setSprite(scaleFactorJar,screenWidth, 0.0, 0.0, textures.at("timer"));
    }

    //create a pot
    float scaleFactorPot = 0.15f*screenWidth/2500;
    cout<< "Before potline";
    cout << "first storage: " << storages[0] << endl;
    float potLine = 20 + 1.2f * storages[0].getSprite().getTextureRect().height*scaleFactorJar;
    cout<< "After potline";
    //random sprite used for preparations
    for(auto& preparation : preparations) {
        preparation.setSprite(scaleFactorPot, screenWidth, spriteTomatoe, scaleFactorJar, potLine, textures.at("timer"), textures.at("check_mark"));
    }
}

void KitchenManager::prepareIfNeeded(sf::Time elapsed_time){
    for (auto& prep : preparations) {
        prep.preparing_if_needed(elapsed_time);
    }
}
