//
// Created by Sarah Zakon on 14/06/2023.
//

#include "PizzaPool.h"

using namespace std;


PizzaPool::PizzaPool(const std::vector<Ingredient>& ingr){

    pizzas.reserve(7);
    /*for (int i = 0; i < 7 - 1; i++)
    {
        particles_[i].setNext(&particles_[i + 1]);
    }*/
    for (int i = 0; i < 7; ++i) {
        Pizza pizza(ingr);
        cout << "NEW PIZZA ID : " << pizza.getId() <<endl;
        pizzas.push_back(pizza);  //add pizza to vector
        //pizzas.emplace_back();  // Create new Pizza objects and add them to the vector
        availableIndices.push(i);  // Add the corresponding index to the available indices queue
    }
}
/*
Pizza PizzaPool::acquirePizza() {
    if (availableIndices.empty()) {
        throw std::runtime_error("No available Pizza objects in the pool");
    }
    int index = availableIndices.front();
    availableIndices.pop();
    return pizzas[index];
}*/

Pizza PizzaPool::acquirePizza() {
    cout << "HOW MANY AVAILABLE INDICES at beg acquire: " << availableIndices.size() << endl;
    if (availableIndices.empty()) {
        throw std::runtime_error("No available Pizza objects in the pool");
    }
    int index = availableIndices.front();
    availableIndices.pop();
    cout << "RETURNED TYPE" << typeid(pizzas[index]).name() << endl;
    cout << "HOW MANY AVAILABLE INDICES at end acquire: " << availableIndices.size() << endl;
    return pizzas[index];

}


void PizzaPool::releasePizza(Pizza& pizza) {

    cout << "HOW MANY AVAILABLE INDICES at begining release: " << availableIndices.size() << endl;
    int index = &pizza - &pizzas[0];  // Calculate the index of the Pizza object
    availableIndices.push(index); //releases the pizza by adding it to the lsit of available indexes
    cout << "HOW MANY AVAILABLE INDICES at end release: " << availableIndices.size() << endl;
}