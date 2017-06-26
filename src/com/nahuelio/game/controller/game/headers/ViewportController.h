/**
 * Interface ViewportController
 * @author Patricio Ferreira <3dimentionar@gmail.com>
 * Copyright (c) 2017 nahuelio. All rights reserved.
 **/

#ifndef GAME_VIEWPORTCONTROLLER_H
#define GAME_VIEWPORTCONTROLLER_H

#include "../../headers/Controller.h"
#include "glad.h"

namespace game_controller {

    class ViewportController : public Controller {

        static ViewportController *_instance;

        public:
            ViewportController();
            static ViewportController *instance();

            ViewportController *setViewport(int x, int y, GLuint width, GLuint height);
            virtual Controller *run();
    };

}

#endif //GAME_VIEWPORTCONTROLLER_H
