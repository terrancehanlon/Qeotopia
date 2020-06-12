#include "headers/Platform.hpp"

Platform::Platform(float x, float y){
    this->ani.setPosition(sf::Vector2f(x,y));
    this->texture.loadFromFile("Assets/Sprites/platforms/platforms.png");
    this->anim.setSpriteSheet(this->texture);
    this->anim.addFrame(sf::IntRect(62, 62, 248, 30));
    this->ani.setScale(0.5, 0.5);
    this->ani.setAnimation(this->anim);

    this->ani.play(this->anim);
};

Platform::~Platform(){};


void Platform::update(sf::Time dt){
    this->ani.update(dt);
};

void Platform::draw(sf::RenderWindow *window){
    window->draw(this->ani);
}