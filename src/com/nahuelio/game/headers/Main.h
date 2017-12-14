/*
*	Interface Main
*	@author Patricio Ferreira <3dimentionar@gmail.com>
*/

#ifndef GAME_MAIN_H
#define GAME_MAIN_H

#include <QGuiApplication>

namespace game_main {

    class Main {

        protected:
            QGuiApplication* app;
            QQmlApplicationEngine* engine;

        public:
            Main(QGuiApplication* app);
            int run(int argc, char *argv []);

    };

}

#endif //GAME_MAIN_H
