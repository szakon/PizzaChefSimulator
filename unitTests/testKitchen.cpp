#include <gtest/gtest.h>
#include "Ingredient.h"
#include "Kitchen.h"


TEST(KitchenTest, Constructor) {
    Ingredient ingr("Onion"); // Example ingredient for testing

    Kitchen kitchen(ingr, 1);

    // Verify that the ingredient is set correctly
    EXPECT_EQ(ingr, kitchen.getIngredient());
    // Verify that the selected status is initialized as false
    EXPECT_FALSE(kitchen.getSelected());
}

TEST(KitchenTest, Selection) {
    Ingredient ingr("Onion");
    Kitchen kitchen(ingr, 1);

    EXPECT_FALSE(kitchen.getSelected());
    kitchen.setSelected(true);
    EXPECT_TRUE(kitchen.getSelected());
}