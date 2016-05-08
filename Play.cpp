#include "Play.h"
#include <stdlib.h>    
#include <time.h>   
#include <iostream>
#include <cstdio>
#include "Ranking.h"


Play::Play(int status_type, RenderWindow & window,std::string window_title,Font & font):
Status(status_type,window,window_title,font),score(0),fraps(12),paused(false)
{
    srand (time(NULL));  

    string tmp; 
    sprintf((char*)tmp.c_str(), "%d", score);
    string str_score =  tmp.c_str();

    score_gui.setString(str_score);
    score_gui.setFont(*pnt_font);
    score_gui.setCharacterSize(86);
    score_gui.setColor(Color(255,255,255,255));
    score_gui.setStyle(Text::Bold);
 
    score_gui.setPosition(Game::SCRN_WIDTH/2-4*score_gui.getGlobalBounds().width,40);

    buffer.loadFromFile("data/eat.wav");      
    sound.setBuffer(buffer);     

}

void Play::levelUp()
{
    if(score % 2)
        fraps+= 4;
    score++;
}


Play::~Play()
{
    delete snake;
    delete food;

}


void Play::init()
{
    snake = new Snake(20,getRandomPosition());
    food = new Food(20,getRandomPosition());
}

void Play::updateScore()
{
    string tmp; 
    sprintf((char*)tmp.c_str(), "%d", score);
    string str_score = tmp.c_str();
    score_gui.setString("Poziom " + str_score); 
}

int Play::getEvents(Event & event)
{
	
    Time TimePerFrame = seconds(1.f / fraps);
    Clock clock;
    Time timeSinceLastUpdate = Time::Zero;

    pnt_window->setMouseCursorVisible(false);

    while (true)
    {
       
       Time delta = clock.restart();
       timeSinceLastUpdate += delta;
    
        while (pnt_window->pollEvent(event))
        {
        
             switch(event.type)
             {

                case Event::KeyPressed:

                     if(event.key.code == Keyboard::Escape)
                     {
                  
                        checkScoreInRank();
                              rank.saveToRanking(Game::getPlayerName(),score);
                        return  Game::END;
                     }
                          

                    else if (Keyboard::isKeyPressed( Keyboard::Right ) )
                        snake->changeDirection(Snake::DIR_RIGHT);
                    else if( Keyboard::isKeyPressed( Keyboard::Right ) )
                        snake->changeDirection(Snake::DIR_RIGHT);
                    else if( Keyboard::isKeyPressed( Keyboard::Left ) )
                        snake->changeDirection(Snake::DIR_LEFT);
                    else if( Keyboard::isKeyPressed( Keyboard::Down ) ) 
                        snake->changeDirection(Snake::DIR_DOWN);
                    else if( Keyboard::isKeyPressed( Keyboard::Up ) ) 
                        snake->changeDirection(Snake::DIR_UP);
                    if ( Keyboard::isKeyPressed( Keyboard::P ) &&  !paused) 
                        paused = true;
                    else if ( Keyboard::isKeyPressed( Keyboard::P ) &&  paused) 
                        paused = false;
         
                break;

             }

        }

        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;

			    if(!snake->exist())
                {
                  
                    checkScoreInRank();
                      rank.saveToRanking(Game::getPlayerName(),score);
                    return Game::GAME_OVER;
                }
               

            if(!paused)
            update(); 
        }

      render();
    }
}


void Play::render()
{
	pnt_window->clear(Color(255,232,143,55));
    pnt_window->draw(score_gui);
    snake->Render(*pnt_window);
 	food->draw(*pnt_window);
	pnt_window->display();
}


void Play::ifSnakeAteFood()
{
	if(food->GetFoodBounds().intersects(snake->GetHeadFloatRect()))
	{
		snake->AddBodyPart(); 
		food_respawn(snake);
        levelUp();
        sound.play();
	} 
}

void Play::update()
{
     ifSnakeAteFood();
     snake->Move();  
     updateScore();
}

void Play::food_respawn(Snake * snake)
{
    Vector2f randomPosition;
   
    do
    {
       randomPosition = getRandomPosition(); 
       
    }while(snake->contains(randomPosition));


    food->set_position(randomPosition);
}


Vector2f Play::getRandomPosition()
{
    Vector2f randomPosition;

    randomPosition.x = 100 + (rand() % (int)(Game::SCRN_WIDTH  - 120 + 1));
    randomPosition.y = 100 + (rand() % (int)(Game::SCRN_HEIGHT - 120 + 1));
    
    return randomPosition;
}


void Play::checkScoreInRank()
{
    int best_score = rank.getTheBestPlayerScore();

    if(best_score < score)
    {
       pnt_window->clear(Color(178,30,0,255));
       score_gui.setPosition(Game::SCRN_WIDTH/2-1.5*score_gui.getGlobalBounds().width,40);
       score_gui.setString(Game::getPlayerName() + " masz nowy record!"); 
       pnt_window->draw(score_gui);
       pnt_window->display();
       sleep(seconds(2));
    }
    
}