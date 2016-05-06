#include "Game.h"
#include <iostream>


Game::Game()
{
    ContextSettings settings;
    settings.antialiasingLevel = 8;
    window.create(VideoMode(SCRN_WIDTH, SCRN_HEIGHT), "Snake", Style::Close, settings);
    window.setFramerateLimit(60);
    Vector2i window_position = Vector2i(0,0);
    window.setPosition(window_position);    


    if (!font.loadFromFile("data/font.ttf"))
    {
        cout<<"Can't load font"<<endl;
        return;
    }

    actualGame_status=MENU;
    game_status = new Menu(MENU, window,"Snake",font);
    game_status->init();

    music.openFromFile("data/loop.wav");
    music.setLoop(true);
    music.setRelativeToListener(true);

    music.setVolume(40.f);
    music.play();

}

Game::~Game()
{   
    music.stop();
    window.close();
}


void Game::start()
{
   
    while(actualGame_status != END)
    {
       
        if(actualGame_status != game_status->getStatusType())
           changeActualGame_status();

         handleState();
    }

}

void Game::changeActualGame_status()
{

   delete game_status;

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