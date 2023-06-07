#include "Kitchen.h"
#include <iostream>

using namespace std;


Kitchen::Kitchen(std::unique_ptr<Ingredient> ingredient)
        : ingredientPtr(std::move(ingredient)), selected(false)
{}

std::unique_ptr<Ingredient> Kitchen::getIngredient() {
    return std::move(ingredientPtr);
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