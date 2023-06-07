//
// Created by Sarah Zakon on 06/06/2023.
//
#include "Facade.h"
#include <unordered_map>


Facade::Facade(){
    /*
    developpeurs = new HashMap<>();
    activites = new HashMap<>();
    taches = new HashMap<>()
     */
}


void Facade::init(){

    Ingredient tomatoe("tomatoe");
    Ingredient cheese("cheese");
    Ingredient pepperoni("pepperoni");
    ingredients.insert(std::make_pair("tomatoe", tomatoe));
    ingredients.insert(std::make_pair("cheese", cheese));
    ingredients.insert(std::make_pair("pepperoni", pepperoni));

    /*
    int i = 0;
    for (const auto &ingredient: ingredients){
        Storage storage(ingredients.second);
        storages.push_back()
    }*/


}




