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
        Pig* pig = this->pigs.at(i);

        if(pig->is_dead){
            this->pigs.erase(this->pigs.begin() + (i));
            continue;
        }
        
        if(pig->ani.getGlobalBounds().intersects(player->getGlobalBounds())){
            pig->stay();
            if(pig->did_hit){ //pig collided with player
                if(player->get_last_hit().asSeconds() > 0.5f){
                    if(pig->last_collide.getElapsedTime().asSeconds() > this->hit_cooldown){
                        //if the pigs attack cooldown is up
                        //if the pig has sat long enough on the player to trigger damage
                        player->hit(1);
                        player->setColor(sf::Color::Red);
                        printf("HIT For damage\n");
                    }
                }
                else{
                    // player->setColor(sf::Color::White);
                    // player->setColor(sf::Color::Transparent);
                    // printf("NO DAMAGE\n");  
                }
            }
            else{
                pig->set_clock(true);
            }
            if(player->is_attacking){
                if(pig->last_struck.getElapsedTime().asSeconds() < 1.0){
                    // pig->ani.setColor(sf::Color::White);
                    // pig->ani.hit(1); //here could set damage
                }else{
                    pig->set_clock(false); //false to set pig GOT hit flag
                    pig->ani.hit(1);
                    pig->ani.setColor(sf::Color::Red);
                }
            }
        }
        else if (pig->ani.getPosition().x < player->getPosition().x){
            pig->right();
            pig->did_hit = false;
            // printf("RIGHT");
        }
        else if(pig->ani.getPosition().x > player->getPosition().x){
            pig->left();
            pig->did_hit = false;
            // printf("LEFT\n");
        }
        pig->update(deltaTime);
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
