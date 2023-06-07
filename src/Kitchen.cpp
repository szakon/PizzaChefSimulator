#include "Kitchen.h"
#include <iostream>

using namespace std;


Kitchen::Kitchen(Ingredient ingredient1)
    : ingredient(ingredient1)
{
    selected = false;
}

Ingredient Kitchen::getingredient() {
    return ingredient;
}

bool Kitchen::getselected() {
    return selected;
}

void Kitchen::selection() {
    selected = true;
}

void Kitchen::release() {
    selected = false;
}