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
    int time_prep;
    shared_ptr<int> time_left;
    sf::Sprite timer;
    sf::Sprite checkMark;
public:
    explicit Preparation(Ingredient ingredient, int prepId);
    bool preparing_if_needed();
    std::string getStatus() const;
    void setStatus( const std::string stat);
    void reset();
    friend std::ostream& operator<<(std::ostream& os, const Preparation& preparation);
    void SetReady();
    int getTimePrep();
    int getTimeLeft();
    void freeprep();
    void setSprite(sf::Texture& texture, float scaleFactor, float position, int screenWidth, sf::Sprite jar, float scaleJar, float y_position, sf::Texture& clock, sf::Texture& check);
    void addTimer(sf::Texture& texture);
    void draw(sf::RenderWindow& window);
    bool isStorage();

    static int id_count;
    static int TIMEPREP;
};


