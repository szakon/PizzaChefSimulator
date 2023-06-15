#pragma once
#include "Ingredient.h"
#include <vector>
#include <map>
#include "Pizza.h"
#include "Kitchen.h"
#include "Storage.h"
#include <memory>
#include <optional>
#include "Drawing.h"
#include "colors.h"
#include <SFML/Graphics.hpp>

#ifndef VALUES_H
#define VALUES_H

struct Ingr {
    Ingredient ingredient;
    bool added;
};

#endif // VALUES_H

class Facade {
private:
    sf::Sprite sprite_background;
    std::vector<Pizza> pizzas;
    std::vector<Storage> storages;
    std::vector<Preparation> preparations;
    std::map<std::string, Ingr> ingredients;
    std::optional<Kitchen> selected;
    std::string selected_type;
    // Declare other member functions and variables

public:
    sf::RenderWindow window;
    Facade();
    void run();  // Constructor
    void init();
    void render();
    void update(sf::Time time, unsigned int screenWidth, unsigned int screenHeight);
    void cout_test();
    void draw_init(unsigned int screenWidth, unsigned int screenHeight);
    void processEvents();
    void startCooking(Preparation preparation);
    void addIngredient(Pizza pizza);

    static const sf::Time TimePerFrame;
    static const float xVelocity;
};
