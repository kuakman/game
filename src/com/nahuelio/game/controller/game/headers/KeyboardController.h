/**
 * Interface KeyboardController
 * @author Patricio Ferreira <3dimentionar@gmail.com>
 * Copyright (c) 2017 nahuelio. All rights reserved.
 **/
#ifndef GAME_KEYBOARDCONTROLLER_H
#define GAME_KEYBOARDCONTROLLER_H

#include "../../headers/Controller.h"

namespace game_controller {

    class KeyboardController : public Controller {

        static KeyboardController *_instance;

        protected:
            static void onKeyEscape(GLFWwindow *window, int key, int scancode, int action, int mode);

        public:
            KeyboardController();
            static KeyboardController *instance();

            virtual KeyboardController *addKeyHandler(GLFWkeyfun handler);
            virtual Controller *run();
    };

}


#endif //GAME_KEYBOARDCONTROLLER_H
