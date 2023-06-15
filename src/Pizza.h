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
    std::map< Ingredient, shared_ptr<bool>> ingredients;
    bool completed;
    sf::CircleShape dough;
    sf::CircleShape sauce;
    sf::CircleShape melted_cheese;
    vector<sf::CircleShape> pepperonis;
    sf::Vector2f position;
public:
    explicit Pizza(const std::vector< Ingredient>& ingr);
    std::map< Ingredient , shared_ptr<bool>> getIngredients();
    std::vector<Preparation> getPreparations();
    friend std::ostream& operator<<(std::ostream& os, const Pizza& pizza);
    int addIngredient(Ingredient ingredient);
    void setPosition(sf::Vector2f circleposition);
    sf::Vector2f getPosition();
    //void setDough(float screenWidth,float xVelocity, const sf::Texture& cooked_cheese, bool tomato, bool cheese, bool pepperoni);
    void setDough(float screenWidth, sf::Vector2f circlePosition, float xVelocity, const sf::Texture& cooked_cheese, bool tomato, bool cheese, bool pepperoni);
    sf::CircleShape getDough();
    sf::CircleShape getSauce();
    sf::CircleShape getCheese();
    vector<sf::CircleShape> getPepperoni();
    void addTomato();
    void randomIngr();

    static int id_count;
};

