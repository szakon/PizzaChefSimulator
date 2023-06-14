#pragma once
#include "Kitchen.h"
#include "Storage.h"

class Preparation : public Kitchen {
private:
    int id;
    bool ready;
    bool free;
    int time_prep;
    int time_left;
public:
    explicit Preparation(Ingredient ingredient, int id);
    int prepare(Storage stock);
    void reset();
    friend std::ostream& operator<<(std::ostream& os, const Preparation& preparation);
    bool getready() const;
    bool getfree();
    int gettime_prep();
    int gettime_left();
    void freeprep();
    int getId();
    void setSprite(sf::Texture& texture, float scaleFactor, float position, int screenWidth, sf::Sprite jar, float scaleJar, float y_position);
    void draw(sf::RenderWindow& window);
    bool isStorage();

    static int id_count;
};


