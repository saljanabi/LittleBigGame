/*
** Ground.h for LittleBigGame in /LittleBigGame/bourdal_j
**
** Made by BOURDALE Jules
** Login   <bourda_j@etna-alternance.net>
**
*/

#ifndef GROUND_H
#define GROUND_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include "AbstractEntity.h"

class Ground: public AbstractEntity {

public:
    void Draw();
    void Update();
    Ground(sf::Vector2f pos, sf::Vector2f size);
    ~Ground();

    sf::FloatRect getGlobalBounds() {
        return shape.getGlobalBounds();
    }

private:
    sf::RectangleShape shape;
};

#endif //_GROUND_H
