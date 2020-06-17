#include "headers/Ability.hpp"

Ability::Ability(){};


void Ability::check(Entity *e){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::T)){
        // printf("ATTACKING\n");
        e->swing();
    }
    else{
        e->run();
    }
};