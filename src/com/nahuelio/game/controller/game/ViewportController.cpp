/**
 * Class ViewportController
 * @author Patricio Ferreira <3dimentionar@gmail.com>
 * Copyright (c) 2017 nahuelio. All rights reserved.
 **/
#include "headers/ViewportController.h"

using namespace game_controller;

/** Constructors **/

ViewportController::ViewportController() {};

/** Members **/

ViewportController *ViewportController::_instance = 0;

/** Methods **/

ViewportController *ViewportController::instance() {
    if(!_instance) _instance = new ViewportController();
    return _instance;
};

ViewportController *ViewportController::setViewport(int x, int y, GLuint width, GLuint height) {
    glViewport(x, y, width, height);
    return this;
}

Controller *ViewportController::run() {
    return this;
};