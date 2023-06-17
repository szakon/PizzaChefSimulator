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
    virtual void setSprite(sf::Texture& texture, float scaleFactor, float position,int screenWidth, sf::Sprite jar, float scaleJar, float y_position, sf::Texture& timer);
    virtual sf::Sprite getSprite() const;
    bool getSelected() const;
    void setSelected(bool select);
    virtual void draw(sf::RenderWindow& window);
    void selection();
    void unselection();
    friend std::ostream& operator<<(std::ostream& os, const Kitchen& kitchen);

    virtual ~Kitchen() {} // Virtual destructor
};





