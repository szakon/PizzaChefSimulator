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

std::ostream& operator<<(std::ostream& os, const Pizza& pizza)
{
    os << "the Pizza contains the following ingredients";
    for(const auto &ingredient: pizza.ingredients){
        string key = ingredient.first.getlabel();
        bool value = ingredient.second;
        os << key << " and it's print status is : " << value << " , ";
    }
    return os;
}
