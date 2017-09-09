/**
 * Class Controller
 * @author Patricio Ferreira <3dimentionar@gmail.com>
 * Copyright (c) 2017 nahuelio. All rights reserved.
 **/
#include <iostream>
#include "headers/Controller.h"

#include <GLFW/glfw3.h>

using namespace game_controller;

Controller::Controller() {};

void Controller::onError(int error, const char *desc) {
    std::cout << printf("Error %d: %s", error, desc);
    return;
};

void Controller::onGLFWError(const char *desc) {
    printf("GLFW Error: %s", desc);
    glfwTerminate();
    return;
};

Controller *Controller::run() { return this; }

void Controller::terminate() {
    glfwTerminate();
    return;
};