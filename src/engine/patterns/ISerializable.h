/*
** ISerializable.h for LittleBigGame in /LittleBigGame/bourdal_j
**
** Made by AL JANABI Sarah
** Login   <aljana_s@etna-alternance.net>
**
*/
#ifndef ISERIALIZABLE_H
#define ISERIALIZABLE_H

#include <iostream>

class ISerializable {

public:
    virtual ~ISerializable() {}

    virtual std::string& Serialize() = 0;
};

#endif //ISERIALIZABLE_H
