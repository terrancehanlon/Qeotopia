#ifndef DOOR_H
#define DOOR_H

// #Include "ZoneOne.hpp"
// #include "../UI/headers/HealthBar.hpp"
#include "../../UI/headers/HealthBar.hpp"
// #include "/home/terrance/Desktop/games/pf/Lib/Imports.hpp"
class Door {

    private:
        // AnimatedSprite *ani_close;
        // AnimatedSprite *ani_idle;
        Animation anim_open;
        Animation anim_close;
        Animation anim_idle;
        sf::Texture texture;


    public:
        AnimatedSprite ani;
        Door(float x, float y);
        ~Door();

        HealthBar *bar;
        void open();
        void close();
        void idle();
        void update(sf::Time dt);
        void draw(sf::RenderWindow *window); 




};  

#endif