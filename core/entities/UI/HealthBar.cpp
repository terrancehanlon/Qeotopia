#include "headers/HealthBar.hpp"


HealthBar::HealthBar(){
    this->texture.loadFromFile("Assets/Sprites/Health_Coins/health_bars.png");

    //probably expensive to set sprite sheet like
    this->anim_3_heart.setSpriteSheet(this->texture);
    this->anim_2_heart.setSpriteSheet(this->texture);
    this->anim_1_heart.setSpriteSheet(this->texture);
    this->anim_1_heart.addFrame(sf::IntRect(5,5,66,24));
    this->anim_2_heart.addFrame(sf::IntRect(5, 49, 66, 34));
    this->anim_3_heart.addFrame(sf::IntRect(81, 5, 66, 34));

    this->ani.setPosition(sf::Vector2f(10,10));
    this->ani.setAnimation(this->anim_3_heart);
    this->ani.play(this->anim_3_heart);

};

void HealthBar::draw(sf::RenderWindow *window){
    window->draw(this->ani);
};

void HealthBar::update(sf::Time dt, Health *healthcomp){
    if(healthcomp->current_health == 3){
        this->ani.play(this->anim_3_heart);
    }
    else if(healthcomp->current_health == 2){
        this->ani.play(this->anim_2_heart);
    }
    else{
        this->ani.play(this->anim_1_heart);
    }

    this->ani.update(dt);
};