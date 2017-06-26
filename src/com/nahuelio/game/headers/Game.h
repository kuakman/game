/*
 * Interface Game
 * @author Patricio Ferreira <3dimentionar@gmail.com>
 * Copyright (c) 2017 nahuelio. All rights reserved.
 */

#ifndef GAME_MAINCONTROLLER_H
#define GAME_MAINCONTROLLER_H

#include <string>
#include <map>
#include "../controller/headers/Controller.h"

namespace game_controller {

    /*
     * Class Game
     */
    class Game {

        static std::map<std::string, Controller*> _factory;
        static Game *_instance;

        public:
            Game();
            static Controller* get(std::string name);
            static Game* instance();

    };

}

#endif //GAME_MAINCONTROLLER_H