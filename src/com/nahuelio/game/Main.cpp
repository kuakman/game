/*
*	Class Main
*	@author Patricio Ferreira <3dimentionar@gmail.com>
*/

#include "headers/Main.h"
#include "headers/Game.h"

using namespace game_main;
using namespace game_controller;

/*
 * Bootstraps Game Controller
 */
Main *Main::bootstrap() {
    Game::instance()->get("controller");
    return this;
}

/*
 * Run
 */
int Main::run() {
    return 0;
}

/*
 * Game Launch
 */
int main() {
    Main *main = new Main();
	return main->bootstrap()->run();
}