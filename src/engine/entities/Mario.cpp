/*
** Mario.cpp for LittleBigGame in /LittleBigGame/bourdal_j
**
** Made by AL JANABI Sarah
** Login   <aljana_s@etna-alternance.net>
**
*/

#include "Mario.h"

Mario::Mario() {

    marioTexture.loadFromFile("./src/resources/sprites/littleMario.png");
    marioSprite.setTexture(marioTexture);

    marioSprite.setTextureRect(sf::IntRect(10, 0, 30, 30));

    marioPosition.x = 15;
    marioPosition.y = 378;

    marioSpeed = 170;

    groundHeight = 700;
    gravitySpeed = 0.3;

    yVelocity = -10;
    isJumping = false;
}

void Mario::Update(unsigned int elapsedSec) {
    float elapsedTime = elapsedSec / 1000.0;

    int oldy = marioPosition.y;
    int oldx = marioPosition.x;
    
    if (yVelocity > 0) {
        std::cout << "JUMPING MARIO" << std::endl;
        marioPosition.y -= 2;
        yVelocity -= 2;
    }
    if (yVelocity < 0) {
        marioPosition.y++;
    }
    
    if (keyRightPressed) {
        marioPosition.x += /*2;*/ marioSpeed * elapsedTime;
    }

    if (keyLeftPressed) {
        // marioSprite.move({sf::Vector2f(-marioSpeed, 0)});
        marioPosition.x -= /*2;*/ marioSpeed * elapsedTime;
    }
    marioSprite.setPosition(marioPosition);
    
    if (isCollidingWithPipes()) {
        marioPosition.x = oldx;
        marioPosition.y = oldy;
        isJumping = false;
    }

    if (isCollidingWithGrounds() && yVelocity < 0) {
        isJumping = false;
    }

    if(!isJumping && isCollidingWithGrounds()) {
        isJumping = false;
        marioPosition.y = oldy;
    }

    marioSprite.setPosition(marioPosition);
    // Le sprite est ici déplacé à sa nouvelle position
}

void Mario::Draw() {

}


sf::Sprite Mario::getSprite() {
    return marioSprite;
}

void Mario::moveLeft() {
    keyLeftPressed = true;
}
void Mario::stopLeft() {
    keyLeftPressed = false;
}

void Mario::moveRight() {
    keyRightPressed = true;
}
void Mario::stopRight() {
    keyRightPressed = false;
}

void Mario::moveUp() {
    // marioSprite.move({sf::Vector2f(0, -marioSpeed)});
    std::cout << "MOVE UP" << std::endl;
    if (!isJumping) {
        isJumping = true;
        keyUpPressed = true;
        yVelocity = 61;
    }
}
void Mario::stopUp() {
    keyUpPressed = false;
    marioSprite.move({sf::Vector2f(0, gravitySpeed)});
}

bool Mario::isCollidingWithCoin(Coin *coin) {
    if (marioSprite.getGlobalBounds().intersects(coin->getGlobalBounds())) {
        return true;
    }
    return false;
}

bool Mario::isCollidingWithGrounds() {
    for (auto const& ground: this->grounds) {
        if (marioSprite.getGlobalBounds().intersects(ground->getGlobalBounds())) {
            return true;
        }
    }
    //exit(0);
    return false;
}

bool Mario::isCollidingWithPipes() {
    for (auto const& pipe: this->pipes) {
        if (marioSprite.getGlobalBounds().intersects(pipe->getGlobalBounds())) {
            std::cout << "INTERSECT WITH PIPE " << pipe->getGlobalBounds().left << ";" << pipe->getGlobalBounds().top  << " > " << pipe->getGlobalBounds().width << ";" << pipe->getGlobalBounds().height << std::endl;
            return true;
        }
    }
    //exit(0);
    return false;
}


Mario::~Mario() {

}

void Mario::setGrounds(std::vector<Ground *> grounds) {
    this->grounds = grounds;
}

void Mario::setPipes(std::vector<Pipe *> pipes) {
    this->pipes = pipes;
}

void Mario::setBlocs(std::vector<Bloc *> blocs) {
    this->blocs = blocs;
}
