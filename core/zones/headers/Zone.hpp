#ifndef ZONE_H
#define ZONE_H
#include "vector"
// #include "Movement.hpp" //possible double 
// #include "Lib/Imports.hpp"
#include "../../components/headers/Movement.hpp"
class Zone{

    private:


    public:
        sf::Texture texture;
        sf::Sprite sprite;
        bool coolDown = false;
        Zone();
        ~Zone();
        sf::RenderWindow *win;
        // sf::View view;
        void update(sf::Time deltaTime, AnimatedSprite *player, Movement *move);
        void draw(sf::RenderWindow *window);
        std::vector<Door*> doors;
        std::vector<Pig*> pigs;
        std::vector<Platform*> platforms;
        bool checkPlayerConstraint(AnimatedSprite *player);
        bool checkPlayerPlatformCollide(AnimatedSprite *player);


        float platformLoc[2]; //coords of the platform that the player collids with
};

#endif