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

void Pizza::setDough(float screenWidth, sf::Vector2f circlePosition, float xVelocity, sf::Vector2f saucePosition, const sf::Texture& cooked_cheese, bool tomato, bool cheese, bool pepperoni){
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
    /*//texture
    sf::Texture cooked_cheese;
    if (!cooked_cheese.loadFromFile("resources/cooked-cheese.png")) {
        cout << "ERROR cooked-cheese IMAGE DIDN'T LOAD" << std::endl;
    }*/
    if(!cheese){
        melted_cheese.setFillColor(sf::Color::Transparent); // Set fill color to transparent
        melted_cheese.setOutlineColor(sf::Color::Transparent); // Set outline color to transparent
        melted_cheese.setOutlineThickness(0.f);
    }else{ //visible cheese

        melted_cheese.setFillColor(sf::Color::Yellow);// Set fill color to transparent
        melted_cheese.setOutlineColor(sf::Color::Yellow);
        melted_cheese.setTexture(&cooked_cheese);

        //melted_cheese.setFillColor(sf::Color::Green);
        //melted_cheese.setOutlineColor(sf::Color::Green);
    }

    //sets pepperoni;
    float i = 1.0*screenWidth/2500;
    float j = 1.0*screenWidth/2500;
    for(sf::CircleShape &pepp: pepperonis){
        pepp.setPosition(saucePosition.x + (i*170*screenWidth-20)/2500/2, saucePosition.y + (j*170*screenWidth-20)/2500/2);
        pepp.setRadius(30*screenWidth/2500);
        //position the pepperonis
        if(i==1*screenWidth/2500){
            i = (i-0.5)*screenWidth/2500;
            j= (j+2)*screenWidth/2500; //2,5 ; 2
            //pepp.setFillColor(sf::Color::Red);
            cout << "first if: " << i << " et " << j << endl;
        }else if(j==(2+1*screenWidth/2500)*screenWidth/2500){
            i = (i+3.2)*screenWidth/2500 ;
            j = (j+1.2)*screenWidth/2500; //2,3
            //pepp.setFillColor(sf::Color::Green);
            cout << "second if: " <<i << " et " << j << endl;
        }else{
            i = (i+0.4)*screenWidth/2500;
            j = (j- 1.7)*screenWidth/2500;  //3.5, 2.5
            //pepp.setFillColor(sf::Color::Blue);
            cout <<"third if: " << i << " et " << j << endl;
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

void Pizza::addIngredient(Ingredient ingredient) {
    cout << 3 << endl;
    for (auto& pair: ingredients){
        cout << 4 << endl;
        Ingredient ingr = pair.first;
        if (ingr == ingredient){
            cout << 5 << endl;
            if (!pair.second){
                cout << 6 << endl;
                if (ingr.getlabel() == "tomatoe"){
                    cout << 7 << endl;
                    pair.second = true;
                }
                else if(ingr.getlabel() == "cheese"){
                    cout << 7.5 << endl;
                    pair.second = true;
                }

                else if(ingr.getlabel() == "pepperoni"){
                    cout << 7.5 << endl;
                    pair.second = true;
                }
            }
        }
    }
}

