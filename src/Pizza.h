#pragma once
#include "Ingredient.h"
#include <vector>
#include <map>
#include "Ingredient.h"
#include "Preparation.h"

using namespace std;

class Pizza {
private :
    int id;
    std::map< shared_ptr<Ingredient> , bool> ingredients;
    std::vector<Preparation> preparations;
    bool completed;
public:
    explicit Pizza(const std::vector< shared_ptr<Ingredient>>& ingr, std::vector<Preparation> prep);
    std::map< shared_ptr<Ingredient> , bool> getIngredients();
    std::vector<Preparation> getPreparations();
    friend std::ostream& operator<<(std::ostream& os, const Pizza& pizza);
    int addIngredient();

    static int id_count;
};

