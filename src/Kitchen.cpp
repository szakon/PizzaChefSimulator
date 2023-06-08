#include "Kitchen.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;


Kitchen::Kitchen(Ingredient ingr,sf::Texture texture)
        : ingredient(ingr), selected(false)
{
    sprite.setTexture(texture);
}

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


