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
    explicit Kitchen(Ingredient ingr,sf::Texture texture);
    Ingredient getIngredient();

    bool getselected() const;
    void selection();
    void unselection();
    friend std::ostream& operator<<(std::ostream& os, const Kitchen& kitchen);
};



