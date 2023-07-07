#include "PizzaPool.h"

using namespace std;


PizzaPool::PizzaPool(std::vector<Ingredient>& ingr){

    pizzas.reserve(7);
    for (int i = 0; i < 7; i++) {
        Pizza pizza(ingr);
        pizzas.push_back(pizza);  //add pizza to vector
        //pizzas.emplace_back();  // Create new Pizza objects and add them to the vector
        availableIndices.push(i);  // Add the corresponding index to the available indices queue
    }
}

const vector<Pizza> PizzaPool::getPizzas() const {
    return pizzas;
}

const queue<int> PizzaPool::getAvailableIndices() const {
    return availableIndices;
}




Pizza PizzaPool::acquirePizza() {
    if (availableIndices.empty()) {
        throw std::runtime_error("No available Pizza objects in the pool");
    }
    int index = availableIndices.front();
    availableIndices.pop();

    //Pizza returnPizza = pizzas[index]
    return pizzas[index];

}


void PizzaPool::releasePizza(Pizza& pizza) {

    int index;
    int i = 0;
    for(Pizza &piz: pizzas){
        if(piz == pizza ){
            index =  i;
            break;
        }
        i++;
    }  // Calculate the index of the Pizza object
    availableIndices.push(index); //releases the pizza by adding it to the lsit of available indexes

}