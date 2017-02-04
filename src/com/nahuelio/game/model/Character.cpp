/*
 *	Class Character
 *	@author Patricio Ferreira <3dimentionar@gmail.com>
 */

#include "headers/Character.h";
#include <iostream>

Character::Character() {
	this->id = 0;
}

Character::Character(int id) {
	this->id = id ? id : Character();
	this->name = "Unknown";
}

Character::Character(string name) {
	this->name = name;
}

void Character::talk() {
	char buffer [100];
	cout << sprintf(buffer, "%s is taking...", this->name) << endl;
}
