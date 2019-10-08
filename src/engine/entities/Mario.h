/*
** Mario.h for LittleBigGame in /LittleBigGame/bourdal_j
**
** Made by AL JANABI Sarah
** Login   <aljana_s@etna-alternance.net>
**
*/

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>
#include "Character.h"
#include "Ground.h"
#include "Coin.h"
#include "Bloc.h"
#include "Pipe.h"

#ifndef MARIO_H
#define MARIO_H

class Mario : public Character {

private:

    sf::Vector2f marioPosition;

    sf::IntRect rectSourceSprite;
    sf::Texture marioTexture;
    sf::Sprite marioSprite;

    float marioSpeed;

    int lives;
    bool keyLeftPressed;
    bool keyRightPressed;
    bool keyUpPressed;
    bool noKeyIsPressed;
    bool isJumping;
    int groundHeight;
    float gravitySpeed;

    int yVelocity;

    std::vector<Ground *> grounds;
    std::vector<Pipe *> pipes;
    std::vector<Bloc *> blocs;

public:

    Mario();
    ~Mario();

    // Send a copy of the sprite to engine
    sf::Sprite getSprite();

    int frameNumber, frameTimer, frameMax;
    int state, direction;

    void moveLeft();
    void moveRight();
    void moveUp();

    void stopLeft();
    void stopRight();
    void stopUp();

    bool isCollidingWithCoin(Coin *coin);
    bool isCollidingWithGrounds();
    bool isCollidingWithPipes();

//    int AddCoins();
//    int GetCoins();
//    void InitCoins();

    void Draw();
    void Update(unsigned int elapsedTime);

    void setGrounds(std::vector<Ground *> grounds);
    void setPipes(std::vector<Pipe *> pipe);
    void setBlocs(std::vector<Bloc *> blocs);

//    std::string& Serialize() override;
//    void AddObserver(IObserver* observer) override;
//    void RemoveObserver(IObserver* observer) override;


// Constantes
// Limites de la caméra avant le scroll
    const int X_LIMIT = 400;
    const int Y_LIMIT = 220;
    const int W_LIMIT = 100;
    const int H_LIMIT = 80;

// Constantes de définition de la gravité, de la vitesse de chute, de la vitesse de saut
    const double GRAVITY_SPEED = 0.6;
    const int MAX_FALL_SPEED = 15;
    const int JUMP_HEIGHT = 10;
};


#endif //MARIO_H