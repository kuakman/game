/*
*	Interface Character
 *	@author Patricio Ferreira <3dimentionar@gmail.com>
 */

#ifndef HEADERS_CHARACTER_H_
#define HEADERS_CHARACTER_H_

#include <string>

using namespace std;

class Character {

	protected:
		int id;
		string name;

	public:
		Character();
		Character(int id);
		Character(string name);

		void talk();

		virtual ~Character();

};

#endif /* HEADERS_CHARACTER_H_ */
