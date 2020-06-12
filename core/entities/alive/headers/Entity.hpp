#ifndef ENTITY_H
#define ENTITY_H

#include "../../../components/headers/Movement.hpp"

class Entity
{
    private:
        Movement *movementComp;


    public:
        // sf::View *view;
        sf::Vector2f movement;
        float movementSpeed;
        // sf::Sprite *sprite;
        Entity();
        AnimatedSprite ani;
        Animation anim;
        sf::Texture text;

        void update(sf::Time deltaTime);
        void render(sf::RenderWindow *window);

        int maxHealth = 3;
        int currentHealth = 3;


};

#endif
