#pragma once
#include "Ingredient.h"
#include <vector>
#include <map>

using namespace std;

class Pizza {
private :
    std::map<Ingredient, bool> ingredients;
    bool completed;
public:
    explicit Pizza(std::vector<Ingredient> ingr);

};

