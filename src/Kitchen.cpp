#include "Kitchen.h"
#include <iostream>

using namespace std;


Kitchen::Kitchen(std::shared_ptr<Ingredient> ingredient)
        : ingredientPtr(std::move(ingredient)), selected(false)
{}

std::shared_ptr<Ingredient> Kitchen::getIngredient() {
    return ingredientPtr;
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
    os << "ingredient : " << kitchen.ingredientPtr << endl;
    os << "selected : " << kitchen.selected << endl;
    return os;
}


