#pragma once
#include "Kitchen.h"

class Preparation : public Kitchen {
private:
    bool ready;
    bool free;
    int time_prep;
    int time_left;
public:
    explicit Preparation(std::unique_ptr<Ingredient> ingredientPtr);
    int prepare(Kitchen stock);
    friend std::ostream& operator<<(std::ostream& os, const Preparation& preparation);
    bool getready();
    bool getfree();
    int gettime_prep();
    int gettime_left();
    void freeprep();

};


