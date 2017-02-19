/*
 * Interface Controller
 * @author Patricio Ferreira <3dimentionar@gmail.com>
 * Copyright (c) 2017 nahuelio. All rights reserved.
 */

#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include <string>

namespace game_controller {

    class Controller {
        public:
            Controller();

            virtual void run();
    };

};


#endif //GAME_CONTROLLER_H
