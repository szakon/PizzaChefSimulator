#pragma once
#include <string>
#include <unordered_map>
#include <map>
#include <vector>
#include <memory>

using namespace std;

class Ingredient {
private :
    int id;
    std::string label;
public:
    static int idCount;
    explicit Ingredient(const std::string name);
    std::string getlabel() const;
    friend std::ostream& operator<<(std::ostream& os, const Ingredient& ingredient);
    friend bool operator<(const Ingredient& lhs, const Ingredient& rhs);
    friend bool operator==(const Ingredient& lhs, const Ingredient& rhs);
    static std::vector<Ingredient> getValue(const std::map<int, std::shared_ptr<Ingredient>>& map);

};



