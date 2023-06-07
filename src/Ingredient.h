#pragma once
#include <string>
#include <unordered_map>
#include <map>


using namespace std;

class Ingredient {
private :
    int id;
    std::string label;
public:
    static int idCount;
    explicit Ingredient(const std::string name);
    std::string getlabel() const;


    // Declare less-than operator as a friend function
    friend bool operator<(const Ingredient& lhs, const Ingredient& rhs);


    friend bool operator==(const Ingredient& lhs, const Ingredient& rhs);

    static std::vector<Ingredient> getValue(const std::map<int, std::unique_ptr<Ingredient>>& map);



};



