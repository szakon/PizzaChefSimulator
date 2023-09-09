#pragma once
#include "Ingredient.h"
#include <vector>
#include <map>
#include "Ingredient.h"
#include "Preparation.h"

using namespace std;

class Pizza {
private :
    std::map< Ingredient, bool> ingredients;
    bool completed;
    sf::CircleShape dough;
    sf::Vector2f circlePosition;
    sf::Vector2f ingredientPosition;
    bool criticalStatePassed;
    int pizzaNum;

public:
    int id;

    explicit Pizza(std::vector< Ingredient>& ingr);
    virtual ~Pizza();
    sf::CircleShape getDough();
    std::vector<Ingredient> getIngredients();
    std::vector<sf::CircleShape> getCircles();
    void movePizza(float velocity);
    std::vector<sf::CircleShape>  addIngredientSprite(float positionX);
    friend std::ostream& operator<<(std::ostream& os, const Pizza& pizza);
    int addIngredient(Ingredient ingredient);
    int getPizzaNum();
    void setPizzaNum(int i);
    void setPosition(sf::Vector2f position);
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
    bool isComplete();
    std::vector<sf::CircleShape> getIngredientsSprite();
    bool getIngredientStatus(std::string string) const;
    void printPizza(sf::RenderWindow& window, sf::Sprite postit);
    bool getCriticalStatePassed();
    //void setNewPizzaGenerated(bool& generated);
    void setCriticalStatePassed();
};

