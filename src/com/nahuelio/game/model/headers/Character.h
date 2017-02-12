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
        Character(string name);
        Character(string name, CharacterType type);

		Character talk();

        boost::uuids::uuid getId() { return _id; };

        CharacterType type();
        Character type(CharacterType type);

        string name();
        Character name(string name);
};

#endif /* HEADERS_CHARACTER_H_ */
