#include <string>
#include <ostream>
#include <cstring>
#include <vector>
#include "Ingredient.h"
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

Ingredient::Ingredient(const std::string name, const int order, const float radius, sf::Texture& texture, const float place)
{
    label = name;
    this->order = order;
    this->radius = radius;
    position = place;

    circle.setRadius(radius);
    circle.setTexture(&texture);
}


std::string Ingredient::getLabel() const {
    return label;
}

float Ingredient::getPosition() const {
    return position;
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
    return lhs.order < rhs.order;
}

// Define the equal operator implementation
bool operator==(const Ingredient& lhs, const Ingredient& rhs) {
    // Compare the labels of the ingredients for ordering
    return lhs.label == rhs.label;
}


void Ingredient::printIngredient(sf::RenderWindow& window, sf::Vector2<float> ingredientPosition){
    circle.setPosition(ingredientPosition);
    window.draw(circle);
}



