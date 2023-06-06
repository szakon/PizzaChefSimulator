#include "Pizza.h"
#include <string>
#include <vector>
#include <map>
#include "Ingredient.h"

using namespace std;

Pizza::Pizza(std::vector<Ingredient> ingr)
{
    completed = 0;
    for (const auto &ingredient: ingr) {
        ingredients[ingredient.getlabel()] = 0;
    }

};
