#pragma once
#include "Ingredient.h"
#include <vector>
#include <map>
#include "Pizza.h"
#include "PizzaManager.h"
#include "KitchenManager.h"
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
    sf::Sprite postit;
    sf::Sprite monsieur;
    sf::Sprite monsieur_arm;
    sf::Sprite lifeline;
    sf::Music music;
    sf::Sprite sound;
    bool sound_on_off;
    std::vector<Storage> storages;
    std::vector<Preparation> preparations;
    std::vector<Ingredient> ingredients;
    std::optional<Kitchen> selected;
    std::string selected_type;
    std::map<std::string, sf::Texture> textures;
    sf::Text scoreText;
    std::vector<sf::Text> recipeNotes;
    sf::Text recipeNote;
    sf::Text recipeNote2;
    sf::RectangleShape score_board;
    PizzaManager pizzaManager;
    KitchenManager kitchenManager;

public:
    sf::RenderWindow window;

    Facade();
    void run();
    void init();
    void render();
    void update(sf::Time elapsed_time);
    void draw_init(unsigned int screenWidth, unsigned int screenHeight);
    void startCooking(Preparation& preparation);
    void selectReady(Preparation& preparation);
    sf::Texture loadTextureFromFile(const std::string& filePath) const;
    std::pair<std::string,sf::Texture> addTextureFromFile(const std::string& name) const;
    void setTextureScalePosition(sf::Sprite& sprite, sf::Texture& texture, double scale, double position_x, double position_y) const;
    void setText(sf::Text& text, int characterSize, sf::Color color, float position_x, float position_y, std::string string) const;
    static const sf::Time TimePerFrame;
    void renderLost();
};