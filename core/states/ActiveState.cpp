#include "headers/ActiveState.hpp"
#include <iostream>

ActiveState::ActiveState(){
    this->player = new Entity();
    this->movementComp = new Movement(0.055f);
    ZoneOne* z1 = new ZoneOne();
    z1->win = this->win;
    this->zones.push_back(z1);
    this->zones.at(0)->win = this->win;
    this->player->ani.setPosition(sf::Vector2f(0.79,359.03));

    this->healthBar = new HealthBar();
    this->healthcomp = new Health();

    //sf::View view;
    this->view = new sf::View();
    this->view->setCenter(this->getPlayerX(),this->getPlayerY());
    this->view->zoom(0.65f);

    //view.reset(sf::FloatRect(100,100,400,200));
    //this->win->setView(view);

    //this->wwi

    
};

float ActiveState::getPlayerX(){
    return this->player->ani.getPosition().x;
}

float ActiveState::getPlayerY(){
    return this->player->ani.getPosition().y;
}

void ActiveState::update(sf::Time dt){
    this->movementComp->move(dt, &this->player->ani, this->view);
    this->healthcomp->updateHealth(&this->player->ani);
    this->healthBar->update(dt, this->healthcomp);
    this->player->update(dt);
    this->zones.at(0)->update(dt, &this->player->ani, this->movementComp);

};
//change function names to match draw to render or render to draw
void ActiveState::render(sf::RenderWindow *win){
    win->setView(*this->view);
    this->zones.at(0)->draw(win);
    this->player->render(win);      
    this->healthBar->draw(win);
};
