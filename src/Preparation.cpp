#include "Preparation.h"
#include "Kitchen.h"
#include "Pizza.h"
#include "Storage.h"
#include <chrono>
#include <thread>
#include <iostream>
#include <unistd.h>



Preparation::Preparation(Ingredient ingredient, int id) : Kitchen(ingredient) {
    this->id = id;
    free = true;
    ready = false;
    time_prep = 3;
    time_left = 3;
}

std::ostream& operator<<(std::ostream& os, const Preparation& preparation)
{
    os << "This is the Preparation :" << endl;
    os << "free : " << preparation.free << endl;
    os << "ready : " << preparation.ready << endl;
    os << "time_prep : " << preparation.time_prep << endl;
    os << "time_left : " << preparation.time_left << endl;
    return os;
}

int Preparation::prepare(Storage stock) {
    if(ingredient == stock.getIngredient()) {
        if(free) {
            free = false;
            while(time_left > 0) {
                time_left -=1;
                sleep(1);
            }

            ready = true;

        }
        else{
            return 1;
        }
    }
    else{
        return 1;
    }
    return 0; //preparation time is done : preparation is ready to be used
}


void Preparation::freeprep() {
    ready = false;
    free = true;
}

bool Preparation::getready() const {
    return ready;
}

bool Preparation::getfree() {
    return free;
}

int Preparation::gettime_prep() {
    return time_prep;
}

int Preparation::gettime_left() {
    return time_left;
}

void Preparation::reset() {
    selected = false;
    free = true;
    ready = false;
    time_left = time_prep;
}

void Preparation::setSprite(sf::Texture& texture, float scaleFactor, float position, int screenWidth, sf::Sprite jar, float scaleJar, float y_position){
    sprite.setTexture(texture);
    sprite.setScale(scaleFactor,scaleFactor);
    //sf::Vector2f spriteJar(8*screenWidth/10-position * sprite.getTextureRect().width * scaleFactor, 20);
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
    //sf::Vector2f pot1Position(8*screenWidth/10-position * sprite.getTextureRect().width * scaleFactor + center + distance, y_position);
    //sf::Vector2f pot2Position(8*screenWidth/10-position * sprite.getTextureRect().width * scaleFactor + center - distance, y_position);
    //sf::Vector2f pot1Position(20 + 1.2f * jar.getTextureRect().height*scaleJar);
    //sf::Vector2f position_sprite(8*screenWidth/10-position * sprite.getTextureRect().width * scaleFactor, 20);
}

bool Preparation::isStorage(){
    return false;
}

void Preparation::draw(sf::RenderWindow& window){
    window.draw(sprite);
}

int Preparation::getId() {
    return id;
}

