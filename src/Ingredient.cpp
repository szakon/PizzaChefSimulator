#include <string>
#include <ostream>
#include <cstring>
#include <vector>
#include "Ingredient.h"
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

Ingredient::Ingredient(const std::string name, const int order, const float radius, sf::Texture& texture, std::string preparation, std::string storage, sf::Texture& recipeTex, int preparations, std::string preparation2)
{
    label = name;
    this->order = order;
    this->radius = radius;
    this->preparation = preparation;
    this->numPreparations = preparations;
    this->storage = storage;
    this->preparation2 = preparation2;

    circle.setRadius(radius);
    circle.setTexture(&texture);
    recipe.setTexture(recipeTex);
    recipe.setScale(0.15, 0.15);
}


std::string Ingredient::getLabel() const {
    return label;
}

int Ingredient::getNumPreparations() const {
    return numPreparations;
}

std::string Ingredient::getPreparation() const {
    return preparation;
}

std::string Ingredient::getPreparation2() const {
    return preparation2;
}

std::string Ingredient::getStorage() const {
    return storage;
}

int Ingredient::getOrder() {
    return order;
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

void Ingredient::printRecipe(sf::RenderWindow& window, int pizzaNum, sf::Sprite postit){
    cout << "Pizza num " << pizzaNum << "Printing this ingredient " << label << endl;
    recipe.setPosition(postit.getPosition().x + postit.getTextureRect().height*postit.getScale().x*0.1*(order+1), postit.getPosition().y + postit.getTextureRect().width*postit.getScale().y*(0.4+0.2*(pizzaNum-1)));
    window.draw(recipe);

}



