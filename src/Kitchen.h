#pragma once
#include <string>
#include "Ingredient.h"

using namespace std;


class Kitchen {
protected:
    bool selected;
    std::shared_ptr<Ingredient> ingredientPtr;
public:
    explicit Kitchen(std::shared_ptr<Ingredient> ingredientPtr);
    shared_ptr<Ingredient> getIngredient();

    bool getselected() const;
    void selection();
    void unselection();
    std::shared_ptr<Ingredient> getingredient() const;
    friend std::ostream& operator<<(std::ostream& os, const Kitchen& kitchen);
};



