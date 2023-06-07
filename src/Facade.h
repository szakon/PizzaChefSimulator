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
    std::map< int , std::shared_ptr<Pizza>> pizzas;
    std::map< int , std::shared_ptr<Storage>> storages;
    std::map< int , std::shared_ptr<Preparation>> preparations;
    std::map<int, std::shared_ptr<Ingredient>> ingredients;
    // Declare other member functions and variables

public:
    Facade();  // Constructor
    void init();
};
