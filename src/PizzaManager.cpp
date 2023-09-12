//
// Created by Sarah Zakon on 07/07/2023.
//

#include "PizzaManager.h"

const float PizzaManager::xVelocity = 1;

PizzaManager::PizzaManager() {
    score = 0;
    lives = 3;
}

std::vector<Pizza*> PizzaManager::getPizzas(){
    return pizzas;
}
int PizzaManager::getScore(){
    return score;
}

int PizzaManager::getLives(){
    return lives;
}
/*
void PizzaManager::setPool(PizzaPool pool){
    this->pool = pool;
}*/


void PizzaManager::setIngredients(std::vector<Ingredient> ingredients){
    this->ingredients = ingredients;
}



void PizzaManager::movePizzas(sf::RenderWindow& window, sf::Sprite lifeline, std::map<std::string, sf::Texture> textures, sf::Sprite postit){
    bool pizzaNeedGeneration=false;
    for (Pizza *pizza: pizzas) {
        if (pizza->getCirclePosition().x >window.getSize().x * 0.65) { //we are at the end of the line
            if (!pizza->isComplete()) { // If the pizza is not completed with all ingredients
                score -= 10;
                lives -= 1;
            } else {
                score += 10;
            }
            releasePizza(pizza, window, postit);
            break;


        } else if (pizza->getCirclePosition().x > window.getSize().x * 0.2) { //we need to display a new pizza
            if (pizza->getCriticalStatePassed() == 0 && !pizzaNeedGeneration) {pizza->setCriticalStatePassed();
                pizzaNeedGeneration=true;
                pizza->movePizza(xVelocity);
            }
            pizza->movePizza(xVelocity);

        } else {
            pizza->movePizza(xVelocity);
        }
    }
    if (pizzaNeedGeneration)
        pizzaGenerator(window, postit);
}

void PizzaManager::randomIngr(Pizza* pizza){ //PM
    std::random_device rd;
    std::mt19937 mt(rd());
    std::vector<int> values = {0, 1};
    std::uniform_int_distribution<int> distribution(0, 1);
    int randomIndex = distribution(mt);
    int numIngredients = values[randomIndex];
    if (numIngredients == 1){
        std::random_device rd1;
        std::mt19937 mt1(rd1());

        std::uniform_int_distribution<int> distribution(0, ingredients.size() - 1);
        int randomIndex1 = distribution(mt1);
        Ingredient ingredient = ingredients[randomIndex1];

        addRandomIngredient(pizza, ingredient);
    }

}

bool PizzaManager::checkPizzaClick(std::optional<Kitchen> selected, sf::Vector2i mousePos) {
    for (auto &pizza: pizzas) {
        if (pizza->getDough().getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            score += pizza->addIngredient(selected->getIngredient());
            return true;
        }
    }
    return false;
}

void PizzaManager::addRandomIngredient(Pizza* pizza, Ingredient ingredient) {  //PM
    pizza->addIngredient(ingredient);

}

std::vector<Ingredient> PizzaManager::randomIngrVect(){

    std::random_device rd;
    std::mt19937 mt(rd());
    std::vector<int> values = {3,4,5};
    std::uniform_int_distribution<int> distribution(0, 1);
    int randomIndex = distribution(mt);
    int numIngredients = values[randomIndex];
    std::vector<Ingredient> vect = createVect(numIngredients);
    return vect;
}

std::vector<Ingredient> PizzaManager::createVect(int numIngredients){
    std::random_device rd1;
    std::mt19937 mt1(rd1());
    std::vector<Ingredient> ingrs;
    std::vector<Ingredient> createdVector;
    for (auto& ingredient: ingredients){
        ingrs.push_back(ingredient);
    }
    for (int i = 0; i<numIngredients; i++){
        std::uniform_int_distribution<int> distribution(0, ingrs.size() - 1);
        int randomIndex1 = distribution(mt1);
        Ingredient ingredient = ingredients[randomIndex1];
        createdVector.push_back(ingredient);
        std::remove(ingrs.begin(), ingrs.end(),ingredient);
    }
    return createdVector;

}





void PizzaManager::pizzaGenerator(sf::RenderWindow& window, sf::Sprite postit){ //PM
    std::vector<Ingredient> ingrs = randomIngrVect();
    Pizza* pizza = new Pizza(ingrs);
    randomIngr(pizza);

    pizzas.push_back(pizza);
    printRecipe(window, postit);
}


void PizzaManager::releasePizza(Pizza* pizza, sf::RenderWindow& window, sf::Sprite postit){
    int pizzasIndex = 0;
    for (auto piz: pizzas){ //tbd
        if(pizza == piz){

            //pizzas.erase(pizzas.begin());
            pizzas.erase(std::remove(pizzas.begin(), pizzas.end(), pizza), pizzas.end());
            break;
        }
        pizzasIndex++;
    }
    printRecipe(window, postit);
    delete pizza;
}

void PizzaManager::printRecipe(sf::RenderWindow& window, sf::Sprite postit){
    for (int i = 0; i<pizzas.size(); i++){
        pizzas[i]->setPizzaNum(i+1);
        for (auto ingredient : pizzas[i]->getIngredients()){
            ingredient.printRecipe(window, i, postit);
        }
    }
}


void PizzaManager::printPizza(sf::RenderWindow& window, sf::Sprite postit){
    for (auto& pizza: pizzas) {
        pizza->printPizza(window, postit);
    }

}
