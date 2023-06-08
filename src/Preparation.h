#pragma once
#include "Kitchen.h"
#include "Storage.h"

class Preparation : public Kitchen {
private:
    int id;
    bool ready;
    bool free;
    int time_prep;
    int time_left;
public:
    explicit Preparation(Ingredient ingredient,sf::Texture texture);
    int prepare(Storage stock);
    void reset();
    friend std::ostream& operator<<(std::ostream& os, const Preparation& preparation);
    bool getready() const;
    bool getfree();
    int gettime_prep();
    int gettime_left();
    void freeprep();

    static int id_count;
};


