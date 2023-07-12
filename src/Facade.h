#pragma once
#include "Ingredient.h"
#include <vector>
#include <map>
#include "Pizza.h"
#include "Kitchen.h"
#include "Storage.h"
#include <memory>
#include <optional>
#include <random>
#include "PizzaPool.h"
#include "SFML/Audio/Music.hpp"
#include <SFML/Graphics.hpp>

struct Ingr {
    Ingredient ingredient;
    bool added;
};

struct Piz {
    Pizza pizza;
    bool newPizzaGenerated;
};


class Facade {
private:
    sf::Sprite sprite_background;
    sf::RectangleShape belt;
    sf::Sprite madame;
    sf::Sprite monsieur;
    sf::Sprite monsieur_arm;
    sf::Sprite lifeline;
    sf::Music music;
    sf::Sprite sound;
    bool sound_on_off;
    std::vector<Pizza> pizzas;
    //std::map<int, Piz> pizzas;
    std::map<std::string, Storage> storages;
    std::map<std::string, Preparation> preparations;
    std::map<std::string, Ingr> ingredients;
    std::optional<Kitchen> selected;
    std::string selected_type;
    std::map<std::string, sf::Texture> textures;
    int score;
    int lives;
    sf::Text scoreText;
    sf::RectangleShape score_board;
    std::optional<PizzaPool> pool;



public:
    sf::RenderWindow window;

    void releasePizza(Pizza pizza);
    Facade();
    void run();
    void init();
    void render();
    void update(unsigned int screenWidth, unsigned int screenHeight);
    void draw_init(unsigned int screenWidth, unsigned int screenHeight);
    void startCooking(Preparation& preparation);
    void selectReady(Preparation& preparation);
    void addIngredient(Pizza& pizza);
    sf::Texture loadTextureFromFile(const std::string& filePath);
    void pizzaGenerator();
    void randomIngr(Pizza pizza);
    void addRandomIngredient(Pizza pizza, Ingredient Ingredient);
    std::pair<std::string,sf::Texture> addTextureFromFile(const std::string& name);
    void setTextureScalePosition(sf::Sprite& sprite, sf::Texture& texture, double scale, double position_x, double position_y);
    void move();
    static const sf::Time TimePerFrame;
    static const float xVelocity;
    void renderLost();
};
