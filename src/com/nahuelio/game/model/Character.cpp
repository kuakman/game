/*
*	Class Character
*	@author Patricio Ferreira <3dimentionar@gmail.com>
*/

#include "headers/Character.h"
// #include <boost/uuid/uuid_generators.hpp>

/** Constructors **/

Character::Character() {
    Character("Unknown");
}

Character::Character(string name) {
    Character(name, MELEE);
}

Character::Character(string name, CharacterType type) {
    this->name(name);
    this->type(type);
}

/** Setters & Getters **/

string Character::name() {
    return _name;
}

Character Character::name(string name) {
    _name = name;
    return *this;
}

CharacterType Character::type() {
    return _type;
}

Character Character::type(CharacterType type) {
    _type = type;
    return *this;
}

/** Methods **/

Character Character::talk() {
    printf("[%s] - [%d] is talking...\n", this->name().c_str(), this->type());
    return *this;
}
