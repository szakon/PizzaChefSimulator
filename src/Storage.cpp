#include "Storage.h"
#include "Kitchen.h"


Storage::Storage(std::unique_ptr<Ingredient> ingredient) : Kitchen(std::move(ingredient)) {
}

