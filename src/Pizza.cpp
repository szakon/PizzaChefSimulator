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
    pizzaNum = 1;
    id = nextId++;
    completed = false;
    criticalStatePassed = false;
    for (auto &ingredient: ingr) {
        ingredients.insert(std::make_pair(ingredient, false));
    }

    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();  //TO BE REMOVED

    circlePosition.x = 0;
    circlePosition.y = 6*desktop.height/10;
    ingredientPosition.x = 0;
    ingredientPosition.x = 200*desktop.width/2500-170*desktop.width/2500+circlePosition.x;
    ingredientPosition.y = circlePosition.y+200*desktop.width/2500-(170*desktop.width-20)/2500;


    dough.setRadius(200*desktop.width/2500);
    dough.setPosition(0, circlePosition.y);
    sf::Color customColor(255, 228, 181);
    dough.setFillColor(customColor);

}

Pizza::~Pizza(){

}

sf::Vector2f Pizza::getCirclePosition(){
    return circlePosition;
}

int Pizza::getId(){
    return id;
}

std::vector<Ingredient> Pizza::getIngredients(){
    std::vector<Ingredient> ingrs;
    for (auto ingredient: ingredients){
        ingrs.push_back(ingredient.first);
    }
    return ingrs;
}

bool Pizza::getCriticalStatePassed(){
    return criticalStatePassed;
}
int Pizza::getPizzaNum(){
    return pizzaNum;
}

void Pizza::setPizzaNum(int i){
    pizzaNum = i;
}

void Pizza::setCriticalStatePassed(){
    criticalStatePassed = true;
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
    circlePosition.x += velocity;
    ingredientPosition.x += velocity;

}

void Pizza::printPizza(sf::RenderWindow& window, sf::Sprite postit){
    dough.setPosition(circlePosition.x,circlePosition.y);
    window.draw(dough);


    for (auto ingredient: ingredients){
        Ingredient ingr = ingredient.first;
        ingr.printRecipe(window, pizzaNum, postit);
        if (ingredient.second){
            ingr.printIngredient(window, ingredientPosition);
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
        if (ingr.getLabel() == ingredient.getLabel()){
            if (!(pair.second)){
                pair.second = true;
                res = 3;

            }
        }
    }
    return res;
}


bool Pizza::isComplete() {
    bool res = true;
    for(auto& pair : ingredients) {
        if(pair.second == false) {
            res = false;
        }
    }

    return res;
}

void Pizza::resetPizza(){
    for (auto& pair: ingredients){
        pair.second = false;
    }

}

