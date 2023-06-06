#include <string>

using namespace std;

class Ingredient {
private :
    std::string label;
public:
    explicit Ingredient(const std::string name);
    std::string getlabel() const;

};



