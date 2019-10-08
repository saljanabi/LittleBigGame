/*
** Character.h for LittleBigGame in /LittleBigGame/bourdal_j
**
** Made by AL JANABI Sarah
** Login   <aljana_s@etna-alternance.net>
**
*/

#ifndef CHARACTER_H
#define CHARACTER_H


#include "AbstractEntity.h"
#include "../patterns/IObservable.h"
#include "../patterns/IObserver.h"
#include <list>

class Character : public AbstractEntity/*, public IObservable */{

private:

protected:
//    std::list<IObserver*> _observer;
    double _x;
    double _y;
//    float _dirX;
//    float _dirY;
    int _life;
    bool _onGround;

public:
    Character();
    virtual void Update() override;
    virtual void Draw() override;
    virtual ~Character() = 0;

//  mutators
    double GetX() const;
    void SetX(double x);

    double GetY() const;
    void SetY(double y);

    int GetLife() const;
    void SetLife(int life);

    bool GetOnGround() const;
    void SetOnGround(bool onGround);

};

#endif //CHARACTER_H
