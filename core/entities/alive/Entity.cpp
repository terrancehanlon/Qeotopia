#include "headers/Entity.hpp"

Entity::Entity(){
    // this->ani = *new AnimatedSprite();
    this->movementSpeed = 1.0f;
    this->movementComp = new Movement(this->movementSpeed);
    this->run_text.loadFromFile("Assets/Sprites/King_Human/Run.png");
    
    // sf::IntRect rectSourceSprite(300, 0, 300, 400);
    // this->sprite = new Sprite(this->text, rectSourceSprite);
    this->anim.setSpriteSheet(this->run_text);
    this->anim.addFrame(sf::IntRect(9, 18, 37, 25));
    this->anim.addFrame(sf::IntRect(87, 16, 37, 26));
    this->anim.addFrame(sf::IntRect(165, 17, 37, 26));
    this->anim.addFrame(sf::IntRect(243, 20, 37, 25));
    this->anim.addFrame(sf::IntRect(321, 18, 37, 25));
    // anim.addFrame(sf::IntRect(388, 16, 37, 26)); //this one triggers the off screen
    this->anim.addFrame(sf::IntRect(477, 17, 37, 26));
    this->anim.addFrame(sf::IntRect(555, 20, 37, 25));

    this->attack_text.loadFromFile("Assets/Sprites/King_Human/Attack.png");
    this->attack.setSpriteSheet(this->attack_text);
    this->attack.addFrame(sf::IntRect(20, 0, 59, 58));
    this->attack.addFrame(sf::IntRect(100, 0, 50, 58));
    this->attack.addFrame(sf::IntRect(165, 16, 37, 28));

    this->ani.setAnimation(this->anim);
    this->ani.play(this->anim);

    this->current_animation = &this->anim;
    
};

void Entity::swing(){
    this->current_animation = &this->attack;
};

void Entity::run(){
    // ani.setAnimation(this->anim);
    this->current_animation = &this->anim;

};
void Entity::update(sf::Time deltaTime){
    this->ani.play(*this->current_animation);
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