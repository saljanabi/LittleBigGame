/*
** Pipe.cpp for LittleBigGame in /LittleBigGame/bourdal_j
**
** Made by BOURDALE Jules
** Login   <bourda_j@etna-alternance.net>
**
*/

#include "Pipe.h"

Pipe::Pipe(sf::Vector2f pos, sf::Vector2f size) {
    shape.setSize(size);
    shape.setPosition(pos);
}
Pipe::~Pipe() {}