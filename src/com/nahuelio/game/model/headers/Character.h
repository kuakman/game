/*
*	Interface Character
*	@author Patricio Ferreira <3dimentionar@gmail.com>
*/

#ifndef HEADERS_CHARACTER_H_
#define HEADERS_CHARACTER_H_

#include <string>
#include <boost/uuid/uuid.hpp>

namespace game_model {

    typedef enum {
        HEROE = 1,
        ENEMY = 2,
        PASSIVE = 3,
    } CharacterType;

    class Character {

        private:
            boost::uuids::uuid _id;
            CharacterType _type;
            std::string _name;

        public:
            Character();

            Character(std::string name);

            Character(std::string name, CharacterType type);

            Character walk();

            std::string id();

            CharacterType type();

            Character type(CharacterType type);

            std::string name();

            Character name(std::string name);

    };

}

#endif /* HEADERS_CHARACTER_H_ */
