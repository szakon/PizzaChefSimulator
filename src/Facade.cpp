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
    ingredients.insert(std::make_pair(0, std::make_unique<Ingredient>("tomatoe")));
    ingredients.insert(std::make_pair(1, std::make_unique<Ingredient>("fromage")));
    ingredients.insert(std::make_pair(2, std::make_unique<Ingredient>("pepperoni")));
    std::vector<Ingredient> vectIngredients = Ingredient::getValue(ingredients);
    //storages.insert(std::make_pair(0, std::make_unique<Storage>(, get_x(), get_y(), r, color));
}




