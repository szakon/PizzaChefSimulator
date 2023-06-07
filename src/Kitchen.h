#pragma once
#include <string>
#include "Ingredient.h"

using namespace std;


class Kitchen {
private :
    bool selected;
protected:
    Ingredient ingredient;
public:
    explicit Kitchen(Ingredient ingredient1);
    bool getselected();
    void selection();
    void release();
    Ingredient getingredient();
};



