#include "headers/Pig.hpp"

Pig::Pig(float x, float y){
    
    this->texture.loadFromFile("Assets/Sprites/Pig/Run.png");
    this->anim_run.setSpriteSheet(this->texture);
    anim_run.addFrame(sf::IntRect(10, 10, 19, 15));
    anim_run.addFrame(sf::IntRect(44, 10, 19, 15));
    anim_run.addFrame(sf::IntRect(79, 11, 18, 17));
    anim_run.addFrame(sf::IntRect(113, 10, 18, 16));
    anim_run.addFrame(sf::IntRect(147, 10, 18, 17));
    anim_run.addFrame(sf::IntRect(181, 11, 18, 17));

    this->ani.setPosition(sf::Vector2f(x, y)); 
    this->ani.setAnimation(this->anim_run);

    this->ani.play(this->anim_run);
    printf("Creating pig\n");
};

Pig::~Pig(){}; //do this when we need to advanced to the other zone or when they get killed or no longer needed


void Pig::update(sf::Time dt){
    this->move();
    this->ani.update(dt);
};

void Pig::draw(sf::RenderWindow *window){
    window->draw(this->ani);
};

void Pig::stay(){
    this->direction = 0;
    this->move();
};

void Pig::left(){
    this->direction = -1;
    this->move();
};

void Pig::right(){
    this->direction = 1;
    this->move();
};


void Pig::move(){
    if(this->direction == 1){
        this->ani.move(sf::Vector2f(0.005f, 0.0f));
    }
    else if(this->direction == -1){
        this->ani.move(sf::Vector2f(-0.005f, 0.0f));
    }
    else{
        //do nothing
    }
}
