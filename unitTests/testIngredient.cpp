#include <gtest/gtest.h>
#include "Ingredient.h"


TEST(IngredientTest, Constructor) {
    Ingredient ingr("Onion"); // Example ingredient for testing

    // Verify that the ingredient is set correctly
    EXPECT_EQ(ingr.getlabel(), "Onion");
}

