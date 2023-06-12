#pragma once
#include "Ingredient.h"
#include <vector>
#include <map>
#include "Ingredient.h"
#include "Preparation.h"

using namespace std;

class Pizza {
private :
    int id;
    std::map< Ingredient, bool> ingredients;
    bool completed;
    sf::CircleShape dough;
    sf::CircleShape sauce;
public:
    explicit Pizza(const std::vector< Ingredient>& ingr);
    std::map< Ingredient , bool> getIngredients();
    std::vector<Preparation> getPreparations();
    friend std::ostream& operator<<(std::ostream& os, const Pizza& pizza);
    void addIngredient(Ingredient ingredient);
    void setDough(float screenWidth, sf::Vector2f circlePosition, float xVelocity, sf::Vector2f saucePosition, bool tomato);
    sf::CircleShape getDough();
    sf::CircleShape getSauce();
    void addTomato();

    static int id_count;
};

