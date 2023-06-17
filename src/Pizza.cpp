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

//int Pizza::nextId = 0;
int nextId = 0;

Pizza::Pizza(const std::vector<Ingredient>& ingr)
{
    id = nextId++;
    completed = false;
    for (const auto &ingredient: ingr) {
        ingredients.insert(std::make_pair(ingredient, std::make_shared<bool>(false)));
    }

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
        string key = ingredient.first.getlabel();
    }
    return os;
}

bool Pizza::operator==(const Pizza& other) const {
    return this->id == other.id;
}

void Pizza::setDough(unsigned int screenWidth, unsigned int screenHeight, float circlePositionX, float xVelocity, const sf::Texture& cooked_cheese, bool tomato, bool cheese, bool pepperoni){
    circlePosition.x=circlePositionX;
    circlePosition.y = 6*screenHeight/10;
    sf::Vector2f saucePosition(200*screenWidth/2500-170*screenWidth/2500+circlePosition.x,circlePosition.y+200*screenWidth/2500-170*screenWidth/2500);
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
    }else{ //visible sauce
        sauce.setFillColor(sf::Color::Red); // Set fill color to transparent
        sauce.setOutlineColor(sf::Color::Red); // Set outline color to transparent
    }

    //set invisible cheese
    melted_cheese.setPosition(saucePosition.x+20/2500, saucePosition.y);
    melted_cheese.setRadius((170*screenWidth-20)/2500);

    if(!cheese){
        melted_cheese.setFillColor(sf::Color::Transparent); // Set fill color to transparent
        melted_cheese.setOutlineColor(sf::Color::Transparent); // Set outline color to transparent
        melted_cheese.setOutlineThickness(0.f);
    }else{ //visible cheese

        melted_cheese.setFillColor(sf::Color::Yellow);// Set fill color to transparent
        melted_cheese.setOutlineColor(sf::Color::Yellow);
        melted_cheese.setTexture(&cooked_cheese);
    }

    //sets pepperoni;
    float i = 1.0*screenWidth/2500*2/3;
    float j = 1.0*screenWidth/2500*2/3;
    int loop=0;
    for(sf::CircleShape &pepp: pepperonis){
        pepp.setPosition(saucePosition.x + (i*170*screenWidth-20)/2500/2, saucePosition.y + (j*170*screenWidth-20)/2500/2);
        pepp.setRadius(30*screenWidth/2500);
        //position the pepperonis
        if(loop == 0){
            i = (i-0.5)*screenWidth/2500*2/3;
            j= (j+2)*screenWidth/2500*2/3; //2,5 ; 2
        }else if(loop == 1){
            i = (i+3.2)*screenWidth/2500*2/3 ;
            j = (j+1.2)*screenWidth/2500*2/3; //2,3

        }else{
            i = (i+0.4)*screenWidth/2500*2/3;
            j = (j- 1.7)*screenWidth/2500*2/3;  //3.5, 2.5
        }
        loop++;

        //make visible/invisible the pepperonis

        if(!pepperoni){
            pepp.setFillColor(sf::Color::Transparent); // Set fill color to transparent
            pepp.setOutlineColor(sf::Color::Transparent); // Set outline color to transparent
            melted_cheese.setOutlineThickness(0.f);
        }else{ //visible cheese
            sf::Color customColor(170, 68, 0);
            pepp.setFillColor(customColor);
        }

    }

}

sf::CircleShape Pizza::getDough() const{
    return dough;
}


sf::CircleShape Pizza::getSauce(){
    return sauce;
}

sf::CircleShape Pizza::getCheese(){
    return melted_cheese;
}

vector<sf::CircleShape> Pizza::getPepperoni(){
    return pepperonis;
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
                if (ingr.getlabel() == "tomatoe"){
                    *pair.second = true;
                }
                else if(ingr.getlabel() == "cheese"){
                    *pair.second = true;
                }

                else if(ingr.getlabel() == "pepperoni"){
                    *pair.second = true;
                }

                res = 3;

            }
        }
    }

    return res;
}

void Pizza::setPosition(sf::Vector2f circleposition) {
    position = circleposition;
}

sf::Vector2f Pizza::getPosition() {
    return position;
}

bool Pizza::getIngredientStatus(std::string string) const{
    for (auto& pair: ingredients) {
        if (pair.first.getlabel() == string){
            bool rtrn = *pair.second;
            return rtrn;
        }
    }
}

bool Pizza::getComplete() {
    bool res = true;
    for(auto& pair : ingredients) {
        if(*pair.second == false) {
            res = false;
        }
    }

    return res;
}

void Pizza::resetPizza(){
    dough.setFillColor(sf::Color::Transparent); // Set fill color to transparent
    dough.setOutlineColor(sf::Color::Transparent); // Set outline color to transparent
    dough.setOutlineThickness(0.f);


    sauce.setFillColor(sf::Color::Transparent); // Set fill color to transparent
    sauce.setOutlineColor(sf::Color::Transparent); // Set outline color to transparent
    sauce.setOutlineThickness(0.f);

    melted_cheese.setFillColor(sf::Color::Transparent); // Set fill color to transparent
    melted_cheese.setOutlineColor(sf::Color::Transparent); // Set outline color to transparent
    melted_cheese.setOutlineThickness(0.f);

    for(sf::CircleShape &pepp: pepperonis) {
        pepp.setFillColor(sf::Color::Transparent); // Set fill color to transparent
        pepp.setOutlineColor(sf::Color::Transparent); // Set outline color to transparent
        pepp.setOutlineThickness(0.f);
    }

    for (auto& pair: ingredients){
        *pair.second = false;
    }

}