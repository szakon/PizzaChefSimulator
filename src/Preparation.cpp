#include "Preparation.h"
#include "Kitchen.h"
#include <iostream>
#include <cmath>


const static sf::Time TIMEPREP = sf::seconds(1); //Preparation time

Preparation::Preparation(Ingredient ingredient, int prepId, sf::Texture& texture, float scaleFactor, sf::Texture& texture2) : Kitchen(ingredient, prepId, texture, scaleFactor) {
    //this->prepId = prepId;
    status = notused;
    time_prep = TIMEPREP.asSeconds();
    time_left = TIMEPREP.asSeconds();
    if(ingredient.getNumPreparations() == 2){
        if(floor(prepId / 2) == 1){
            preparation_order = 2;
        }else{
            preparation_order = 1;
        }
    }else{
        preparation_order = 0;
    }

    if (preparation_order == 2){
        sprite.setTexture(texture2);
    }else{
        sprite.setTexture(texture);
    }

}

std::ostream& operator<<(std::ostream& os, const Preparation& preparation)
{
    os << "Preparation :" << endl;
    os << "status" << preparation.status;
    os << "time_prep : " << preparation.time_prep << endl;
    os << "time_left : " << preparation.time_left << endl;
    return os;
}

void Preparation::preparing_if_needed(sf::Time elapsed_time) {
    if(status == inprep) {
        time_left -= elapsed_time.asSeconds();
    }
    if(time_left <= 0) {
        status = ready;
    }
}

float Preparation::getProgress() const {
    float progress = 1.0f - time_left / time_prep;
    return std::max(0.0f, std::min(1.0f, progress)); // Between 0 and 1
}

std::string Preparation::getStatus() const {
    if(status == inprep) {
        return "inprep";
    }
    else if (status == notused) {
        return "notused";
    }
    else if (status == ready) {
        return "ready";
    }

    return "";
}

void Preparation::setStatus( const std::string stat) {
    if(stat == "inprep") {
        status = inprep;
    }
    else if (stat == "notused") {
        status = notused;
    }
    else if (stat == "ready") {
        status = ready;
    }
}

float Preparation::getTimePrep() const {
    return time_prep;
}

float Preparation::getTimeLeft() const {
    return time_left;
}

void Preparation::reset() {
    status = notused;
    time_left = TIMEPREP.asSeconds();
    selected = false;
}

void Preparation::setSprite(float scaleFactor, int screenWidth, sf::Sprite jar, float scaleJar, float y_position, sf::Texture& clock, sf::Texture& check){
    /*
    if (prepId/2<1){
        sprite.setTexture(preparation1);
    }else{
        sprite.setTexture(preparation2);
    }*/
    sprite.setScale(scaleFactor,scaleFactor);

    int center = jar.getTextureRect().width * scaleJar/2 - sprite.getTextureRect().width*scaleFactor/2;
    int distance = 0.4*sprite.getTextureRect().width* scaleFactor;

    progressBar.setSize(sf::Vector2f(getProgress() * 200, 50));
    progressBar.setFillColor(sf::Color::Green);

    timer.setTexture(clock);
    timer.setScale(sf::Vector2f(0.05,0.05));

    checkMark.setTexture(check);
    checkMark.setScale(sf::Vector2f(0.2,0.2));

    float position = ingredient.getOrder()*1.7;
    int y = y_position + sprite.getTextureRect().height * scaleFactor * 1.5 * floor(prepId / 2);
    if (prepId%2 == 0){
        sf::Vector2f pot1Position(8.5*screenWidth/10-position * sprite.getTextureRect().width * scaleFactor + center - distance, y);
        sprite.setPosition(pot1Position);
        timer.setPosition(pot1Position);
        progressBar.setPosition(pot1Position);
        checkMark.setPosition(pot1Position);

    }else{
        sf::Vector2f pot2Position(8.5*screenWidth/10-position * sprite.getTextureRect().width * scaleFactor + center + distance, y);
        sprite.setPosition(pot2Position);
        progressBar.setPosition(pot2Position);
        timer.setPosition(pot2Position);
        checkMark.setPosition(pot2Position);
    }
}


void Preparation::draw(sf::RenderWindow& window){
    window.draw(sprite);
    if(status == inprep) {
        window.draw(timer);
        progressBar.setSize(sf::Vector2f(getProgress() * 80, 20));
        window.draw(progressBar);
    }else if (status == ready){
        window.draw(checkMark);
    }
}

int Preparation::getPreparationOrder(){
    return preparation_order;
}

