/*
** AbstractEntity.cpp for LittleBigGame in /LittleBigGame/bourdal_j
**
** Made by AL JANABI Sarah
** Login   <aljana_s@etna-alternance.net>
**
*/

#include "Character.h"
#include "AbstractEntity.h"



void AbstractEntity::Update() {

}

void AbstractEntity::Draw() {

}

AbstractEntity::AbstractEntity() {

}

AbstractEntity::~AbstractEntity() {

}

namespace ns {
    // a simple struct to model a character
    struct Character {
        int life;
        double x;
        double y;
        std::list<IObserver*> observers;
    };
}
