#pragma once
#include "Ingredient.h"
#include <vector>
#include <map>
#include "Pizza.h"
#include "PizzaManager.h"
#include "Kitchen.h"
#include "Storage.h"
#include <memory>
#include <optional>
#include <random>
#include "PizzaPool.h"
#include "SFML/Audio/Music.hpp"
#include <SFML/Graphics.hpp>


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
    std::map<std::string, Storage> storages;
    std::vector<Preparation> preparations;
    std::vector<Ingredient> ingredients;
    std::optional<Kitchen> selected;
    std::string selected_type;
    std::map<std::string, sf::Texture> textures;
    sf::Text scoreText;
    sf::RectangleShape score_board;
    std::optional<PizzaPool> pool; //PM
    PizzaManager pizzaManager;



public:
    sf::RenderWindow window;

    void releasePizza(Pizza pizza); //PM
    Facade();
    void run();
    void init();
    void render();
    void update(unsigned int screenWidth, unsigned int screenHeight);
    void draw_init(unsigned int screenWidth, unsigned int screenHeight);
    void startCooking(Preparation& preparation);
    void selectReady(Preparation& preparation);
    sf::Texture loadTextureFromFile(const std::string& filePath);
    std::pair<std::string,sf::Texture> addTextureFromFile(const std::string& name);
    void setTextureScalePosition(sf::Sprite& sprite, sf::Texture& texture, double scale, double position_x, double position_y);
    static const sf::Time TimePerFrame;
    static const float xVelocity;
    void renderLost();
};
