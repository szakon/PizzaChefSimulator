#pragma once
#include "Kitchen.h"

class Preparation : public Kitchen {
private:
    bool ready;
    int time_prep;
public:
    explicit Preparation(Ingredient ingredient1);
};


