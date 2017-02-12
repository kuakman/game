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
    Character *c = new Character("Character A", HEROE);
    c->walk().name("Character B").type(PASSIVE).walk();
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
