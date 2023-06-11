#pragma once
#include <string>
#include "Ingredient.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;


class Kitchen {
protected:
    bool selected;
    Ingredient ingredient;
    sf::Sprite sprite;
public:
    explicit Kitchen(Ingredient ingr);
    Ingredient getIngredient();
    virtual void setSprite(sf::Texture& texture, float scaleFactor, float position,int screenWidth, sf::Sprite jar, float scaleJar, float y_position);
    virtual sf::Sprite getSprite() const;
    bool getSelected() const;
    virtual void draw(sf::RenderWindow& window);
    void selection();
    void unselection();
    friend std::ostream& operator<<(std::ostream& os, const Kitchen& kitchen);

    virtual ~Kitchen() {} // Virtual destructor
};





