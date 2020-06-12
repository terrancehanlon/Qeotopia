#include "headers/Door.hpp"

Door::Door(float x, float y){
    texture.loadFromFile("Assets/Sprites/Door/Doors.png");

    //set close
    anim_close.setSpriteSheet(texture);

    anim_close.addFrame(sf::IntRect(0, 2, 40, 47));
    anim_close.addFrame(sf::IntRect(121, 2, 40, 47));
    anim_close.addFrame(sf::IntRect(242, 2, 40, 47));
    // //maybe look into using a single animation object 
    // ani_close.setAnimation(anim_close).
    anim_open.setSpriteSheet(this->texture);
    anim_open.addFrame(sf::IntRect(242, 2, 40, 47));
    anim_open.addFrame(sf::IntRect(121, 2, 40, 47));
    anim_open.addFrame(sf::IntRect(0, 2, 40, 47));
    // // ani.pen->setAnimation(*anim_open);

    anim_idle.setSpriteSheet(this->texture);
    anim_idle.addFrame(sf::IntRect(242, 2, 40, 47));
    // ani_idle->setAnimation(*anim_idle);

    // ani.setPosition(sf::Vector2f(x,y));
    // ani_open->setPosition(sf::Vector2f(x,y));
    // ani_close->setPosition(sf::Vector2f(x,y));
    ani.setPosition(sf::Vector2f(x,y));
    ani.setAnimation(this->anim_close);
    ani.play(this->anim_close);
};

Door::~Door(){
    delete &ani;
    delete &anim_close;
    delete &anim_idle;
    delete &anim_open;
};

void Door::draw(sf::RenderWindow *window){
        window->draw(this->ani);

};

void Door::update(sf::Time dt){
    this->ani.update(dt);
};

void Door::close(){
    this->ani.play(this->anim_close);
}

void Door::open(){
    this->ani.play(this->anim_open);
}

void Door::idle(){
    this->ani.play(this->anim_idle);
}
