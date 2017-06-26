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

const int Screen::CTX_X = 0;
const int Screen::CTX_Y = 0;

// HD
const GLuint Screen::HD_WIDTH = 1280;
const GLuint Screen::HD_HEIGHT = 720;

// Full HD
const GLuint Screen::FULLHD_WIDTH = 1920;
const GLuint Screen::FULLHD_HEIGHT = 1080;

const char* Screen::TITLE = "Game @nahuelio";

GLFWwindow *Screen::window = 0;