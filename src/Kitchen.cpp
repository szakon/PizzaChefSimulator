#include "Kitchen.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;


Kitchen::Kitchen(Ingredient ingr, int prepId, sf::Texture& texture, float scaleFactor)
        : ingredient(ingr), selected(false)
{
    this->prepId = prepId;
    sprite.setTexture(texture);
    sprite.setScale(scaleFactor,scaleFactor);

}

Ingredient Kitchen::getIngredient() {
    return ingredient;
}

bool Kitchen::getSelected() const {
    return selected;
}

void Kitchen::setSelected(bool select) {
    selected = select;
}

std::ostream& operator<<(std::ostream& os, const Kitchen& kitchen)
{
    os << "This is the Kitchen :" << endl;
    os << "ingredient : " << kitchen.ingredient << endl;
    os << "selected : " << kitchen.selected << endl;
    return os;
}

void Kitchen::setSprite(float scaleFactor, int screenWidth, float scaleJar, float y_position, sf::Texture& timer) {
    //sprite.setTexture(texture);
    //sprite.setScale(scaleFactor,scaleFactor);
    float position = ingredient.getOrder()*1.5;
    sf::Vector2f position_sprite(8*screenWidth/10-position * sprite.getTextureRect().width * scaleFactor, 20);
    //cout << "set sprite for " << ingredient.getLabel() << " at position: " << 8*screenWidth/10-position * sprite.getTextureRect().width * scaleFactor << " and with the scale factor: " << endl;
    sprite.setPosition(position_sprite);
}

sf::Sprite Kitchen::getSprite() const {
    return sprite;
}

int Kitchen::getPrepId() {
    return prepId;
}

void Kitchen::draw(sf::RenderWindow& window) {
    sprite.setScale(1,1);
    window.draw(sprite);
}



