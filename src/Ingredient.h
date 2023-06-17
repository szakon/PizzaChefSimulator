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
public:
    explicit Ingredient(const std::string name);
    std::string getlabel() const;
    friend std::ostream& operator<<(std::ostream& os, const Ingredient& ingredient);
    friend bool operator<(const Ingredient& lhs, const Ingredient& rhs);
    friend bool operator==(const Ingredient& lhs, const Ingredient& rhs);
    static std::vector<Ingredient> getValue(const std::map<int, Ingredient>& map);

};



