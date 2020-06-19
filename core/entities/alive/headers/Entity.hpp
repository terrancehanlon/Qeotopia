#ifndef ENTITY_H
#define ENTITY_H

// #pragma once

#include "../../../components/headers/Movement.hpp"
// #include "../../entities/structural/headers/Platform.hpp"
// #include "../../structural/headers/Platform.hpp"
// #include "../../../../Lib/Imports.hpp"

class Entity
{
    private:
        Movement *movementComp;


    public:
        // sf::View *view;
        sf::Vector2f movement;
        float movementSpeed;
        // sf::Sprite *sprite;
        Entity();
        AnimatedSprite ani;
        Animation anim;
        Animation attack;
        sf::Texture run_text;
        sf::Texture attack_text;
        // sf::Texture 

        void update(sf::Time deltaTime);
        void render(sf::RenderWindow *window);

        void swing();
        void run();

        int maxHealth = 3;
        int currentHealth = 3;

        Animation *current_animation;
        bool is_attacking = false;



};

#endif
