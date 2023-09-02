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
    shared_ptr<Status> status;
    sf::Time time_prep;
    shared_ptr<sf::Time> time_left;
    sf::Sprite timer;
    sf::Sprite checkMark;
    sf::Sprite sprite2;
    sf::RectangleShape progressBar;

public:
    explicit Preparation(Ingredient ingredient, int prepId);
    void preparing_if_needed(sf::Time elapsed_time);
    std::string getStatus() const;
    void setStatus(const std::string stat);
    void reset();
    friend std::ostream& operator<<(std::ostream& os, const Preparation& preparation);
    sf::Time getTimePrep();
    sf::Time getTimeLeft();
    float getProgress() const;
    void setSprite(sf::Texture& texture, float scaleFactor, int screenWidth, sf::Sprite jar, float scaleJar, float y_position, sf::Texture& clock, sf::Texture& check, sf::Texture& preparation2);
    void draw(sf::RenderWindow& window);
};


