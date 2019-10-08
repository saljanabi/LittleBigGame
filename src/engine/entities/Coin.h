/*
** Coin.h for LittleBigGame in /LittleBigGame/bourdal_j
**
** Made by AL JANABI Sarah
** Login   <aljana_s@etna-alternance.net>
**
*/

#ifndef COIN_H
#define COIN_H

#include <SFML/Graphics.hpp>
#include "Score.h"
#include "AbstractEntity.h"
#include <iostream>
#include <sstream>

class Coin: public AbstractEntity {

public:
    void Draw();
    void Update();
    Coin(sf:: RenderWindow *window, sf::Vector2f pos);
    ~Coin();

    sf::FloatRect getGlobalBounds() {
        return shape.getGlobalBounds();
    }

    bool isDisplayed();
    void setDisplayed(bool displayed);


private:
    sf::RenderWindow *window;
    sf::RectangleShape shape;
    bool displayed;
};


#endif //_COIN_H
