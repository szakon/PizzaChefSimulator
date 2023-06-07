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

void Kitchen::unselection() {
    selected = false;
}

std::ostream& operator<<(std::ostream& os, const Kitchen& kitchen)
{
    os << "This is the Kitchen :" << endl;
    os << "ingredient : " << kitchen.ingredient << endl;
    os << "selected : " << kitchen.selected << endl;
    return os;
}

