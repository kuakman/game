/*
*	Class Character
*	@author Patricio Ferreira <3dimentionar@gmail.com>
*/

#include <iostream>
#include "headers/Character.h"
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/uuid_generators.hpp>

using namespace game_model;

/** Constructors **/

Character::Character() {
	Character("Unknown");
}

Character::Character(std::string name) {
    Character(name, HEROE);
}

Character::Character(std::string name, CharacterType type) :
		_id(boost::uuids::random_generator()()),
		_name(name),
		_type(type) {
}

/** Setters & Getters **/

std::string Character::id() {
	return boost::uuids::to_string(_id);
}

std::string Character::name() {
	return _name;
}

Character Character::name(std::string name) {
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

Character Character::walk() {
	printf("[%s] >> [%s] - [%d] is walking...\n", this->id().c_str(), this->name().c_str(), this->type());
	return *this;
}
