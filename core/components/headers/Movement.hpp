#ifndef MOVEMENT_H
#define MOVEMENT_H

// #include "ZoneOne.hpp"
#include "../../entities/structural/headers/Platform.hpp"

#include <math.h>

class Movement {

    private:
        float movementSpeed = 501.90f;
        sf::Vector2f movement;

    public:
        Movement(float movementSpeed);
        ~Movement();

        sf::Vector2f move(sf::Time deltaTime, AnimatedSprite *ani, sf::View *view);
        float getPlayerX(AnimatedSprite *ani);
        float getPlayerY(AnimatedSprite *ani);
        void setMove(sf::Vector2f *movement);
        sf::Vector2f *getMovementVector();
        void resetMovement();
        void backPeddle(AnimatedSprite *ani) ;

        float jumpHeight = 50.0f;
        void stop(AnimatedSprite *ani, float x, float y);

        bool isJumping = false;
        bool landed = false;
        bool canJump = true;
        sf::Clock lastJump;
        bool falling = false;

        sf::Vector2f _movement;
        float last_y = 285.03f ; //360 is current ground probably make this a variable
        float ground = 285.03f;
};

#endif