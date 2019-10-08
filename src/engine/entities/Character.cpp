/*
** Character.cpp for LittleBigGame in /LittleBigGame/bourdal_j
**
** Made by AL JANABI Sarah
** Login   <aljana_s@etna-alternance.net>
**
*/

#include "Character.h"
#include <iostream>
//
Character::Character() {

}
Character::~Character() {

}

void Character::Update() {

}

void Character::Draw() {

}

double Character::GetX() const {
    return this->_x;
}

void Character::SetX(double x) {
    this->_x = x;
}

double Character::GetY() const {
    return this->_y;
}
void Character::SetY(double y) {
    this->_y = y;
}

int Character::GetLife() const {
    return this->_life;
}
void Character::SetLife(int life) {
    this->_life = life;
}

bool Character::GetOnGround() const {
    return this->_onGround;
}
void Character::SetOnGround(bool onGround) {
    this->_onGround = onGround;
//    for (IObserver *n : this->_observer)
//    {
//        n->Notify(this);
//    }
}
