/*
*	Interface Game
*	@author Patricio Ferreira <3dimentionar@gmail.com>
*/

#ifndef GAME_MAINCONTROLLER_H
#define GAME_MAINCONTROLLER_H

#include <string>

namespace game_controller {

    /*
     * Facade references
     */
    typedef union {

    } GameFacade;

    /*
     * Singleton Game Facade
     */
    class Game {

        static Game *_instance;
        Game();

        public:
            static void get(std::string name);
            static Game *instance();

    };

}

#endif //GAME_MAINCONTROLLER_H