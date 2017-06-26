/**
 * Interface SoundController
 * @author Patricio Ferreira <3dimentionar@gmail.com>
 * Copyright (c) 2017 nahuelio. All rights reserved.
 **/

#ifndef GAME_SOUNDCONTROLLER_H
#define GAME_SOUNDCONTROLLER_H

#include "Controller.h"

namespace game_controller {

    class SoundController : public Controller {

        static SoundController *_instance;

        public:
            SoundController();
            static SoundController *instance();

            virtual Controller *run();
    };

}

#endif //GAME_SOUNDCONTROLLER_H
