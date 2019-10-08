/*
** Engine.h for LittleBigGame in /LittleBigGame/bourdal_j
**
** Made by AL JANABI Sarah
** Login   <aljana_s@etna-alternance.net>
**
*/

#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "engine/entities/Mario.h"
#include "engine/entities/Map.h"
#include "engine/entities/Score.h"
#include "engine/entities/Coin.h"
#include "engine/entities/Bloc.h"
#include "engine/entities/Ground.h"
#include "engine/entities/Pipe.h"

class Engine {

private:
    sf::RenderWindow window;
    sf::Clock globalClock;
    sf::Time duration;
    sf::Image mario_icon;
    sf::Music mainSound;
    sf::Music jump;
    sf::Music end;

    Engine();
    static Engine* instance;

    Map map;
    Score lblScore;
    Mario *marioPlayer;
    std::vector<Coin*> coinVec;
    std::vector<Ground*> groundVec;
    std::vector<Pipe*> pipeVec;
    std::vector<Bloc*> blocVec;

    sf::View Input(sf::View view);
    void Update(unsigned int dtAsSeconds);
    void Draw();


public:
    static Engine* getInstance();

    virtual ~Engine();
    void Start();
    void End();

    const int SCREEN_WIDTH = 700;
    const int SCREEN_HEIGHT = 440;

};


#endif //ENGINE_H
