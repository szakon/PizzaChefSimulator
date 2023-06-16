#include "Preparation.h"
#include "Kitchen.h"
#include "Pizza.h"
#include "Storage.h"
#include <chrono>
#include <thread>
#include <iostream>
#include <unistd.h>

static int TIMEPREP = 200;

Preparation::Preparation(Ingredient ingredient, int id) : Kitchen(ingredient) {
    this->id = id;
    status = make_shared<Status>(notused);
    time_prep = ::TIMEPREP;
    time_left = make_shared<int>(::TIMEPREP);
}

std::ostream& operator<<(std::ostream& os, const Preparation& preparation)
{
    os << "Preparation :" << endl;
    os << "status" << preparation.status;
    os << "time_prep : " << preparation.time_prep << endl;
    os << "time_left : " << preparation.time_left << endl;
    return os;
}

bool Preparation::preparing_if_needed() {
    if(*status == inprep) {
        *time_left -= 1;
    }
    if(*time_left == 0) {
        *status = ready;
    }
}

std::string Preparation::getStatus() const {
    if(*status == inprep) {
        return "inprep";
    }
    else if (*status == notused) {
        return "notused";
    }
    else if (*status == ready) {
        return "ready";
    }
}

void Preparation::setStatus( const std::string stat) {
    if(stat == "inprep") {
        *status = inprep;
    }
    else if (stat == "notused") {
        *status = notused;
    }
    else if (stat == "ready") {
        *status = ready;
    }
}

int Preparation::getTimePrep() {
    return time_prep;
}

int Preparation::getTimeLeft() {
    return *time_left;
}

void Preparation::reset() {
    *status = notused;
    *time_left = time_prep;
}

void Preparation::setSprite(sf::Texture& texture, float scaleFactor, float position, int screenWidth, sf::Sprite jar, float scaleJar, float y_position){
    sprite.setTexture(texture);
    sprite.setScale(scaleFactor,scaleFactor);

    int center = jar.getTextureRect().width * scaleJar/2 - sprite.getTextureRect().width*scaleFactor/2;
    int distance = 0.4*sprite.getTextureRect().width* scaleFactor;

    if (id == 1){
        cout << "FIRST SPRITE" << endl;
        sf::Vector2f pot1Position(8*screenWidth/10-position * sprite.getTextureRect().width * scaleFactor + center - distance, y_position);
        sprite.setPosition(pot1Position);

    }else{
        cout << "SECOND SPRITE" << endl;
        sf::Vector2f pot2Position(8*screenWidth/10-position * sprite.getTextureRect().width * scaleFactor + center + distance, y_position);
        sprite.setPosition(pot2Position);
    }
}

bool Preparation::isStorage(){
    return false;
}

void Preparation::draw(sf::RenderWindow& window){
    window.draw(sprite);
    cout << "AVANT";
    if(*status == inprep) {
        cout << "OK C4EST BON";
        window.draw(sprite_prep);
    }
}

void Preparation::addTimer(sf::Texture &texture) {
    sf::Vector2f position = sf::Vector2f(200,200);
    sprite_prep.setTexture(texture);
    sprite_prep.setScale(sf::Vector2f (300,300));
    sprite_prep.setPosition(position);
}



