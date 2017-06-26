/**
 * Class KeyboardController
 * @author Patricio Ferreira <3dimentionar@gmail.com>
 * Copyright (c) 2017 nahuelio. All rights reserved.
 **/
#include "../../headers/Game.h"
#include "../headers/WindowController.h"
#include "headers/KeyboardController.h"

using namespace game_controller;

/** Constructors **/

KeyboardController::KeyboardController() {};

/** Members **/

KeyboardController *KeyboardController::_instance = 0;

/** Methods **/

KeyboardController *KeyboardController::instance() {
    if(!_instance) _instance = new KeyboardController();
    return _instance;
};

void KeyboardController::onKeyEscape(GLFWwindow *window, int key, int scancode, int action, int mode) {
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
    return;
};

KeyboardController *KeyboardController::addKeyHandler(GLFWkeyfun handler) {
    Screen *screen = ((WindowController *) Game::instance()->get("Window"))->getScreen();
    glfwSetKeyCallback(screen->window, handler);
    return this;
};

Controller *KeyboardController::run() {
    this->addKeyHandler(this->onKeyEscape); // Exit
    return this;
};
