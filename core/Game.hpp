
#ifndef GAME_H
#define GAME_H


#include "states/headers/ActiveState.hpp"


class Game {

    public:

        sf::RenderWindow *window;
        // std::stack<ActiveState*> states;

        // sf::View *view;

        ActiveState *state;

        Game();
        ~Game();
        
        void init();
        void update(sf::Time dt);
        void render();

        bool isFull = false;

        void run();




};

#endif