#include "Game.hpp"

Game::Game(){
    this->init();
    this->state = new ActiveState();
    this->state->win = this->window;
    // this->states.push(new ActiveState(this->window));
    // this->states.push(new ActiveState());
    printf("%ld %ld\n", this->window->getSize().x, this->window->getSize().y);
    // this->window->setKeyRepeatEnabled(false);
};

Game::~Game(){}


void Game::init(){
    printf("Creating Window and initializing Game object now\n");
    this->window = new sf::RenderWindow(sf::VideoMode(1024, 1024), "PF", sf::Style::Resize);
    // this->window = new sf::RenderWindow(sf::VideoMode(1024, 1024), "RPG", sf::Style::Fullscreen);
    // this->view = new sf::View(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1024.0f, 512.0f));
};


void Game::update(sf::Time dt){
    this->state->update(dt);
};

void Game::render(){
    this->window->clear();
    // this->states.top()->render(this->window);
    this->state->render(this->window);
    this->window->display();
};

void Game::run(){
    printf("Game running \n");
    sf::Clock frameClock;
    sf::Time frameTime;

    // lua_State* L = luaL_newstate();
    // luaL_loadfile(L, "Zones/constraints/zone1.lua");
    // lua_pcall(L, 0, 1, 0);
    // auto waterRef = luabridge::
    // lua_getglobal(L, "")
    while(this->window->isOpen()){
        sf::Event event;
        while(window->pollEvent(event)){
            if (event.type == sf::Event::Closed)
                this->window->close();
            switch (event.key.code)
            {
            case sf::Keyboard::Return:
                    if(this->isFull){
                        this->window->create(sf::VideoMode(1024, 1024), "PF", sf::Style::Default);
                        this->isFull = false;
                    }
                    else
                    {
                        this->window->create(sf::VideoMode(1024, 1024), "PF", sf::Style::Fullscreen);
                        this->isFull = true;
                    }
                    
                break;
            
            default:
                break;
            }
        }
        frameTime = frameClock.restart();
        // this->update();
        // this->render();
        // this->states.top()->update(frameTime);
        this->update(frameTime);
        this->render();
    }
}