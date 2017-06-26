/*
 * Class SoundController
 * @author Patricio Ferreira <3dimentionar@gmail.com>
 * Copyright (c) 2017 nahuelio. All rights reserved.
 */
#include <iostream>
#include "headers/SoundController.h"

using namespace game_controller;

/** Constructors **/

SoundController::SoundController() {};

/** Members **/

SoundController *SoundController::_instance = 0;

/** Methods **/

SoundController *SoundController::instance() {
    if(!_instance) {
        _instance = new SoundController();
    }
    return _instance;
}

Controller *SoundController::run() {
    std::cout << "TODO: SoundController.run()" << std::endl;
    return this;
};
