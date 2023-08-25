#include "Preparation.h"
#include "Kitchen.h"
#include <chrono>
#include <iostream>



static int TIMEPREP = 200;

Preparation::Preparation(Ingredient ingredient, int prepId) : Kitchen(ingredient, prepId) {
    //this->prepId = prepId;
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

void Preparation::preparing_if_needed() {
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

    return "";
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
    selected = false;
}

void Preparation::setSprite(sf::Texture& preparation1, float scaleFactor, int screenWidth, sf::Sprite jar, float scaleJar, float y_position, sf::Texture& clock, sf::Texture& check, sf::Texture& preparation2){
    if (prepId/2<1){
        sprite.setTexture(preparation1);
    }else{
        sprite.setTexture(preparation2);
    }
    sprite.setScale(scaleFactor,scaleFactor);

    int center = jar.getTextureRect().width * scaleJar/2 - sprite.getTextureRect().width*scaleFactor/2;
    int distance = 0.4*sprite.getTextureRect().width* scaleFactor;

    timer.setTexture(clock);
    timer.setScale(sf::Vector2f(0.05,0.05));

    checkMark.setTexture(check);
    checkMark.setScale(sf::Vector2f(0.2,0.2));

    float position = ingredient.getOrder()*1.7;
    int y = y_position + sprite.getTextureRect().height*scaleFactor*1.5 * floor(prepId/2);
    if (prepId%2 == 0){
        sf::Vector2f pot1Position(8.5*screenWidth/10-position * sprite.getTextureRect().width * scaleFactor + center - distance, y);
        sprite.setPosition(pot1Position);
        timer.setPosition(pot1Position);
        checkMark.setPosition(pot1Position);
        cout << "preparation " << ingredient.getLabel() << " has this position " << sprite.getPosition().x << " , " << sprite.getPosition().y << " and this scale: " << sprite.getScale().x << endl;


    }else{
        sf::Vector2f pot2Position(8.5*screenWidth/10-position * sprite.getTextureRect().width * scaleFactor + center + distance, y);
        sprite.setPosition(pot2Position);
        timer.setPosition(pot2Position);
        checkMark.setPosition(pot2Position);
        cout << "2";
    }
}

bool Preparation::isStorage(){
    return false;
}

void Preparation::draw(sf::RenderWindow& window){
    window.draw(sprite);
    if(*status == inprep) {
        window.draw(timer);
    }else if (*status == ready){
        window.draw(checkMark);
    }
}

