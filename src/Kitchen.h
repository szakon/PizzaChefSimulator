#pragma once
#include <string>
#include "Ingredient.h"

using namespace std;


class Kitchen {
protected:
    bool selected;
    Ingredient ingredient;
public:
    explicit Kitchen(Ingredient ingr);
    Ingredient getIngredient();

    bool getselected() const;
    void selection();
    void unselection();
    Ingredient getingredient() const;
    friend std::ostream& operator<<(std::ostream& os, const Kitchen& kitchen);
};



