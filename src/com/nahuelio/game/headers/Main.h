/*
*	Interface Main
*	@author Patricio Ferreira <3dimentionar@gmail.com>
*/

#ifndef GAME_MAIN_H
#define GAME_MAIN_H

namespace game_main {

    class Main {

        protected:
            int id;

        public:
            Main *bootstrap();
            int run();

    };

}

#endif //GAME_MAIN_H
