#include "Pizza.h"
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <iostream>
#include "Ingredient.h"

using namespace std;

Pizza::Pizza(std::vector<Ingredient> ingr)
{
    completed = false;
    for (const auto &ingredient: ingr) {
        ingredients.insert(std::make_pair(ingredient.getlabel(), false));
    }

};
