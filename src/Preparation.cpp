#include "Preparation.h"
#include "Kitchen.h"
#include "Pizza.h"
#include "Storage.h"
#include <chrono>
#include <thread>
#include <iostream>

int Preparation::id_count = 0;

Preparation::Preparation(Ingredient ingredient1) : Kitchen(ingredient1) {
    id = id_count++;
    free = true;
    ready = false;
    time_prep = 3;
    time_left = 3;
}

std::ostream& operator<<(std::ostream& os, const Preparation& preparation)
{
    os << "This is the Preparation :" << endl;
    os << "free : " << preparation.free << endl;
    os << "ready : " << preparation.ready << endl;
    os << "time_prep : " << preparation.time_prep << endl;
    os << "time_left : " << preparation.time_left << endl;
    return os;
}

int Preparation::prepare(Storage stock) {
    if(ingredient == stock.getingredient()) {
        if(free) {
            free = false;
            while(time_left > 0) {
                time_left -=1;
                sleep(1);
            }

            ready = true;

        }
        else{
            return 1;
        }
    }
    else{
        return 1;
    }
    return 0; //preparation time is done : preparation is ready to be used
}


void Preparation::freeprep() {
    ready = false;
    free = true;
}

bool Preparation::getready() {
    return ready;
}

bool Preparation::getfree() {
    return free;
}

int Preparation::gettime_prep() {
    return time_prep;
}

int Preparation::gettime_left() {
    return time_left;
}

void Preparation::reset() {
    selected = false;
    free = true;
    ready = false;
    time_left = time_prep;
}


