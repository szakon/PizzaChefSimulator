#include "Preparation.h"
#include "Kitchen.h"
#include <chrono>
#include <thread>


Preparation::Preparation(Ingredient ingredient1) : Kitchen(ingredient1) {
    free = true;
    ready = false;
    time_prep = 3;
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
