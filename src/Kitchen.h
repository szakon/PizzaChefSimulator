#pragma once
#include <string>
#include "Ingredient.h"

using namespace std;


class Kitchen {
protected:
    Ingredient ingredient;
    bool selected;
public:
    explicit Kitchen(Ingredient ingredient1);
    bool getselected();
    void selection();
    void unselection();
    Ingredient getingredient();
    friend std::ostream& operator<<(std::ostream& os, const Kitchen& kitchen);
};



