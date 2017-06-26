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
        static const GLuint WIDTH;
        static const GLuint HEIGHT;
        static const char* TITLE;

        static GLFWwindow *window;

        Screen();

        //void getWindowContext();
    };

}

#endif //GAME_SCREEN_H
