/*
 *	Main
 *	@author: patricio.ferreira
 */

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "model/headers/character.h"

/*
 * Game Launch
 */
int main() {
	Character *c = new Character("kuakman");
	c->talk();
	return 0;
}
