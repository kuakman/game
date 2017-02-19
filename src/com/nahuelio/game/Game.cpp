/*
 * Class Game
 * @author Patricio Ferreira <3dimentionar@gmail.com>
 * Copyright (c) 2017 nahuelio. All rights reserved.
 */

#include "headers/Game.h"
#include "controller/headers/GameController.h"
#include "controller/headers/SoundController.h"

#include <boost/assign.hpp>

using namespace game_controller;

/** Constructors **/

Game::Game() {}

/** Members **/

Game *Game::_instance = 0;

std::map<std::string, void*> Game::_factory =
        boost::assign::map_list_of("Game", new GameController()) ("Sound", new SoundController());

/** Methods **/

Game *Game::instance() {
    if(!_instance) {
        _instance = new Game();
    }
    return _instance;
}

Controller *Game::get(std::string name) {
    return (Controller*) _factory.at(name);
}