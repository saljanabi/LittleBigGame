/*
** Animation.h for LittleBigGame in /LittleBigGame/bourdal_j
**
** Made by AL JANABI Sarah
** Login   <aljana_s@etna-alternance.net>
**
*/


#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Graphics.hpp>

struct Frame {
    sf::IntRect rect;
    double duration; // in seconds
};


class Animation {
    std::vector<Frame> frames;
    double totalLength;
    double progress;
    sf::Sprite &target;

public:
    Animation(sf::Sprite &target);
    virtual ~Animation();
    void addFrame(Frame&& frame);
    void update(double elapsed);
    const double getLength() const { return totalLength; }
};

#endif //ANIMATION_H
