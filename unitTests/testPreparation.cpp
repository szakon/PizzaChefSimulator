#include <gtest/gtest.h>
#include "Ingredient.h"
#include "Preparation.h"
#include "Storage.h"


TEST(PreparationTest, Constructor) {
    Ingredient ingr("Onion"); // Example ingredient for testing
    Preparation prep = Preparation(ingr,1);

    // Verify that the ingredient is set correctly
    EXPECT_EQ(prep.getId(), 1);
    // Verify that the selected status is initialized as false
    EXPECT_TRUE(prep.getfree());
    EXPECT_FALSE(prep.getready());
    EXPECT_EQ(prep.gettime_prep(), prep.gettime_left());
}

TEST(PreparationTest, Prepare) {
    Ingredient ingr("Onion"); // Example ingredient for testing
    Preparation prep = Preparation(ingr,1);
    Storage storage = Storage(ingr);

    prep.prepare(storage);

    EXPECT_FALSE(prep.getfree());
    EXPECT_TRUE(prep.getready());
}

TEST(PreparationTest, Reset) {
    Ingredient ingr("Onion"); // Example ingredient for testing
    Preparation prep = Preparation(ingr,1);

    prep.reset();

    EXPECT_FALSE(prep.getSelected());
    EXPECT_TRUE(prep.getfree());
    EXPECT_FALSE(prep.getready());
    EXPECT_EQ(prep.gettime_left(),prep.gettime_prep());

}