/*
** Coin.cpp for LittleBigGame in /LittleBigGame/bourdal_j
**
** Made by AL JANABI Sarah
** Login   <aljana_s@etna-alternance.net>
**
*/

#include "Coin.h"
#include "Score.h"

Coin::Coin(sf::RenderWindow *window, sf::Vector2f pos) {
	this->window = window;
    shape.setSize({ 20, 20 });
    shape.setFillColor(sf::Color::Yellow);
    shape.setPosition(pos);
    this->setDisplayed(true);
}
Coin::~Coin() {}

void Coin::Draw() {
    window->draw(shape);
}

void Coin::Update() {}

bool Coin::isDisplayed() {
    return this->displayed;
}

void Coin::setDisplayed(bool displayed) {
    this->displayed = displayed;
}
