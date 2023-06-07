#include "Kitchen.h"
#include <iostream>

using namespace std;


Kitchen::Kitchen(Ingredient ingr)
        : ingredient(ingr), selected(false)
{}

Ingredient Kitchen::getIngredient() {
    return ingredient;
}

bool Kitchen::getselected() const {
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


