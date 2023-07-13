//
// Created by Sarah Zakon on 07/07/2023.
//
#pragma once
#include "Ingredient.h"
#include <vector>
#include <map>
#include "Pizza.h"
#include "Kitchen.h"
#include "Storage.h"
#include <memory>
#include <optional>
#include <random>
#include "PizzaPool.h"
#ifndef GLOUTON_PIZZAMANAGER_H
#define GLOUTON_PIZZAMANAGER_H


class PizzaManager {
private:
    std::vector<Pizza> pizzas;
    int lives;
    int score;
    static const float xVelocity;
    std::optional<PizzaPool> pool;
    std::vector<Ingredient> ingredients;
public:
    explicit PizzaManager();

    void setPool(PizzaPool pool);
    void setIngredients(std::vector<Ingredient> ingredients);
    std::vector<Pizza> getPizzas();
    int getScore();
    int getLives();
    void addRandomIngredient(Pizza pizza, Ingredient ingredient);
    void pizzaGenerator();
    void randomIngr(Pizza pizza);
    void movePizzas(sf::RenderWindow& window, sf::Sprite lifeline, std::map<std::string, sf::Texture> textures);
    void releasePizza(Pizza pizza);
    bool checkPizzaClick(std::optional<Kitchen> selected, sf::Vector2i mousePos);
    void printPizza(sf::RenderWindow& window);


    };


#endif //GLOUTON_PIZZAMANAGER_H
