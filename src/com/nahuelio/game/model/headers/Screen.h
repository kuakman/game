/**
 * Interface Screen
 * @author Patricio Ferreira <3dimentionar@gmail.com>
 * Copyright (c) 2017 nahuelio. All rights reserved.
 **/

#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include "glad.h"
#include <glfw/glfw3.h>

namespace game_model {

    class Screen {

        public:
            static const int CTX_MAJOR;
            static const int CTX_MINOR;
            static const int CTX_X;
            static const int CTX_Y;

            static const GLuint HD_WIDTH;
            static const GLuint HD_HEIGHT;

            static const GLuint FULLHD_WIDTH;
            static const GLuint FULLHD_HEIGHT;

            static const char* TITLE;
            static GLFWwindow *window;

            Screen();
    };

}

#endif //GAME_SCREEN_H
