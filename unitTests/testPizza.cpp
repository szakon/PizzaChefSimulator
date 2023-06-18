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

    Ingredient ingr2("tomaoe");

}