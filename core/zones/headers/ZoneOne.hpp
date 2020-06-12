#ifndef ZONEONE_H
#define ZONEONE_H

#include "Zone.hpp"

class ZoneOne : public Zone {

    private:
        // sf::Texture texture;
        // sf::Sprite sprite;
        bool onScreen = false;

    public:
        bool coolDown = false;
        ZoneOne();
        ~ZoneOne();
        // Door *door;
        // void update(sf::Time deltaTime, AnimatedSprite *player, Movement *move);
        // void draw(sf::RenderWindow *window);
        // std::vector<Pig*> pigs;
        // std::vector<Platform*> platforms;
        
        //checks if player is walking over restricted coords given from lua file
        // bool checkPlayerConstraint(AnimatedSprite *player);
        // bool checkPlayerPlatformCollide(AnimatedSprite *player);


        // float platformLoc[2]; //coords of the platform that the player collids with
};

#endif