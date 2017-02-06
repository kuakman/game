/*
*	Class Character
*	@author Patricio Ferreira <3dimentionar@gmail.com>
*/

#include "headers/Character.h"
#include <boost/uuid/uuid_generators.hpp>

//Character::Character() : _id(boost::uuids::random_generator()()) {
Character::Character() {
    this->setType(MELEE);
    this->setName("Unknown");
}

Character::Character(string &name) {
	Character().setName(name);
}

Character::Character(string &name, CharacterType type) {
	Character(name).setType(type);
}

void Character::talk() {
    printf("[%s] - [%d] is talking...", this->getName().c_str(), this->getType());
}
