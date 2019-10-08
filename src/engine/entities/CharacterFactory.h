/*
** CharacterFactory.hh for Baignoire in /group-687056
**
** Made by BOURDALE Jules
** Login   <bourda_j@etna-alternance.net>
**
*/
#include <string>

#include "Character.h"
#include "Mario.h"

class CharacterFactory {

public:
	CharacterFactory();
	~CharacterFactory();

	Character *Create(const std::string&);
};