#include "Storage.h"
#include "Kitchen.h"
#include <SFML/Graphics.hpp>


Storage::Storage(Ingredient ingredient, int prepId) : Kitchen(ingredient, prepId) {
}


bool Storage::isStorage(){
    return true;
}
