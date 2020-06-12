#include "headers/Health.hpp"

Health::Health(){
    this->current_health = this->max_health;
};

int Health::getHealth(AnimatedSprite *ani){
    return ani->get_current_health();
};

void Health::setHealth(AnimatedSprite *ani, int health){
    ani->set_health(health);
};

void Health::updateHealth(AnimatedSprite *ani){
    this->current_health = ani->get_current_health();
};