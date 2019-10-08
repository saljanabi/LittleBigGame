/*
** IObserver.h for LittleBigGame in /LittleBigGame/bourdal_j
**
** Made by AL JANABI Sarah
** Login   <aljana_s@etna-alternance.net>
**
*/

#ifndef IOBSERVER_H
#define IOBSERVER_H

class IObservable;
class IObserver {

public:
    virtual ~IObserver() {}

    virtual void Notify(IObservable* observable) = 0;
};

#endif //IOBSERVER_H
