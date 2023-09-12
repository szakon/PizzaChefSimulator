#include "Storage.h"
#include "Kitchen.h"
#include <SFML/Graphics.hpp>


Storage::Storage(Ingredient ingredient, int prepId, sf::Texture& texture, float scaleFactor) : Kitchen(ingredient, prepId, texture, scaleFactor) {
}


bool Storage::isStorage(){
    return true;
}
