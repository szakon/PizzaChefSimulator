#pragma once
#include "Kitchen.h"

class Preparation : public Kitchen {
private:
    bool ready;
    bool free;
    int time_prep;
public:
    explicit Preparation(Ingredient ingredient1);
    int prepare(Kitchen stock);
    void freeprep();

};


