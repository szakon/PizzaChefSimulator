#include "Kitchen.h"
#include <iostream>

using namespace std;


Kitchen::Kitchen(Ingredient ingredient1)
    : ingredient(ingredient1)
{
    selected = false;
}

Ingredient Kitchen::getIngredient() {
    return ingredient;
}

bool Kitchen::getselected() {
    return selected;
}
