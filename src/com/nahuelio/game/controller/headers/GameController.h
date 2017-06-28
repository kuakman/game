/**
 * Interface GameController
 * @author Patricio Ferreira <3dimentionar@gmail.com>
 * Copyright (c) 2017 nahuelio. All rights reserved.
 **/

#ifndef GAME_GAMECONTROLLER_H
#define GAME_GAMECONTROLLER_H

#include "Controller.h"

namespace game_controller {

    class GameController : public Controller {

        static GameController *_instance;

        public:
            GameController();

            virtual GameController *initialize();
            virtual GameController *bindings();
            virtual GameController *loadShaders();
            virtual GameController *start();
            virtual Controller *run();

            static GameController *instance();
    };

}

#endif //GAME_GAMECONTROLLER_H
