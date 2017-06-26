/**
 * Class GameController
 * @author Patricio Ferreira <3dimentionar@gmail.com>
 * Copyright (c) 2017 nahuelio. All rights reserved.
 **/
#include "headers/GameController.h"
#include "headers/WindowController.h"
#include "game/headers/ViewportController.h"
#include "game/headers/KeyboardController.h"
#include "../headers/Game.h"

using namespace game_controller;

/** Constructors **/

GameController::GameController() {};

/** Members **/

GameController *GameController::_instance = 0;

/** Methods **/

GameController *GameController::instance() {
    if(!_instance) _instance = new GameController();
    return _instance;
};

GameController *GameController::initialize() {
    Screen *screen = ((WindowController *) Game::instance()->get("Window"))->getScreen();
    ((ViewportController *) Game::instance()->get("Viewport"))
            ->setViewport(screen->CTX_X, screen->CTX_Y, screen->WIDTH, screen->HEIGHT);
    return this;
};

GameController *GameController::bindings() {
    ((KeyboardController *) Game::instance()->get("Keyboard"))->run();
    return this;
};

GameController *GameController::start() {
    Screen *screen = ((WindowController *) Game::instance()->get("Window"))->getScreen();
    while(!glfwWindowShouldClose(screen->window)) {
        glfwPollEvents();

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Time to learn:
        // - Vertex Array Buffers
        // - Vertex Shader (Basic Shader) for 2D shapes
        // - Fragment Shaders
        // - Glad 3D Loaders & Textures

        glfwSwapBuffers(screen->window);
    }
    this->terminate();
    return this;
};

Controller *GameController::run() {
    return (Controller *) this->initialize()->bindings()->start();
};