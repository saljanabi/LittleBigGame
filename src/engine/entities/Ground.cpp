/*
** Ground.cpp for LittleBigGame in /LittleBigGame/bourdal_j
**
** Made by BOURDALE Jules
** Login   <bourda_j@etna-alternance.net>
**
*/

#include "Ground.h"

Ground::Ground(sf::Vector2f pos, sf::Vector2f size) {
    shape.setSize(size);
    shape.setPosition(pos);
}
Ground::~Ground() {}

void Ground::Draw() {}
void Ground::Update() {}