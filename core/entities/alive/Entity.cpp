#include "headers/Entity.hpp"

Entity::Entity(){
    // this->ani = *new AnimatedSprite();
    this->movementSpeed = 1.0f;
    this->movementComp = new Movement(this->movementSpeed);
    text.loadFromFile("Assets/Sprites/King_Human/Run.png");
    // sf::IntRect rectSourceSprite(300, 0, 300, 400);
    // this->sprite = new Sprite(this->text, rectSourceSprite);
    anim.setSpriteSheet(text);
    anim.addFrame(sf::IntRect(9, 18, 37, 25));
    anim.addFrame(sf::IntRect(87, 16, 37, 26));
    anim.addFrame(sf::IntRect(165, 17, 37, 26));
    anim.addFrame(sf::IntRect(243, 20, 37, 25));
    anim.addFrame(sf::IntRect(321, 18, 37, 25));
    // anim.addFrame(sf::IntRect(388, 16, 37, 26)); //this one triggers the off screen
    anim.addFrame(sf::IntRect(477, 17, 37, 26));
    anim.addFrame(sf::IntRect(555, 20, 37, 25));

    ani.setAnimation(this->anim);
    ani.play(anim);
    
};

void Entity::update(sf::Time deltaTime){
    if(this->ani.get_last_hit().asSeconds() >= 0.5){
        this->ani.setColor(sf::Color::White);
    }
    this->ani.update(deltaTime);
    /*  this function updates the animation of the sprite
        all the movement functionality is done within Movement.h this is how to follow a more "composition over inheritance" ideology
        the ActiveState.h is what utilizes the Movement.h functions.
    */
}


void Entity::render(sf::RenderWindow *window){
    window->draw(this->ani);
}