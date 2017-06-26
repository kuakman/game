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
            static GameController *instance();

            virtual GameController *initialize();
            virtual GameController *bindings();
            virtual GameController *start();
            virtual Controller *run();
    };

}

#endif //GAME_GAMECONTROLLER_H
