/*
 * Class Main
 * @author Patricio Ferreira <3dimentionar@gmail.com>
 * Copyright (c) 2017 nahuelio. All rights reserved.
 */

#include <iostream>
#include "headers/Main.h"
#include "headers/Game.h"

using namespace game_main;
using namespace game_controller;

/*
 * Run
 */
int Main::run() {
    Game::instance()->get("Game")->run();
    Game::instance()->get("Sound")->run();
    return 0;
}

/*
 * Game Launch
 */
int main() {
    Main *main = new Main();
    return main->run();
}