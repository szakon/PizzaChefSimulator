#include <string>
#include "Ingredient.h"

using namespace std;
#ifndef INGREDIENT_H
#define INGREDIENT_H

Ingredient::Ingredient(const std::string name)
{
    label = name;
}

#endif // INGREDIENT_H

std::string Ingredient::getlabel() const {
    return label;
}


// Define the less-than operator implementation
bool operator<(const Ingredient& lhs, const Ingredient& rhs) {
    // Compare the labels of the ingredients for ordering
    return lhs.label < rhs.label;
}



