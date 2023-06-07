#include "Pizza.h"
#include <string>
#include <utility>
#include <vector>
#include <map>
#include <unordered_map>
#include <iostream>
#include "Ingredient.h"
#include "Preparation.h"

using namespace std;

int Pizza::id_count = 0;

Pizza::Pizza(const std::vector<Ingredient>& ingr, std::vector<Preparation> prep)
{
    completed = false;
    id = id_count++;
    for (const auto &ingredient: ingr) {
        ingredients.insert(std::make_pair(ingredient, false));
    }
    preparations = std::move(prep);
}

std::ostream& operator<<(std::ostream& os, const Pizza& pizza)
{
    os << "the Pizza contains the following ingredients";
    for(const auto &ingredient: pizza.ingredients){
        string key = ingredient.first.getlabel();
        bool value = ingredient.second;
        os << key << " and it's print status is : " << value << endl;
    }
    return os;
}


std::map<Ingredient, bool> Pizza::getIngredients() {
    return ingredients;
}

std::vector<Preparation> Pizza::getPreparations() {
    return preparations;
}

int Pizza::addIngredient() {
    for(Preparation& prep : preparations) {
        if(prep.getselected() && prep.getready() && !ingredients[prep.getIngredient()]) {
            ingredients[prep.getIngredient()] = true;
            prep.reset();
        }
    }
    return 0;
}


