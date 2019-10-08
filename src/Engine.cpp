/*
** Engine.cpp for LittleBigGame in /LittleBigGame/bourdal_j
**
** Made by AL JANABI Sarah
** Login   <aljana_s@etna-alternance.net>
**
*/
#ifdef __unix__
# include <unistd.h>
#elif defined _WIN32
# include <windows.h>
#define sleep(x) Sleep(1000 * (x))
#endif
#include "Engine.h"
#include "./engine/time/TimeManager.h"
#include "./engine/entities/CharacterFactory.h"

Engine::Engine() {
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Mario Bros.etna");

    map.setWindow(&window);
    mario_icon.loadFromFile("./src/resources/sprites/mario.png");
    window.setIcon(mario_icon.getSize().x,  mario_icon.getSize().y,  mario_icon.getPixelsPtr());

    coinVec.push_back(new Coin (&window, sf::Vector2f(250, 250)));
    coinVec.push_back(new Coin (&window, sf::Vector2f(400, 250)));

    groundVec.push_back(new Ground(sf::Vector2f(0, 410), sf::Vector2f(364, 40)));
    groundVec.push_back(new Ground(sf::Vector2f(432, 410), sf::Vector2f(308, 40)));
    groundVec.push_back(new Ground(sf::Vector2f(800, 410), sf::Vector2f(320, 40)));
    groundVec.push_back(new Ground(sf::Vector2f(1176, 410), sf::Vector2f(240, 40)));
    groundVec.push_back(new Ground(sf::Vector2f(1480, 410), sf::Vector2f(252, 40)));
    groundVec.push_back(new Ground(sf::Vector2f(1760, 410), sf::Vector2f(204, 40)));
    groundVec.push_back(new Ground(sf::Vector2f(2012, 410), sf::Vector2f(168, 40)));
    groundVec.push_back(new Ground(sf::Vector2f(2208, 410), sf::Vector2f(292, 40)));
    groundVec.push_back(new Ground(sf::Vector2f(2552, 410), sf::Vector2f(272, 40)));
    groundVec.push_back(new Ground(sf::Vector2f(2868, 410), sf::Vector2f(332, 40)));

    pipeVec.push_back(new Pipe(sf::Vector2f(1972, 392), sf::Vector2f(24, 48)));
    pipeVec.push_back(new Pipe(sf::Vector2f(1432, 376), sf::Vector2f(24, 64)));
    pipeVec.push_back(new Pipe(sf::Vector2f(1132, 376), sf::Vector2f(24, 64)));
    pipeVec.push_back(new Pipe(sf::Vector2f(310, 370), sf::Vector2f(12, 35)));

    blocVec.push_back(new Bloc(sf::Vector2f(156, 328)));
    blocVec.push_back(new Bloc(sf::Vector2f(172, 328)));
    blocVec.push_back(new Bloc(sf::Vector2f(188, 328)));
    blocVec.push_back(new Bloc(sf::Vector2f(204, 328)));
    blocVec.push_back(new Bloc(sf::Vector2f(220, 328)));
    blocVec.push_back(new Bloc(sf::Vector2f(236, 328)));
    blocVec.push_back(new Bloc(sf::Vector2f(552, 328)));
    blocVec.push_back(new Bloc(sf::Vector2f(568, 328)));
    blocVec.push_back(new Bloc(sf::Vector2f(584, 328)));
    blocVec.push_back(new Bloc(sf::Vector2f(932, 328)));
    blocVec.push_back(new Bloc(sf::Vector2f(948, 328)));
    blocVec.push_back(new Bloc(sf::Vector2f(964, 328)));
    blocVec.push_back(new Bloc(sf::Vector2f(980, 328)));
    blocVec.push_back(new Bloc(sf::Vector2f(1264, 328)));
    blocVec.push_back(new Bloc(sf::Vector2f(1280, 328)));
    blocVec.push_back(new Bloc(sf::Vector2f(1296, 328)));
    blocVec.push_back(new Bloc(sf::Vector2f(1312, 328)));
    blocVec.push_back(new Bloc(sf::Vector2f(1588, 328)));
    blocVec.push_back(new Bloc(sf::Vector2f(1604, 328)));
    blocVec.push_back(new Bloc(sf::Vector2f(1620, 328)));
    blocVec.push_back(new Bloc(sf::Vector2f(1636, 328)));
    blocVec.push_back(new Bloc(sf::Vector2f(1844, 328)));
    blocVec.push_back(new Bloc(sf::Vector2f(1860, 328)));
    blocVec.push_back(new Bloc(sf::Vector2f(1876, 328)));
    blocVec.push_back(new Bloc(sf::Vector2f(1892, 328)));
    blocVec.push_back(new Bloc(sf::Vector2f(2084, 328)));
    blocVec.push_back(new Bloc(sf::Vector2f(2084, 328)));
    blocVec.push_back(new Bloc(sf::Vector2f(2100, 328)));
    blocVec.push_back(new Bloc(sf::Vector2f(2116, 328)));
    blocVec.push_back(new Bloc(sf::Vector2f(2328, 328)));
    blocVec.push_back(new Bloc(sf::Vector2f(2344, 328)));
    blocVec.push_back(new Bloc(sf::Vector2f(2360, 328)));
    blocVec.push_back(new Bloc(sf::Vector2f(2376, 328)));
    blocVec.push_back(new Bloc(sf::Vector2f(2648, 328)));
    blocVec.push_back(new Bloc(sf::Vector2f(2664, 328)));
    blocVec.push_back(new Bloc(sf::Vector2f(2680, 328)));
    blocVec.push_back(new Bloc(sf::Vector2f(2696, 328)));
    blocVec.push_back(new Bloc(sf::Vector2f(2712, 328)));
    blocVec.push_back(new Bloc(sf::Vector2f(2948, 328)));
    blocVec.push_back(new Bloc(sf::Vector2f(2964, 328)));
    blocVec.push_back(new Bloc(sf::Vector2f(2980, 328)));
    blocVec.push_back(new Bloc(sf::Vector2f(2996, 328)));
    blocVec.push_back(new Bloc(sf::Vector2f(3012, 328)));


    CharacterFactory characterFactory;;
    this->marioPlayer = (Mario *)characterFactory.Create("Mario");
    std::cout << "mario : " << this->marioPlayer << std::endl;
    this->marioPlayer->setGrounds(groundVec);
    this->marioPlayer->setPipes(pipeVec);
    this->marioPlayer->setBlocs(blocVec);

    mainSound.openFromFile("./src/resources/sounds/overworld.wav");
    jump.openFromFile("./src/resources/sounds/smb_jumpsmall.wav");
    end.openFromFile("./src/resources/sounds/smb_flagpole.wav");
    lblScore.score = 0;
}

Engine* Engine::instance = 0;

Engine* Engine::getInstance()
{
    if (instance == 0)
    {
        instance = new Engine();
    }

    return instance;
}

void Engine::Update(unsigned int dtAsSeconds) {
    std::cout << "DT AS SECONDS : " << dtAsSeconds << std::endl;
    marioPlayer->Update(dtAsSeconds);
    map.Update();

    for (auto& coin : coinVec) {
        if (marioPlayer->isCollidingWithCoin(coin)) {
            coin->setDisplayed(false);
            lblScore.score++;
        }
    }
}

void Engine::Draw() {
    window.clear();
    map.Draw();
    lblScore.Draw(window);
    window.draw(marioPlayer->getSprite());
    for (auto& coin : coinVec) {
        if (coin->isDisplayed()){
            coin->Draw();
        }
    }
    window.display();
}

sf::View Engine::Input(sf::View view) {
    bool isJumping;
    const int groundHeight = 700;
    const float gravitySpeed = 0.3;
    view = window.getView();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        marioPlayer->moveLeft();
        view.setCenter(marioPlayer->getSprite().getPosition().x, marioPlayer->getSprite().getPosition().y);
        window.setView(view);
    } else {
        marioPlayer->stopLeft();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        marioPlayer->moveRight();
        view.setCenter(marioPlayer->getSprite().getPosition());
        window.setView(view);
    } else {
        marioPlayer->stopRight();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        jump.stop();
        jump.play();
        marioPlayer->moveUp();
        view.setCenter(marioPlayer->getSprite().getPosition().x, marioPlayer->getSprite().getPosition().y);
        window.setView(view);
    } else {
        marioPlayer->stopUp();
        isJumping = false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        window.close();
    }

    if (marioPlayer->getSprite().getPosition().x >= 3115) {
        end.play();
        sleep(3);
        std::cout << "\tEND\n";
        window.close();
    }
    std::cout << "X=" << marioPlayer->getSprite().getPosition().x;
    return view;
}

void Engine::Start() {
    TimeManager &t = TimeManager::GetInstance();
    t.Update();
    window.setFramerateLimit(60);
    mainSound.play();
    
    sf::View view(sf::FloatRect(
                                50.f,
                                (window.getSize().y - (window.getSize().y)/3),
                                window.getSize().x - 2*(window.getSize().x)/3,
                                window.getSize().y - 2*(window.getSize().y)/3 - 22));
    window.getView();
    view.setCenter(marioPlayer->getSprite().getPosition().x+20, marioPlayer->getSprite().getPosition().y + 378);
    window.setView(view);

    while (window.isOpen()) {
        t.Update();

        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        Input(view);
        window.getView();
        Update(t.GetElapsedTime());
        Draw();
    }
}

Engine::~Engine() {}
