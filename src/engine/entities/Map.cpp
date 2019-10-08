/*
** Map.cpp for LittleBigGame in /LittleBigGame/bourdal_j
**
** Made by AL JANABI Sarah
** Login   <aljana_s@etna-alternance.net>
**
*/

#include "Map.h"

//Constructeur
Map::Map() {
    backgroundTexture.loadFromFile("./src/resources/sprites/background.png");
    background.setTexture(backgroundTexture);

    groundTexture.loadFromFile("./src/resources/sprites/ground.png");
    ground.setTexture(groundTexture);

    mapTexture1.loadFromFile("./src/resources/sprites/layer1.png");
    map1.setTexture(mapTexture1);

    mapTexture2.loadFromFile("./src/resources/sprites/layer2.png");
    map2.setTexture(mapTexture1);

    mapTexture3.loadFromFile("./src/resources/sprites/layer3.png");
    map3.setTexture(mapTexture3);

    flagpoleTexture.loadFromFile("./src/resources/sprites/flagpole.png");

    flagpoleSprite.setTexture(flagpoleTexture);

    flagpoleSprite.setScale(0.4,0.4); 

    flagpolePosition.x = 3100;
    flagpolePosition.y = 300;


    std::cout << flagpolePosition.x << " " << flagpolePosition.y << "\n";

    loopTimer = 0;
    mapTimer = TIME_BETWEEN_2_FRAMES * 3;
    level = 1;
}

Map::~Map() {}

void Map::Update() {
    loopTimer = loopTimer + 1;
    if (loopTimer % 60 == 0) {
        level = 3;
        std::cout << std::to_string(loopTimer) << "\tlevel 3 \n";
    } else if (loopTimer % 40 == 0){
        level = 2;
        std::cout << std::to_string(loopTimer) << "\tlevel 2 \n";
    } else if (loopTimer % 20 == 0){
        level = 1;
        std::cout << std::to_string(loopTimer) << "\tlevel 1 \n";
    }

    flagpoleSprite.setPosition(flagpolePosition);
}

void Map::Draw() {
    window->draw(this->getBackground());
    window->draw(this->getGround());

    window->draw(this->getMap1());
    window->draw(this->getMap2());
    window->draw(this->getMap3());
    window->draw(this->getFlagpole());
}

sf::Sprite Map::getBackground() {
    return background;
}

sf::Sprite Map::getGround() {
    return ground;
}

sf::Sprite Map::getMap1() {
    return map1;
}

sf::Sprite Map::getMap2() {
    return map2;
}

sf::Sprite Map::getMap3() {
    return map3;
}

sf::Sprite Map::getFlagpole() {
    return flagpoleSprite;
}

void Map::setWindow(sf::RenderWindow *window) {
    this->window = window;
}