#ifndef HEALTH_H
#define HEALTH_H

// #include "../../../../Lib/Imports.hpp"
// #include "../../Lib/Imports.hpp"
// #include "/home/terrance/Desktop/games/pf/Lib/Imports.hpp"
#include "../../../Lib/Imports.hpp"
class Health {
    private:
        int self;
    public:
        int max_health = 3;
        int current_health;

        int getHealth(AnimatedSprite *ani);
        void setHealth(AnimatedSprite *ani, int health);
        void updateHealth(AnimatedSprite *ani);

        Health();
};

#endif