/*
** IObservable.h for LittleBigGame in /LittleBigGame/bourdal_j
**
** Made by AL JANABI Sarah
** Login   <aljana_s@etna-alternance.net>
**
*/


#ifndef IOBSERVABLE_H
#define IOBSERVABLE_H

#include <list>

class IObserver;
class IObservable {

public:
    virtual ~IObservable() {}

    virtual void AddObserver(IObserver* observer) = 0;
    virtual void RemoveObserver(IObserver* observer) = 0;
};

#endif //IOBSERVABLE_H
