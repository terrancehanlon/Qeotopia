#include "headers/Movement.hpp"

Movement::Movement(float movementSpeed){
    this->movementSpeed = movementSpeed;
};

Movement::~Movement(){
    // this->movementSpeed = NULL;
    delete &movement;   
    delete &lastJump;
    delete &jumpHeight;

};

float Movement::getPlayerX(AnimatedSprite *ani){
    return ani->getPosition().x;
}

float Movement::getPlayerY(AnimatedSprite *ani){
    return ani->getPosition().y;
}

void Movement::backPeddle(AnimatedSprite *ani){
    ani->move(sf::Vector2f(-0.05f, 0.0f));
}
void Movement::stop(AnimatedSprite *ani, float x, float y){
    landed = true;
    this->last_y = y;
}
void Movement::move(sf::Time deltaTime, AnimatedSprite *ani, sf::View *view){
    // ani = new Entity();
    this->_movement.x = 0.0f;
    this->_movement.y = 0.0f;
    if(ani->getPosition().y < this->ground && !landed){
        this->falling = true;
    }
    else{
        this->falling = false;
    }
    if(ani->getPosition().y <= (this->last_y - this->jumpHeight) && !landed){ //lands on platform
        isJumping = false;
    }else if (ani->getPosition().y >= this->ground)
    {   
        falling = false;
        landed = false;
        ani->setPosition(sf::Vector2f(ani->getPosition().x, this->ground));
        // ani->move(this->_movement)
        last_y = ani->getPosition().y;
    }

    if(isJumping){
        // ani->move(sf::Vector2f(0.0f, -0.05f));
        // this->_movement.y -= sqrt(0.05f * 2.0f * 981.0f); //change to jump speed?
        this->_movement.y -= 0.10f;
    }
    // this->_movement.y += (981.0f * deltaTime.asSeconds());
    if(!isJumping && !landed){
        // ani->move(sf::Vector2f(0.0f, 0.05f));
        //falling
        this->_movement.y += this->movementSpeed; //change to falling speed
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        //left
        if(!isJumping && !landed){
            // ani->move(sf::Vector2f(-0.05f, 0.05f));
            this->_movement.x -= this->movementSpeed;
            this->_movement.y += this->movementSpeed; //change to falling speed
            view->move(sf::Vector2f(-0.05f, 0.0f));
            view->setCenter(this->getPlayerX(ani), this->getPlayerY(ani));
        }else{
            //  ani->move(sf::Vector2f(-0.05f, 0.0f));
            this->_movement.x -= this->movementSpeed;
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        //right
        if(!isJumping && !landed){
            // ani->move(sf::Vector2f(0.05f, 0.05f));
            this->_movement.x += this->movementSpeed;
            this->_movement.y += this->movementSpeed; //change to jumping
        }else{
            //  ani->move(sf::Vector2f(0.05f, 0.0f));
             this->_movement.x += this->movementSpeed;
        }

    }

    if(!landed && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        // ani->move(sf::Vector2f(0.00f, 0.05f));
        this->_movement.y += this->movementSpeed; //change to jumping
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !this->isJumping && !falling)
    {
        if(this->lastJump.getElapsedTime().asSeconds() >= 0.5){
            isJumping = true;
            this->lastJump.restart();  
        }
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::U)){
        printf("X: %f\n", ani->getPosition().x);
        printf("Y: %f\n", ani->getPosition().y);
    }

    ani->move(this->_movement);
    view->move(this->movement);
    view->setCenter(ani->getPosition().x, ani->getPosition().y);
    // view->zoom(3.0f);
}

sf::Vector2f *Movement::getMovementVector(){
    return &this->movement;
}

void Movement::resetMovement(){
    this->movement.x = 0;
    this->movement.y = 0;
}