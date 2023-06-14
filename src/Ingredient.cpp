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
    os << "This is the Ingredient :" << endl;
    os << "label : " << ingredient.label << endl;
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

std::vector<Ingredient> getValue(std::map<int, std::unique_ptr<Ingredient>> map) {
    std::vector<Ingredient> values;
    for (const auto& pair : map) {
        Ingredient* ingredientPtr = pair.second.get();  // Get the raw pointer from unique_ptr
        Ingredient ingredient(*ingredientPtr);  // Instantiate an Ingredient object
        values.push_back(ingredient);
    }
    return values;
}



