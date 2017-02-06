/*
*	Interface Character
*	@author Patricio Ferreira <3dimentionar@gmail.com>
*/

#ifndef HEADERS_CHARACTER_H_
#define HEADERS_CHARACTER_H_

#include <string>
#include <boost/uuid/uuid.hpp>

using namespace std;

typedef enum {
    MELEE = 1,
    HEROE = 2,
    SPECIAL = 3
} CharacterType;

class Character {

	private:
		boost::uuids::uuid _id;
        CharacterType _type;
		string _name;

	public:
        Character();
        Character(string &name);
        Character(string &name, CharacterType type);

		void talk();

        boost::uuids::uuid getId() { return _id; };

        CharacterType getType() { return _type; }
        Character& setType(CharacterType type) { _type = type; return *this; };

        string getName() { return _name; };
        Character& setName(string name) { _name = name; return *this; };
};

#endif /* HEADERS_CHARACTER_H_ */
