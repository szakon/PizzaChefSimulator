#include "Preparation.h"
#include "Kitchen.h"
#include <chrono>
#include <iostream>


const static sf::Time TIMEPREP = sf::seconds(6.0f); //Preparation time

Preparation::Preparation(Ingredient ingredient, int prepId, sf::Texture& texture, float scaleFactor, sf::Texture& texture2) : Kitchen(ingredient, prepId, texture, scaleFactor) {
    //this->prepId = prepId;
    status = notused;
    time_prep = TIMEPREP;
    time_left = TIMEPREP;

    cout << "preparation created for ingredient: " << ingredient.getLabel() << " NUMBER " << ingredient.getNumPreparations() << endl;
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

    cout << "PREPARATION ORDER " << preparation_order << endl;

}

std::ostream& operator<<(std::ostream& os, const Preparation& preparation)
{
    os << "Preparation :" << endl;
    os << "status" << preparation.status;
    os << "time_prep : " << preparation.time_prep.asSeconds() << endl;
    os << "time_left : " << preparation.time_left.asSeconds() << endl;
    return os;
}

void Preparation::preparing_if_needed(sf::Time elapsed_time) {
    if(status == inprep) {
        cout << "time spent " << elapsed_time.asSeconds() << endl;
        //time_left -= elapsed_time;
        time_left -= elapsed_time;
        cout << "time left" << time_left.asSeconds();
    }
    if(time_left <= sf::Time::Zero) {
        status = ready;
    }
}

float Preparation::getProgress() const {
    float progress = 1.0f - time_left.asSeconds() / time_prep.asSeconds();
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

sf::Time Preparation::getTimePrep() const {
    return time_prep;
}

sf::Time Preparation::getTimeLeft() const {
    return time_left;
}

void Preparation::reset() {
    status = notused;
    time_left = TIMEPREP;
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
        cout << "preparation " << ingredient.getLabel() << " has this position " << sprite.getPosition().x << " , " << sprite.getPosition().y << " and this scale: " << sprite.getScale().x << endl;


    }else{
        sf::Vector2f pot2Position(8.5*screenWidth/10-position * sprite.getTextureRect().width * scaleFactor + center + distance, y);
        sprite.setPosition(pot2Position);
        progressBar.setPosition(pot2Position);
        timer.setPosition(pot2Position);
        checkMark.setPosition(pot2Position);
        cout << "2";
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

