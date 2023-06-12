#include "Pizza.h"
#include <string>
#include <utility>
#include <vector>
#include <map>
#include <unordered_map>
#include <iostream>
#include "Ingredient.h"
#include "Preparation.h"

using namespace std;

int Pizza::id_count = 0;

Pizza::Pizza(const std::vector<Ingredient>& ingr)
{
    completed = false;
    id = id_count++;
    for (const auto &ingredient: ingr) {
        ingredients.insert(std::make_pair(ingredient, false));
    }
}

std::ostream& operator<<(std::ostream& os, const Pizza& pizza)
{
    os << "the Pizza contains the following ingredients";
    for(const auto &ingredient: pizza.ingredients){
        string key = ingredient.first.getlabel();
        bool value = ingredient.second;
        os << key << " and it's print status is : " << value << endl;
    }
    return os;
}


std::map<Ingredient, bool> Pizza::getIngredients() {
    return ingredients;
}
/*
std::vector<Preparation> Pizza::getPreparations() {
    return preparations;
}*/
/*
int Pizza::addIngredient() {
    for(Preparation& prep : preparations) {
        if(prep.getSelected() && prep.getready() && !ingredients[prep.getIngredient()]) {
            ingredients[prep.getIngredient()] = true;
            prep.reset();
        }
    }
    return 0;
}
*/

void Pizza::setDough(float screenWidth, sf::Vector2f circlePosition, float xVelocity, sf::Vector2f saucePosition, bool tomato){
    dough.setPosition(circlePosition);
    dough.setRadius(200*screenWidth/2500);
    sf::Color customColor(255, 228, 181);
    dough.setFillColor(customColor);

    //set invisible sauce
    sauce.setPosition(saucePosition);
    sauce.setRadius(170*screenWidth/2500);
    if(!tomato){
        sauce.setFillColor(sf::Color::Transparent); // Set fill color to transparent
        sauce.setOutlineColor(sf::Color::Transparent); // Set outline color to transparent
        sauce.setOutlineThickness(0.f);
    }else{
        sauce.setFillColor(sf::Color::Red); // Set fill color to transparent
        sauce.setOutlineColor(sf::Color::Red); // Set outline color to transparent
    }
}

sf::CircleShape Pizza::getDough(){
    return dough;
}


sf::CircleShape Pizza::getSauce(){
    return sauce;
}

void Pizza::addTomato(){
    cout << 8 << endl;
    sauce.setFillColor(sf::Color::Red);
}

void Pizza::addIngredient(Ingredient ingredient) {
    cout << 3 << endl;
    for (const auto& pair: ingredients){
        cout << 4 << endl;
        Ingredient ingr = pair.first;
        if (ingr == ingredient){
            cout << 5 << endl;
            if (!pair.second){
                cout << 6 << endl;
                if (ingr.getlabel() == "tomatoe"){
                    cout << 7 << endl;
                    addTomato();
                }
            }
        }
    }
}

