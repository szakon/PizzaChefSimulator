#include "Storage.h"
#include "Kitchen.h"


Storage::Storage(std::unique_ptr<Ingredient> ingredientPtr) : Kitchen(std::move(ingredientPtr)) {
}

