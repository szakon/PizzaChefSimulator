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

#ifndef GLOUTON_FACADE_H
#define GLOUTON_FACADE_H

#endif //GLOUTON_FACADE_H

class Facade {
private:
    std::vector<Pizza> pizzas;
    std::vector<Storage> storages;
    std::vector<Preparation> preparations;
    std::map< std::string, Ingredient> ingredients;
    // Declare other member functions and variables

public:
    Facade();  // Constructor
    void init();
};
