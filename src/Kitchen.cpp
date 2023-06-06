#include "Kitchen.h"

using namespace std;


Kitchen::Kitchen(Ingredient ingredient1)
    : ingredient(ingredient1)
{
    selected = false;
}

Ingredient Kitchen::getIngredient() {
    return ingredient;
}
