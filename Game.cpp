#include "Game.h"
#include "Menu.h"
#include "Play.h"
//#include "GameOver.h"
#include <iostream>
using namespace sf;


Game::Game()
{
   
    window.create(VideoMode(SCRN_WIDTH, SCRN_HEIGHT), "Snake");
    window.setFramerateLimit(60);
    Vector2i window_position = Vector2i(0,0);
    window.setPosition(window_position);       

    if (!font.loadFromFile("data/font.ttf"))
    {
        cout<<"Can't load font"<<endl;
        return;
    }
    
}


void Game::start()
{
    game_status = new Menu(MENU, window,"Snake",font);
    game_status->init();

    while(actualGame_status != END)
    {
       
        if(actualGame_status != game_status->getStatusType())
           changeActualGame_status();

         handleState();

    }

    window.close();
}

void Game::changeActualGame_status()
{
    switch (actualGame_status)
    {
        case MENU:
            game_status = new Menu(MENU, window, "Menu",font);
            break;

        case RUN:
            game_status = new Play(MENU, window, "Play mode",font);
            break;

        case GAME_OVER:
            game_status = new Menu(MENU, window, "Game over",font);
            break;
    }
    
    game_status->init();
}

void Game::handleState()
{   
    actualGame_status = game_status->getEvents(event);
    game_status->update();
    game_status->render();
}