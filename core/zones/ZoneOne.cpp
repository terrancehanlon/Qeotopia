#include "headers/ZoneOne.hpp"

ZoneOne::ZoneOne(){
    this->texture.loadFromFile("Assets/Sprites/z1_big.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(sf::Vector2f(0.0,0.0));
    float d_width = this->sprite.getLocalBounds().width;
    float d_height = sf::VideoMode::getDesktopMode().height 
                        / this->sprite.getLocalBounds().height;
    // 5 / sf::VideoMode::height;
    // sf::VideoMode::height
    // this->sprite.scale(sf::Vector2f(this->win->getSize().x / this->sprite.getLocalBounds().width,   this->win->getSize().y / this->sprite.getLocalBounds().height  ));
    // this->sprite.set

    
    // sf::View view;

    // view.reset(sf::FloatRect(100,100,400,200));
    // view.setCenter(0,0);
    // this->win->setView(view);
    this->doors.push_back(new Door(907.0, 336.02));

    this->platforms.push_back(new Platform(50, 315));
    this->platforms.push_back(new Platform(350, 260));
    
    Pig *pig1 = new Pig(150, 360);
    pig1->left();

    this->pigs.push_back(pig1);

    // this->door->idle();
}


ZoneOne::~ZoneOne(){
    delete &this->sprite;
    delete &this->texture;
};
