/*
** AbstractEntity.hh for LittleBigGame in /LittleBigGame/bourdal_j
**
** Made by AL JANABI Sarah
** Login   <aljana_s@etna-alternance.net>
**
*/

#ifndef ABSTRACTENTITY_H
#define ABSTRACTENTITY_H


#include "../patterns/ISerializable.h"

class AbstractEntity {
protected:
    AbstractEntity();
    virtual ~AbstractEntity();

public:
    virtual void Update() = 0;
    virtual void Draw() = 0;
};

#endif //ABSTRACTENTITY_H
