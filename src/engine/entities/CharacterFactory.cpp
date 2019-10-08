/*
** CharacterFactory.cpp for Baignoire in /group-687056
**
** Made by BOURDALE Jules
** Login   <bourda_j@etna-alternance.net>
**
*/

#include "CharacterFactory.h"

CharacterFactory::CharacterFactory() {}

CharacterFactory::~CharacterFactory() {}

Character *CharacterFactory::Create(const std::string &className) 
{
	if (className == "Mario") {
		return new Mario();
	}
	return nullptr;
}