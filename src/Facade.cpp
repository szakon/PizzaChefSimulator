//
// Created by Sarah Zakon on 06/06/2023.
//
#include "Facade.h"
#include <unordered_map>
#include <iostream>


Facade::Facade(){
    /*
    developpeurs = new HashMap<>();
    activites = new HashMap<>();
    taches = new HashMap<>()
     */
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






