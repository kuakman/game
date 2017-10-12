/*
 * Class Main
 * @author Patricio Ferreira <3dimentionar@gmail.com>
 * Copyright (c) 2017 nahuelio. All rights reserved.
 */

#include <iostream>
#include <QApplication>
#include "headers/Main.h"
#include "headers/Game.h"
#include "view/main/headers/MainWindow.h"

using namespace game_main;
using namespace game_controller;

/*
 * Run
 */
int Main::run() {
    Game::instance()->get("Window")->run();
    Game::instance()->get("Sound")->run();
    Game::instance()->get("Game")->run()->terminate();
    return 0;
};

/*
 * Test using QT
 */
int Main::window() {
    MainWindow *window = new MainWindow();
    window->resize(1280, 960);
    window->show();
    return 0;
}

/*
 * Game Launch
 */
int main(int argc, char *argv[]) {
    Q_INIT_RESOURCE(application);
    QApplication app(argc, argv);
    QCoreApplication::setOrganizationName("Nahuel IO");
    QCoreApplication::setApplicationName("Game Application");
    QCoreApplication::setApplicationVersion(QT_VERSION_STR);

    Main *main = new Main();
    main->window();
    return app.exec();
    //return main->run();
};