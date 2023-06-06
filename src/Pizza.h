#pragma once
#include "Ingredient.h"
#include <vector>
#include <map>
#include "Ingredient.h"
#include "Preparation.h"

using namespace std;

class Pizza {
private :
    std::map<Ingredient, bool> ingredients;
    bool completed;
public:
    explicit Pizza(std::vector<Ingredient> ingr);
    friend std::ostream& operator<<(std::ostream& os, const Pizza& pizza);

    friend void receiveIngredient(Preparation preparation);


};

