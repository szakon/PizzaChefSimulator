//
// Created by Sarah Zakon on 06/06/2023.
//

#import "Kitchen.h"
/*
#ifndef GLOUTON_STORAGE_H
#define GLOUTON_STORAGE_H

#endif //GLOUTON_STORAGE_H
*/

class Storage : public Kitchen {
public:
    explicit Storage(std::unique_ptr<Ingredient> ingredientPtr);

};