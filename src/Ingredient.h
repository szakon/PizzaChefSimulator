#pragma once
#include <string>
#include <unordered_map>
#include <map>
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

using namespace std;

class Ingredient {
private :
    std::string label;
    float radius;
    sf::CircleShape circle;
    int order;
public:
    explicit Ingredient(const std::string name, const int order, const float radius, sf::Texture& texture);
    std::string getLabel() const;
    friend std::ostream& operator<<(std::ostream& os, const Ingredient& ingredient);
    friend bool operator<(const Ingredient& lhs, const Ingredient& rhs);
    friend bool operator==(const Ingredient& lhs, const Ingredient& rhs);
    void printIngredient(sf::RenderWindow& window, sf::Vector2<float> ingredientPosition);
    int getOrder();

};



