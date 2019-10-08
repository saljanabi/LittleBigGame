/*
** Bloc.cpp for LittleBigGame in /LittleBigGame/bourdal_j
**
** Made by BOURDALE Jules
** Login   <bourda_j@etna-alternance.net>
**
*/

#include "Bloc.h"

Bloc::Bloc(sf::Vector2f pos) {
    shape.setSize({ 16, 16 });
    shape.setPosition(pos);
}
Bloc::~Bloc() {}

void Bloc::Draw() {}
void Bloc::Update() {}