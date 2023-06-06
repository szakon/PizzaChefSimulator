#pragma once
#include <string>

using namespace std;

class Ingredient {
private :
    std::string label;
public:
    explicit Ingredient(const std::string name);
    std::string getlabel() const;


    // Declare less-than operator as a friend function
    friend bool operator<(const Ingredient& lhs, const Ingredient& rhs);

    friend bool operator==(const Ingredient& lhs, const Ingredient& rhs);

};



