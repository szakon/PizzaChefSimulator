#pragma once
#include "Ingredient.h"
#include <vector>
#include <map>
#include "Ingredient.h"
#include "Preparation.h"

using namespace std;

class Pizza {
private :
    int nextId;
    std::map< Ingredient, shared_ptr<bool>> ingredients;
    bool completed;
    sf::CircleShape dough;
    sf::CircleShape sauce;
    sf::CircleShape melted_cheese;
    vector<sf::CircleShape> pepperonis;
    sf::Vector2f position;
    sf::Vector2f circlePosition;

public:
    int id;

    explicit Pizza(const std::vector< Ingredient>& ingr);
    friend std::ostream& operator<<(std::ostream& os, const Pizza& pizza);
    int addIngredient(Ingredient ingredient);
    void setPosition(sf::Vector2f circleposition);
    sf::Vector2f getPosition();
    void setDough(unsigned int screenWidth, unsigned int screenHeight, float circlePosition, float xVelocity, const sf::Texture& cooked_cheese, bool tomato, bool cheese, bool pepperoni);
    sf::CircleShape getDough() const;
    sf::CircleShape getSauce() ;
    sf::CircleShape getCheese() ;
    vector<sf::CircleShape> getPepperoni();
    void resetPizza();
    bool operator==(const Pizza& other) const;
    int getId();
    sf::Vector2f getCirclePosition();
    bool getComplete();

    bool getIngredientStatus(std::string string) const;
};

