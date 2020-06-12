#ifndef HEALTHBAR_H
#define HEALTHBAR_H

#include "../../../components/headers/Health.hpp"

class HealthBar {

    private:


    public:
        AnimatedSprite ani;
        Animation anim_1_heart;
        Animation anim_2_heart;
        Animation anim_3_heart;

        sf::Texture texture;
        
        HealthBar();

        void update(sf::Time dt, Health *healthcomp);
        void draw(sf::RenderWindow *window);    

};


#endif