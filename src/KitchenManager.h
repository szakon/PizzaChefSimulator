//
// Created by Sarah Zakon on 11/09/2023.
//

#ifndef GLOUTON_KITCHENMANAGER_H
#define GLOUTON_KITCHENMANAGER_H

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

class KitchenManager {
private:
    std::vector<Storage> storages;
    std::vector<Preparation> preparations;
    std::vector<Ingredient> ingredients;
    std::optional<Kitchen> selected;
    std::string selected_type;
    std::map<std::string, sf::Texture> textures;
    float scaleFactorJar = 0.9f*screenWidth/2500;
    float scaleFactorPot = 0.15f*screenWidth/2500;
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    unsigned int screenWidth = desktopMode.width;

public:
    explicit KitchenManager();
    void setIngredients(std::vector<Ingredient> ingredients);
    void setTextures(std::map<std::string, sf::Texture> textures);
    std::optional<Kitchen> getSelected();
    std::string getSelectedType();
    void setSelected();
    void setSelectedType();
    void resetSelected();
    void setSelected(Kitchen element);
    void setSelectedType(std::string string);
    std::vector<Preparation> getPreparations();
    std::vector<Storage> getStorages();
    void initPrepAndStorage();
    void initSprite();
    void startCooking(Preparation &preparation);
    void selectReady(Preparation &preparation);
    void printKitchen(sf::RenderWindow& window);
    void mousePressed(sf::Event event,sf::RenderWindow& window, bool isTouched);
    bool onTouchedStorage(sf::Vector2i mousePos, sf::RenderWindow& window);
    bool onTouchedPreparation(sf::Vector2i mousePos, sf::RenderWindow& window);
    void setSprites();
    void prepareIfNeeded(sf::Time elapsed_time);
    void addIngredient();
};
#endif //GLOUTON_KITCHENMANAGER_H
