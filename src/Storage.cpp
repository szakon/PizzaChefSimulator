//
// Created by Sarah Zakon on 06/06/2023.
//

#include "Storage.h"



Storage::Storage(std::unique_ptr<Ingredient> ingredientPtr) : Kitchen(std::move(ingredientPtr)) {

}