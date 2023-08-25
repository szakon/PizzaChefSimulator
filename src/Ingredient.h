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
    sf::Sprite recipe;
    int order;
    std::string preparation;
    std::string preparation2;
    std::string storage;
    int numPreparations;
public:
    explicit Ingredient(const std::string name, const int order, const float radius, sf::Texture& texture, std::string texture_preparation, std::string storage, sf::Texture& recipeTex, int numPreparations, std::string texture_preparation2);
    std::string getLabel() const;
    std::string getPreparation() const;
    std::string getPreparation2() const;
    std::string getStorage() const;
    friend std::ostream& operator<<(std::ostream& os, const Ingredient& ingredient);
    friend bool operator<(const Ingredient& lhs, const Ingredient& rhs);
    friend bool operator==(const Ingredient& lhs, const Ingredient& rhs);
    void printIngredient(sf::RenderWindow& window, sf::Vector2<float> ingredientPosition);
    int getOrder();
    void printRecipe(sf::RenderWindow& window, int pizzaNum, sf::Sprite postit);
    int getNumPreparations() const;

};



