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
    this->doors.push_back(new Door(907.0, 258.03));

    this->platforms.push_back(new Platform(1050, 245));
    this->platforms.push_back(new Platform(2075, 225));
    
    Pig *pig1 = new Pig(150, 285.03);
    Pig *pig2 = new Pig(360, 285.03);
    Pig *pig3 = new Pig(170, 285.03);
    Pig *pig4 = new Pig(880, 285.03);
    Pig *pig5 = new Pig(1190, 285.03);
    pig1->left();

    this->pigs.push_back(pig1);
    this->pigs.push_back(pig2);
    this->pigs.push_back(pig3);
    this->pigs.push_back(pig4);
    this->pigs.push_back(pig5);

    // this->door->idle();
}


ZoneOne::~ZoneOne(){
    delete &this->sprite;
    delete &this->texture;
};
