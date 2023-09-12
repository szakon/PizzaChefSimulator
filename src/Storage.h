#pragma once
#include "Kitchen.h"


class Storage : public Kitchen {
public:
    explicit Storage(Ingredient ingr, int prepId, sf::Texture& texture, float scaleFactor);
    bool isStorage();

};