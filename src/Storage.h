#pragma once
#import "Kitchen.h"


class Storage : public Kitchen {
public:
    explicit Storage(std::unique_ptr<Ingredient> ingredientPtr);

};