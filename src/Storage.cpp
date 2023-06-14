#include "Storage.h"
#include "Kitchen.h"
#include <SFML/Graphics.hpp>


Storage::Storage(Ingredient ingredient) : Kitchen(ingredient) {
}


bool Storage::isStorage(){
    return true;
}
