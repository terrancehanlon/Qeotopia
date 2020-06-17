//need to make an ability class that handles the abilities then I can pass entity into the ability class from the activestate class to avoid circular dependencies

#ifndef ABILITY_H
#define ABILITY_H
#include "../../entities/alive/headers/Entity.hpp"

class Ability 
{
    public:
        Ability();

        void check(Entity *e);

    private:
};

#endif