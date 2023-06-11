//
// Created by Sarah Zakon on 06/06/2023.
//
#pragma once
#include "Ingredient.h"
#include <vector>
#include <map>
#include "Pizza.h"
#include "Kitchen.h"
#include "Storage.h"
#include <memory>
#include "Drawing.h"
#include "colors.h"
#include <SFML/Graphics.hpp>

#ifndef GLOUTON_FACADE_H
#define GLOUTON_FACADE_H

#endif //GLOUTON_FACADE_H

class Facade {
private:
    std::vector<Pizza> pizzas;
    std::vector<Storage> storages;
    std::vector<Preparation> preparations;
    std::map< std::string, Ingredient> ingredients;
    std::optional<Kitchen> selected;
    std::string selected_type;
    // Declare other member functions and variables

public:
    sf::RenderWindow window;
    Facade();  // Constructor
    void init();
    void draw_init();
    void startCooking(Preparation preparation);
};
