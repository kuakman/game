/*
*	Class Game
*	@author Patricio Ferreira <3dimentionar@gmail.com>
*/

#include <iostream>
#include "headers/Game.h"

using namespace game_controller;

Game::Game() {}

Game *Game::_instance = 0;

Game *Game::instance() {
    if(!_instance) {
        _instance = new Game;
    }
    return _instance;
}

void Game::get(std::string name) {
    std::cout << "TODO " << name << std::endl;
}