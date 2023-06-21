//
// Created by Sarah Zakon on 18/06/2023.
//

#include "PizzaPool.h"
#include <gtest/gtest.h>


TEST(PizzaPoolTest, Constructor) {
std::vector<Ingredient> ingr_vector;
Ingredient ingr("Onion");
ingr_vector.push_back(ingr);

PizzaPool pool(ingr_vector);

EXPECT_EQ(pool.getPizzas().size(), 7);
EXPECT_EQ(pool.getAvailableIndices().size(), 7);
}

TEST(PizzaPoolTest, acquirePizza) {
    std::vector<Ingredient> ingr_vector;
    Ingredient ingr("Onion");
    ingr_vector.push_back(ingr);

    PizzaPool pool(ingr_vector);
    pool.acquirePizza();

    EXPECT_EQ(pool.getPizzas().size(), 7);
    EXPECT_EQ(pool.getAvailableIndices().size(), 6);
}


TEST(PizzaPoolTest, releasePizza) {
    std::vector<Ingredient> ingr_vector;
    Ingredient ingr("Onion");
    ingr_vector.push_back(ingr);
    PizzaPool pool(ingr_vector);
    Pizza pizza(ingr_vector);

    pool.acquirePizza();
    pool.releasePizza(pizza);

    EXPECT_EQ(pool.getPizzas().size(), 7);
    EXPECT_EQ(pool.getAvailableIndices().size(), 7);
}