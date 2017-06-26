/**
 * Class WindowController
 * @author Patricio Ferreira <3dimentionar@gmail.com>
 * Copyright (c) 2017 nahuelio. All rights reserved.
 **/
#include "headers/WindowController.h"

using namespace game_controller;
using namespace game_model;

/** Constructors **/

WindowController::WindowController() {};

/** Members **/

WindowController *WindowController::_instance = 0;

Screen *WindowController::screen = new Screen();

WindowController *WindowController::instance() {
    if(!_instance) {
        _instance = new WindowController();
    }
    return _instance;
};

/** Getters & Setters **/

Screen *WindowController::getScreen() {
    return screen;
};

/** Methods **/

WindowController *WindowController::initialize() {
    if(!glfwInit()) this->onGLFWError("GLFW couldn't initialized.");

    glfwSetErrorCallback(this->onError);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, screen->CTX_MAJOR);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, screen->CTX_MINOR);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    screen->window = glfwCreateWindow(screen->HD_WIDTH, screen->HD_HEIGHT, screen->TITLE, NULL, NULL);

    if(!screen->window) this->onGLFWError("Failed to create GLFWwindow");

    glfwMakeContextCurrent(screen->window);

    return this;
};

WindowController *WindowController::GLLoader() {
    if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) this->onGLFWError("GLAD couldn't bind OpenGL ProcAddress");
    return this;
};

Controller *WindowController::run() {
    return this->initialize()->GLLoader();
};
