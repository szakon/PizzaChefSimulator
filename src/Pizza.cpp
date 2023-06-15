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

int Pizza::id_count = 0;

Pizza::Pizza(const std::vector<Ingredient>& ingr)
{

    completed = false;
    for (const auto &ingredient: ingr) {
        ingredients.insert(std::make_pair(ingredient, std::make_shared<bool>(false)));
    }

    sf::CircleShape pepperoni1;
    sf::CircleShape pepperoni2;
    sf::CircleShape pepperoni3;
    sf::CircleShape pepperoni4;
    pepperonis = {pepperoni1, pepperoni2,pepperoni3, pepperoni4};
}

std::ostream& operator<<(std::ostream& os, const Pizza& pizza)
{
    os << "the Pizza contains the following ingredients";
    for(const auto &ingredient: pizza.ingredients){
        string key = ingredient.first.getlabel();
    }
    return os;
}


void Pizza::setDough(float screenWidth, sf::Vector2f circlePosition, float xVelocity, const sf::Texture& cooked_cheese, bool tomato, bool cheese, bool pepperoni){
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
        for(auto& ingredient: ingredients){
            cout<< "true or false of ingredient: " << ingredient.first.getlabel() << "status " << ingredient.second << endl;
        }
        melted_cheese.setFillColor(sf::Color::Yellow);// Set fill color to transparent
        melted_cheese.setOutlineColor(sf::Color::Yellow);
        melted_cheese.setTexture(&cooked_cheese);


    }

    //sets pepperoni;
    float i = 1.0*screenWidth/2500*2/3;
    float j = 1.0*screenWidth/2500*2/3;
    for(sf::CircleShape &pepp: pepperonis){
        pepp.setPosition(saucePosition.x + (i*170*screenWidth-20)/2500/2, saucePosition.y + (j*170*screenWidth-20)/2500/2);
        pepp.setRadius(30*screenWidth/2500);
        //position the pepperonis
        if(i==1*screenWidth/2500*2/3){
            cout << "first if" << endl;
            i = (i-0.5)*screenWidth/2500*2/3;
            j= (j+2)*screenWidth/2500*2/3; //2,5 ; 2
            //pepp.setFillColor(sf::Color::Red);
        }else if(j==(2+1*screenWidth/2500*2/3)*screenWidth/2500*2/3){
            i = (i+3.2)*screenWidth/2500*2/3 ;
            j = (j+1.2)*screenWidth/2500*2/3; //2,3
            cout << "second if" << endl;
            //pepp.setFillColor(sf::Color::Green);

        }else{
            i = (i+0.4)*screenWidth/2500*2/3;
            j = (j- 1.7)*screenWidth/2500*2/3;  //3.5, 2.5
            cout << "third if" << endl;
            //pepp.setFillColor(sf::Color::Blue);
        }

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

sf::CircleShape Pizza::getDough(){
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

void Pizza::addTomato(){
    cout << 8 << endl;
    sauce.setFillColor(sf::Color::Red);
}

int Pizza::addIngredient(Ingredient ingredient) {
    int res = -2;
    for (auto& pair: ingredients){
        Ingredient ingr = pair.first;
        cout << "the ingredient we have: " << ingr.getlabel() << " the ingredient we want: " << ingredient << endl;
        if (ingr == ingredient){
            cout << "INN" << endl;
            cout << 5 << endl;
            if (pair.second && !(*pair.second)){
                cout << 6 << endl;
                if (ingr.getlabel() == "tomatoe"){
                    cout << 7 << endl;
                    *pair.second = true;
                }
                else if(ingr.getlabel() == "cheese"){
                    cout << 7.5 << endl;
                    *pair.second = true;
                }

                else if(ingr.getlabel() == "pepperoni"){
                    cout << 8.5 << endl;
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


void Pizza::randomIngr(){
    std::random_device rd;
    std::mt19937 mt(rd());  // Mersenne Twister engine
    // Define the vector of values
    std::vector<int> values = {0, 1};
    std::uniform_real_distribution<double> distribution(0.0, 1.0);
    int randomIndex = distribution(mt);
    int numIngredients = values[randomIndex];

    if (numIngredients == 1){
        std::vector<Ingredient> ingrs;
        for (auto& ingredient: ingredients){
            ingrs.push_back(ingredient.first);
        }
        int randomIndex2 = distribution(mt);
        Ingredient ingredient = ingrs[randomIndex2];
    }



}

