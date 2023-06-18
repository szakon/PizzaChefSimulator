#include <gtest/gtest.h>
#include "Ingredient.h"
#include "Preparation.h"
#include "Storage.h"


TEST(PreparationTest, Constructor) {
    Ingredient ingr("Onion"); // Example ingredient for testing
    Preparation prep = Preparation(ingr,1);

    // Verify that the ingredient is set correctly
    // Verify that the selected status is initialized as false
    EXPECT_EQ(prep.getStatus(), "notused");
    EXPECT_EQ(prep.getTimePrep(), prep.getTimeLeft());
}

TEST(PreparationTest, Preparinf_if_needed) {
    Ingredient ingr("Onion"); // Example ingredient for testing
    Preparation prep = Preparation(ingr,1);

    prep.preparing_if_needed();
    EXPECT_EQ(prep.getTimeLeft(), prep.getTimePrep());

    prep.setStatus("inprep");
    int i = 1;
    while(prep.getTimeLeft() > 0) {
        prep.preparing_if_needed();
        EXPECT_EQ(prep.getTimeLeft(), prep.getTimePrep() -i);
        i++;
    }

    prep.preparing_if_needed();
    EXPECT_EQ(prep.getTimeLeft(), 0);
    EXPECT_EQ(prep.getStatus(), "ready");
}

TEST(PreparationTest, Reset) {
    Ingredient ingr("Onion"); // Example ingredient for testing
    Preparation prep = Preparation(ingr,1);

    prep.reset();

    EXPECT_FALSE(prep.getSelected());
    EXPECT_EQ(prep.getStatus(), "notused");
    EXPECT_FALSE(prep.getSelected());
    EXPECT_EQ(prep.getTimeLeft(),prep.getTimePrep());
}