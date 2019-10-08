/*
** main.cpp for LittleBigGame in /LittleBigGame/bourdal_j
**
** Made by AL JANABI Sarah
** Login   <aljana_s@etna-alternance.net>
**
*/

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cstdlib>
#include <iostream>
#include "Engine.h"
#include "engine/entities/Mario.h"
#include "engine/log/Logger.h"
#include "engine/entities/Map.h"

int main()
{

    printf("avant le chargement de la fenêtre\n");

    Engine* engine = Engine::getInstance();
    engine->Start();

    log::Logger myLog ("1.0.4.2", "logsOutput/LittleBigGame.txt");
    myLog << log::Logger::e_logType::LOG_WARNING << "Hey! ... This is a warning message!";
    myLog << log::Logger::e_logType::LOG_ERROR << "WOW! Something really wrong is happening here!";
    myLog << "This is just a simple text";

    return 0;
}

