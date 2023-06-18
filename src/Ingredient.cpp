#include <string>
#include <ostream>
#include <cstring>
#include <vector>
#include "Ingredient.h"
#include <unordered_map>
#include <SFML/Graphics.hpp>

using namespace std;

Ingredient::Ingredient(const std::string name)
{
    label = name;
}

std::string Ingredient::getlabel() const {
    return label;
}

std::ostream& operator<<(std::ostream& os, const Ingredient& ingredient)
{
    os << "Ingredient : {";
    os << "label : " << ingredient.label << "}" << endl;
    return os;
}

// Define the less-than operator implementation
bool operator<(const Ingredient& lhs, const Ingredient& rhs) {
    // Compare the labels of the ingredients for ordering
    return lhs.label < rhs.label;
}

// Define the equal operator implementation
bool operator==(const Ingredient& lhs, const Ingredient& rhs) {
    // Compare the labels of the ingredients for ordering
    return lhs.label == rhs.label;
}




