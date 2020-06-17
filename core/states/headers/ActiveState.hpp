#ifndef ACTIVE_STATE
#define ACTIVE_STATE

// #include "State.h"
#include "../../entities/alive/headers/Entity.hpp"
#include <string>
#include <stack>
#include "../../zones/headers/ZoneOne.hpp"
#include "../../components/headers/Ability.hpp"
class ActiveState {

    public:

        //player instance
        Entity *player;
        HealthBar *healthBar;
        // lua_State *L;
        // std::stack<Zone*> zones;
        ActiveState();
        Movement *movementComp;
        Health *healthcomp;
        Ability *abilityComp;
        
        std::vector<Zone*> zones;
        sf::View *view;

        sf::Vector2f tmp;

        float getPlayerX();
        float getPlayerY();

        // int getIntField(lua_State *L, const char* key);
        // std::string getStringField(lua_State *L, const char* key);
        // sf::View *view;
        // sf::View *resource_view;
        sf::RenderWindow *win;


        void update(sf::Time dt);
        void render(sf::RenderWindow *win);

};

#endif