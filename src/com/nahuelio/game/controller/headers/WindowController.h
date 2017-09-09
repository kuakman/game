/**
* @author Patricio Ferreira <$Email>
* Copyright (c) 2017 nahuelio. All rights reserved.
**/

#ifndef GAME_WINDOWCONTROLLER_H
#define GAME_WINDOWCONTROLLER_H

#include "Controller.h"
#include "../../model/headers/Screen.h"
#include <GLFW/glfw3.h>

using namespace game_model;

namespace game_controller {

    class WindowController : public Controller {

        static WindowController *_instance;

        public:
            WindowController();
            static WindowController *instance();
            static Screen *screen;

            Screen *getScreen();

            virtual WindowController *GLLoader();
            virtual WindowController *initialize();
            virtual Controller *run();
    };

}

#endif //GAME_WINDOWCONTROLLER_H
