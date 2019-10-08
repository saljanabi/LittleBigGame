/*
** Score.h for LittleBigGame in /LittleBigGame/bourdal_j
**
** Made by AL JANABI Sarah
** Login   <aljana_s@etna-alternance.net>
**
*/

#ifndef SCORE_H
#define SCORE_H

#include "Coin.h"
#include <sstream>
#include <iostream>

class Score {

public:
    Score();
    ~Score();

    void Draw(sf:: RenderWindow &window);
    void Update(sf::Text lblScore);

    int score;

    std::ostringstream ssScore;
    sf::Text lblScore;
    sf::Font arial;
};


#endif //SCORE_H
