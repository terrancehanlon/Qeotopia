// #pragma once
#ifndef PLATFORM_H
#define PLATFORM_H

#include "../../alive/headers/Pig.hpp"

class Platform {

    private:
    
    public:
        AnimatedSprite ani;
        Animation anim;
        sf::Texture texture;
        Platform(float x, float y);
        ~Platform();

        void update(sf::Time dt);

        void draw(sf::RenderWindow *window);

};

#endif