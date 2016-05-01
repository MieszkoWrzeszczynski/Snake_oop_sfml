#include "Play.h"
#include <stdlib.h>    
#include <time.h>   


Play::Play(int status_type, RenderWindow & window,Font & font):Status(status_type,window,font)
{
   srand (time(NULL));  
}


void Play::init()
{
	
}

int Play::getEvents(Event & event)
{
	
	    Time TimePerFrame = seconds(1.f / 15.f);
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
                         snake.changeDirection(Snake::DIR_RIGHT);
                     else if( Keyboard::isKeyPressed( Keyboard::Right ) )
                         snake.changeDirection(Snake::DIR_RIGHT);
                     else if( Keyboard::isKeyPressed( Keyboard::Left ) )
                         snake.changeDirection(Snake::DIR_LEFT);
                     else if( Keyboard::isKeyPressed( Keyboard::Down ) ) 
                         snake.changeDirection(Snake::DIR_DOWN);
                     else if( Keyboard::isKeyPressed( Keyboard::Up ) ) 
                         snake.changeDirection(Snake::DIR_UP);
                      
                    break;

                 }

            }

            while (timeSinceLastUpdate > TimePerFrame)
            {
                timeSinceLastUpdate -= TimePerFrame;

  			    if(!snake.exist())
                   return Game::END;

                update();
                
            }

           render();
      
        }
}


void Play::render()
{
	pnt_window->clear();
 	snake.Render(*pnt_window);
 	food.draw(*pnt_window);
	pnt_window->display();
}


void Play::ifSnakeAteFood()
{
	if(food.GetFoodBounds().intersects(snake.GetHeadFloatRect()))
	{
		snake.AddBodyPart(); 
		food_respawn(snake);
	} 
}

void Play::update()
{
     ifSnakeAteFood();
     snake.Move();  
}

void Play::food_respawn(Snake & snake)
{

    Vector2f randomPosition;
    do
    {
        randomPosition.x = 100 + (rand() % (int)(Game::SCRN_WIDTH  - 120 + 1));

        randomPosition.y = 100 + (rand() % (int)(Game::SCRN_HEIGHT - 120 + 1));
    
    }while(snake.contains(randomPosition));


    food.set_position(randomPosition);
}