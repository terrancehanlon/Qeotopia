#include "headers/Zone.hpp"


Zone::Zone(){

};

Zone::~Zone(){};


bool Zone::checkPlayerPlatformCollide(AnimatedSprite *player){
    sf::FloatRect coords = player->getGlobalBounds();
    // coords->top = coords->top - 5;
    sf::FloatRect cords = sf::FloatRect(player->getGlobalBounds().left, coords.top, player->getGlobalBounds().width, player->getGlobalBounds().height); //make it so this whole thing isnt executed during every loop
    for(int i = 0; i < this->platforms.size(); i++){
        if(this->platforms.at(i)->ani.getGlobalBounds().intersects(cords)){
            this->platformLoc[0] = this->platforms.at(i)->ani.getPosition().x;
            this->platformLoc[1] = this->platforms.at(i)->ani.getPosition().y;
            return true;
        }
    }
    return false;
};

bool Zone::checkPlayerConstraint(AnimatedSprite *player){
    return this->doors.at(0)->ani.getGlobalBounds().intersects(player->getGlobalBounds());
};
void Zone::update(sf::Time deltaTime, AnimatedSprite *player, Movement *move){
    if (this->checkPlayerConstraint(player)){
        this->doors.at(0)->open();
    }
    else{
        this->doors.at(0)->idle();
    }
    
    if(checkPlayerPlatformCollide(player)){
        //  printf("COLLIDE WITH PLATFORM\n"); 
         move->stop(player, this->platformLoc[0], this->platformLoc[1]);
    }
    else{
        // printf("Not colliding\n");
        move->landed = false;
    }
    this->doors.at(0)->update(deltaTime);
    for(int i = 0; i < this->platforms.size(); i++){
        platforms.at(i)->update(deltaTime);
    }

    for(int i = 0; i < this->pigs.size(); i++) {
        Pig *p = this->pigs.at(i);
        
        if(p->ani.getGlobalBounds().intersects(player->getGlobalBounds())){
            // printf("STAYING \n");
            p->stay();
            if(player->get_last_hit().asSeconds() > 2){
                player->hit(1);
                player->setColor(sf::Color::Red);
                // player->getCol
                printf("HIT For damage\n");
            }
            else{
                // player->setColor(sf::Color::White);
                // player->setColor(sf::Color::Transparent);
                // printf("NO DAMAGE\n");
            }
        }
        else if (p->ani.getPosition().x < player->getPosition().x){
            p->right();
            // printf("RIGHT");
        }
        else if(p->ani.getPosition().x > player->getPosition().x){
            p->left();
            // printf("LEFT\n");
        }
        p->update(deltaTime);
    }
};

void Zone::draw(sf::RenderWindow *window){
    window->draw(this->sprite);
    this->doors.at(0)->draw(window);
    for(int i = 0; i < this->platforms.size(); i++){
        this->platforms.at(i)->draw(window);
    }
    for(int i = 0; i < this->pigs.size(); i++){
        this->pigs.at(i)->draw(window);
    }
};
