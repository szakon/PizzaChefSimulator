#include <gtest/gtest.h>
#include "Pizza.h"

TEST(PizzaTest, Constructor) {
    std::vector<Ingredient> ingr_vector;
    Ingredient ingr("Onion");
    ingr_vector.push_back(ingr);

    Pizza pizza(ingr_vector);

    EXPECT_FALSE(pizza.getComplete());
    EXPECT_EQ(pizza.getId(), 0);
    EXPECT_EQ(pizza.getIngredientStatus("Onion"), false);
    EXPECT_EQ(pizza.getCirclePosition().x, 0);
    EXPECT_EQ(pizza.getPepperoni().size(), 4);

    Pizza pizza2(ingr_vector);
    EXPECT_EQ(pizza2.getId(), 1);

}

TEST(PizzaTest, AddIngredient) {
    std::vector<Ingredient> ingr_vector;
    Ingredient ingr("Onion");
    ingr_vector.push_back(ingr);

    Pizza pizza(ingr_vector);
    EXPECT_EQ(pizza.getIngredientStatus("Onion"),false);

    int res = pizza.addIngredient(ingr);

    EXPECT_EQ(res, 3);
    EXPECT_EQ(pizza.getIngredientStatus("Onion"),true);

    res = pizza.addIngredient(ingr);

    EXPECT_EQ(res, -2);
}

TEST(PizzaTest, GetComplete) {
    std::vector<Ingredient> ingr_vector;
    Ingredient ingr("Onion");
    ingr_vector.push_back(ingr);

    Pizza pizza(ingr_vector);

    int res = pizza.addIngredient(ingr);

    EXPECT_TRUE(res);
}

TEST(PizzaTest, GetIngredientStatus) {
    std::vector<Ingredient> ingr_vector;
    Ingredient ingr("Onion");
    ingr_vector.push_back(ingr);

    Pizza pizza(ingr_vector);

    EXPECT_FALSE(pizza.getIngredientStatus("Onion"));

    pizza.addIngredient(ingr);

    EXPECT_TRUE(pizza.getIngredientStatus("Onion"));
}

TEST(PizzaTest, Reset) {
    std::vector<Ingredient> ingr_vector;
    Ingredient ingr("Onion");
    ingr_vector.push_back(ingr);

    Pizza pizza(ingr_vector);
    pizza.addIngredient(ingr);
    pizza.resetPizza();

    EXPECT_FALSE(pizza.getIngredientStatus("Onion"));
    EXPECT_FALSE(pizza.getComplete());
}