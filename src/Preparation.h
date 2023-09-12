#pragma once
#include "Kitchen.h"
#include "Storage.h"

enum Status {
    notused = 0,
    inprep = 1,
    ready = 2,
};

class Preparation : public Kitchen {
private:
    Status status;
    sf::Time time_prep;
    sf::Time time_left;
    sf::Sprite timer;
    sf::Sprite checkMark;
    sf::Sprite sprite2;
    sf::RectangleShape progressBar;
    int preparation_order;

public:
    //explicit Preparation(Ingredient ingredient, int prepId);
    explicit Preparation(Ingredient ingr, int prepId, sf::Texture& texture, float scaleFactor, sf::Texture& texture2);
    void preparing_if_needed(sf::Time elapsed_time);
    std::string getStatus() const;
    void setStatus(const std::string stat);
    void reset();
    friend std::ostream& operator<<(std::ostream& os, const Preparation& preparation);
    sf::Time getTimePrep() const;
    sf::Time getTimeLeft() const;
    float getProgress() const;
    void setSprite(float scaleFactor, int screenWidth, sf::Sprite jar, float scaleJar, float y_position, sf::Texture& clock, sf::Texture& check);
    void draw(sf::RenderWindow& window);
    int getPreparationOrder();
};


