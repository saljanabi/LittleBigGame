/*
** Score.cpp for LittleBigGame in /LittleBigGame/bourdal_j
**
** Made by AL JANABI Sarah
** Login   <aljana_s@etna-alternance.net>
**
*/

#include "Score.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

Score::Score() {
    arial.loadFromFile("/home/sarah/Developer/testSFML/Arial.ttf");
    int score = 0;
    lblScore.setCharacterSize(30);
    lblScore.setPosition({ 400, 400 });
    lblScore.setFont(arial);
    lblScore.setString(ssScore.str());
}

void Score::Draw(sf:: RenderWindow &window) {
    window.draw(lblScore);
}

void Score::Update(sf::Text lblScore) {

}

Score::~Score() {}