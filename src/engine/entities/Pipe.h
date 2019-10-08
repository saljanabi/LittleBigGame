/*
** Pipe.h for LittleBigGame in /LittleBigGame/bourdal_j
**
** Made by BOURDALE Jules
** Login   <bourda_j@etna-alternance.net>
**
*/

#ifndef PIPE_H
#define PIPE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

class Pipe {

public:
    void Draw(sf:: RenderWindow &window);
    void Update();
    Pipe(sf::Vector2f pos, sf::Vector2f size);
    ~Pipe();

    sf::FloatRect getGlobalBounds() {
        return shape.getGlobalBounds();
    }

private:
    sf::RectangleShape shape;
};


#endif //_PIPE_H
