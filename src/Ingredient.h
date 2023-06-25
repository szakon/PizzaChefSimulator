#pragma once
#include <string>
#include <unordered_map>
#include <map>
#include <vector>
#include <memory>

using namespace std;

class Ingredient {
private :
    std::string label;
    float position;
public:
    explicit Ingredient(const std::string name, const float place);
    std::string getlabel() const;
    float getPosition() const;
    friend std::ostream& operator<<(std::ostream& os, const Ingredient& ingredient);
    friend bool operator<(const Ingredient& lhs, const Ingredient& rhs);
    friend bool operator==(const Ingredient& lhs, const Ingredient& rhs);

};



