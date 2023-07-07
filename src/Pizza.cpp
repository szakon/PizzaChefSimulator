#include "Pizza.h"
#include <string>
#include <utility>
#include <vector>
#include <random>
#include <map>
#include <unordered_map>
#include <iostream>
#include "Ingredient.h"
#include "Preparation.h"
#include <SFML/Graphics.hpp>

using namespace std;

int nextId = 0;

Pizza::Pizza(std::vector<Ingredient>& ingr)
{
    id = nextId++;
    completed = false;
    for (auto &ingredient: ingr) {
        ingredients.insert(std::make_pair(ingredient, std::make_shared<bool>(false)));
    }

    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();  //TO BE REMOVED

    circlePosition.x = 0;
    circlePosition.y = 6*desktop.height/10;
    ingredientPosition.x = 0;
    ingredientPosition.x = 200*desktop.width/2500-170*desktop.width/2500+circlePosition.x;
    ingredientPosition.y = circlePosition.y+200*desktop.width/2500-(170*desktop.width-20)/2500;


    dough.setRadius(200*desktop.width/2500);
    sf::Color customColor(255, 228, 181);
    dough.setFillColor(customColor);

    sf::CircleShape pepperoni1;
    sf::CircleShape pepperoni2;
    sf::CircleShape pepperoni3;
    sf::CircleShape pepperoni4;
    pepperonis = {pepperoni1, pepperoni2,pepperoni3, pepperoni4};
    circlePosition.x = 0;

}

sf::Vector2f Pizza::getCirclePosition(){
    return circlePosition;
}

int Pizza::getId(){
    return id;
}

std::ostream& operator<<(std::ostream& os, const Pizza& pizza)
{
    os << "the Pizza contains the following ingredients";
    for(const auto &ingredient: pizza.ingredients){
        string key = ingredient.first.getLabel();
    }
    return os;
}

bool Pizza::operator==(const Pizza& other) const {
    return this->id == other.id;
}

sf::CircleShape Pizza::getDough(){
    return dough;
}


void Pizza::movePizza(float velocity) {
    //cout << "should move Pizza number " << id <<  " from position: " << circlePosition.x << endl;
    circlePosition.x += velocity;
    ingredientPosition.x += velocity;
}

void Pizza::printPizza(sf::RenderWindow& window){

    dough.setPosition(circlePosition.x,circlePosition.y);
    window.draw(dough);


    for (auto ingredient: ingredients){
        if (*ingredient.second){
            //cout << "HERE" << endl;
            Ingredient ingr = ingredient.first;
            ingr.printIngredient(window, ingredientPosition);
            //ingr.setPosition(ingredientPosition.x, ingredientPosition.y);
            //circles.push_back(ingr.getCircle());
        }
    }
}

// Define the less-than operator implementation
bool operator<(const Pizza& lhs, const Pizza& rhs) {
    // Compare the labels of the ingredients for ordering
    return lhs.id < rhs.id;
}


int Pizza::addIngredient(Ingredient ingredient) {
    int res = -2;
    for (auto& pair: ingredients){
        Ingredient ingr = pair.first;
        if (ingr == ingredient){
            if (pair.second && !(*pair.second)){
                *pair.second = true;
                res = 3;

            }
        }
    }
    return res;
}


bool Pizza::isComplete() {
    bool res = true;
    for(auto& pair : ingredients) {
        if(*pair.second == false) {
            res = false;
        }
    }

    return res;
}

void Pizza::resetPizza(){


    sauce.setFillColor(sf::Color::Transparent); // Set fill color to transparent
    sauce.setOutlineColor(sf::Color::Transparent); // Set outline color to transparent
    sauce.setOutlineThickness(0.f);


    for(sf::CircleShape &pepp: pepperonis) {
        pepp.setFillColor(sf::Color::Transparent); // Set fill color to transparent
        pepp.setOutlineColor(sf::Color::Transparent); // Set outline color to transparent
        pepp.setOutlineThickness(0.f);
    }

    for (auto& pair: ingredients){
        *pair.second = false;
    }

}