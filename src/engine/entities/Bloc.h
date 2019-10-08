/*
** Bloc.h for LittleBigGame in /LittleBigGame/bourdal_j
**
** Made by BOURDALE Jules
** Login   <bourda_j@etna-alternance.net>
**
*/

#ifndef BLOC_H
#define BLOC_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include "AbstractEntity.h"

class Bloc: public AbstractEntity {

public:
    void Draw();
    void Update();

    Bloc(sf::Vector2f pos);
    ~Bloc();

    sf::FloatRect getGlobalBounds() {
        return shape.getGlobalBounds();
    }

private:
    sf::RectangleShape shape;
};


#endif //_BLOC_H
