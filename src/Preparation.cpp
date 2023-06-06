#include "Preparation.h"
#include "Kitchen.h"


Preparation::Preparation(Ingredient ingredient1) : Kitchen(ingredient1) {
    ready = false;
    time_prep = 3;
}
