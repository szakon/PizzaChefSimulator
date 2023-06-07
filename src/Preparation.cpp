#include "Preparation.h"
#include "Kitchen.h"
#include <chrono>
#include <thread>
#include <iostream>


Preparation::Preparation(Ingredient ingredient1) : Kitchen(ingredient1) {
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

int Preparation::prepare(Kitchen stock) {
    if(ingredient == stock.getIngredient()) {
        if(free) {
            free = false;
            std::chrono::seconds delay(time_prep);
            std::thread thread([this, delay]() {
                std::this_thread::sleep_for(delay); // Attente du délai spécifié
                ready = true;
            });
            thread.detach();
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
