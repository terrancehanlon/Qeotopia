#ifndef PIG_H
#define PIG_H


#include "../../structural/headers/Door.hpp"

class Pig {
    private:

    public:
        AnimatedSprite ani;
        Animation anim_run;
        sf::Texture texture;

        Pig(float x, float y);
        ~Pig();

        void draw(sf::RenderWindow *window);
        void update(sf::Time dt);

        int direction = 0;

        void left();
        void right();
        void stay();

        void move();
};


#endif