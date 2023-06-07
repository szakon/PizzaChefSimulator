#pragma once
#include <string>
#include "Ingredient.h"

using namespace std;


class Kitchen {
private :
    bool selected;
protected:
    std::unique_ptr<Ingredient> ingredientPtr;
public:
    explicit Kitchen(std::unique_ptr<Ingredient> ingredientPtr);
    std::unique_ptr<Ingredient>  getIngredient();
    bool getselected();

};



