/**
 * Class GameController
 * @author Patricio Ferreira <3dimentionar@gmail.com>
 * Copyright (c) 2017 nahuelio. All rights reserved.
 **/
#include "headers/GameController.h"

using namespace game_controller;

/** Constructors **/

GameController::GameController() {};

/** Members **/

GameController *GameController::_instance = 0;

/** Methods **/

GameController *GameController::instance() {
    if(!_instance) {
        _instance = new GameController();
    }
    return _instance;
}

Controller *GameController::run() {
    return this;
};