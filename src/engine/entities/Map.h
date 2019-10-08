/*
** Map.h for LittleBigGame in /LittleBigGame/bourdal_j
**
** Made by AL JANABI Sarah
** Login   <aljana_s@etna-alternance.net>
**
*/

#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include "AbstractEntity.h"


class Map : public AbstractEntity {
public:
    Map();
    ~Map();

    void Draw();
    void Update();

    sf::Sprite background;
    sf::Texture backgroundTexture;

    sf::Sprite ground;
    sf::Texture groundTexture;

    sf::Sprite map1;
    sf::Texture mapTexture1;
    sf::Sprite map2;
    sf::Texture mapTexture2;
    sf::Sprite map3;
    sf::Texture mapTexture3;
    sf::Sprite flagpoleSprite;
    sf::Texture flagpoleTexture;

    sf::Vector2f flagpolePosition = flagpoleSprite.getPosition();

    sf::Sprite getBackground();
    sf::Sprite getGround();
    sf::Sprite getMap1();
    sf::Sprite getMap2();
    sf::Sprite getMap3();
    sf::Sprite getFlagpole();
    void setWindow(sf::RenderWindow *window);

    int score;
    int map;

private:

    sf::RenderWindow *window;

    int level;
    int loopTimer;
    int mapTimer;

    // Constantes
    // Taille de la fenêtre : 700x440 pixels
    const int SCREEN_WIDTH = 700;
    const int SCREEN_HEIGHT = 440;

    // Constante pour l'animation
    const int TIME_BETWEEN_2_FRAMES = 20;

};
#endif //MAP_H
