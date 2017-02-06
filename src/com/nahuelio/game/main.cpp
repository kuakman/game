/*
*	Class Main
*	@author Patricio Ferreira <3dimentionar@gmail.com>
*/

#include <iostream>
#include "headers/main.h"
#include "model/headers/Character.h"

/*
 * Bootstraps Game Controller
 */
Main *Main::bootstrap() {
    // TODO: Controllers
    string name = "kuakman";
    Character *c = new Character(name, HEROE);
    c->talk();
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
