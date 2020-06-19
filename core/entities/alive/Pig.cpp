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
    this->ani.set_health(3);
    printf("Creating pig\n");
};

Pig::~Pig(){
}; //do this when we need to advanced to the other zone or when they get killed or no longer needed


void Pig::update(sf::Time dt){
    if(this->last_struck.getElapsedTime().asSeconds() >= 0.5){
        this->ani.setColor(sf::Color::White);
    }
    this->move();
    this->ani.update(dt);

    if(this->ani.get_current_health() <= 0){
        this->is_dead = true;
    }
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
};

void Pig::set_clock(bool is_colliding){
    if(is_colliding){
        this->did_hit = true;
        this->last_collide = sf::Clock();
    }
    else{
        this->last_struck = sf::Clock();
    }
};


