/**
 * Class Screen
 * @author Patricio Ferreira <3dimentionar@gmail.com>
 * Copyright (c) 2017 nahuelio. All rights reserved.
 **/

#include "headers/Screen.h"

using namespace game_model;

Screen::Screen() {};

const int Screen::CTX_MAJOR = 3;
const int Screen::CTX_MINOR = 2;

const GLuint Screen::WIDTH = 1280;
const GLuint Screen::HEIGHT = 1024;

const char* Screen::TITLE = "Game @nahuelio";

GLFWwindow *Screen::window = 0;