//
// Created by Sarah Zakon on 06/06/2023.
//
#include "facade.h"
#include <unordered_map>


Facade::Facade(){
    /*
    developpeurs = new HashMap<>();
    activites = new HashMap<>();
    taches = new HashMap<>()
     */
}


void Facade::init(){
    std::unique_ptr<Ingredient> tomatoe = std::make_unique<Ingredient>("tomatoe");
    ingredients.insert(std::make_pair(0, std::move(tomatoe)));
    storages.insert(std::make_pair(0, std::make_unique<Storage>(std::move(tomatoe))));
    
    std::unique_ptr<Ingredient> cheese = std::make_unique<Ingredient>("cheese");
    ingredients.insert(std::make_pair(1, std::move(cheese)));
    storages.insert(std::make_pair(1, std::make_unique<Storage>(std::move(cheese))));


    std::unique_ptr<Ingredient> pepperoni = std::make_unique<Ingredient>("pepperoni");
    ingredients.insert(std::make_pair(2, std::move(pepperoni)));
    storages.insert(std::make_pair(2, std::make_unique<Storage>(std::move(pepperoni))));


}




