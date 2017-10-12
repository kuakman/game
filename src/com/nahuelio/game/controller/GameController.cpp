/**
 * Class GameController
 * @author Patricio Ferreira <3dimentionar@gmail.com>
 * Copyright (c) 2017 nahuelio. All rights reserved.
 **/
#include <iostream>
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
    this->shaderController = ((ShaderController *) Game::instance()->get("Shader"));

    ((ViewportController *) Game::instance()->get("Viewport"))
            ->setViewport(screen->CTX_X, screen->CTX_Y, screen->HD_WIDTH, screen->HD_HEIGHT);
    return this;
};

GameController *GameController::bindings() {
    ((KeyboardController *) Game::instance()->get("Keyboard"))->run();
    return this;
};

GameController *GameController::loadShaders() {
    this->shaderController->load("VertexShader", GL_VERTEX_SHADER);
    this->shaderController->load("FragmentShader", GL_FRAGMENT_SHADER);
    return this;
};

GameController *GameController::start() {
    Screen *screen = ((WindowController *) Game::instance()->get("Window"))->getScreen();
    unsigned int program = this->shaderController->getProgramWith();

    // Terminology:
    // VBO: vertex buffer objects
    // VAO: vertex attribute objects
    // EBO: element buffer objets

    unsigned int vbo, vao;
    float vertices[] = {
            -0.9f, -0.9f, 0.0f,
            0.0f, 0.9f, 0.0f,
            0.9f, -0.9f, 0.0f
    };

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);

    // VBO -> Creates Buffer and puts the vertices inside the GPU
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindVertexArray(vao);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    while(!glfwWindowShouldClose(screen->window)) {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(program);
        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(screen->window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);

    this->terminate();
    return this;
};

Controller *GameController::run() {
    printf("OpenGL Version: [%s]\n", glGetString(GL_VERSION));
    return (Controller *) this->initialize()->bindings()->loadShaders()->start();
}