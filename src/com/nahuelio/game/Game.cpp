/**
 * Class Game
 * @author Patricio Ferreira <3dimentionar@gmail.com>
 * Copyright (c) 2017 nahuelio. All rights reserved.
 **/
#include "headers/Game.h"
#include "controller/headers/WindowController.h"
#include "controller/headers/GameController.h"
#include "controller/game/headers/ViewportController.h"
#include "controller/game/headers/KeyboardController.h"
#include "controller/headers/SoundController.h"
#include <boost/assign.hpp>

using namespace game_controller;

/** Constructors **/

Game::Game() {};

/** Members **/

Game *Game::_instance = 0;

std::map<std::string, Controller*> Game::_factory =
        boost::assign::map_list_of<std::string, Controller*>
                ("Window", WindowController::instance())
                ("Viewport", ViewportController::instance())
                ("Keyboard", KeyboardController::instance())
                ("Shader", ShaderController::instance())
                ("Sound", SoundController::instance())
                ("Game", GameController::instance());

/** Methods **/

Game *Game::instance() {
    if(!_instance) {
        _instance = new Game();
    }
    return _instance;
};

Controller* Game::get(std::string name) {
    return _factory.at(name);
};