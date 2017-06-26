/**
 * Interface Controller
 * @author Patricio Ferreira <3dimentionar@gmail.com>
 * Copyright (c) 2017 nahuelio. All rights reserved.
 **/

#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include <string>

namespace game_controller {

    class Controller {

        protected:
            static void onError(int error, const char* desc);
            virtual void onGLFWError(const char* desc);

        public:
            Controller();

            virtual void terminate();
            virtual Controller *run();
    };

};


#endif //GAME_CONTROLLER_H
