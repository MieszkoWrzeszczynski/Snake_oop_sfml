#include "Play.h"
#include <stdlib.h>    
#include <time.h>   
#include <iostream>
#include <cstdio>

Play::Play(int status_type, RenderWindow & window,std::string window_title,Font & font):
Status(status_type,window,window_title,font)
{
    srand (time(NULL));  

    score = 1;
    fraps = 15;

    string tmp; 
    sprintf((char*)tmp.c_str(), "%d", score);
    string str_score = tmp.c_str();

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
        fraps+= 3;
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

                    case Event::Closed :
                        return  Game::END;
                    break;

                    case Event::KeyPressed:

                     if(event.key.code == Keyboard::Escape)
                           return  Game::END;

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
                      
                    break;

                 }

            }

            while (timeSinceLastUpdate > TimePerFrame)
            {
                timeSinceLastUpdate -= TimePerFrame;

  			    if(!snake->exist())
                   return Game::GAME_OVER;

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

    Vector2f randomPosition = getRandomPosition();
    do
    {
        randomPosition.x = 100 + (rand() % (int)(Game::SCRN_WIDTH  - 120 + 1));
        randomPosition.y = 100 + (rand() % (int)(Game::SCRN_HEIGHT - 120 + 1));
    
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