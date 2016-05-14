#include "Play.h"
#include <stdlib.h>    
#include <time.h>  
#include <cstdio> 

Play::Play(int status_type, RenderWindow & window,std::string window_title,Font & font):
Status(status_type,window,window_title,font),score(0),fraps(12),paused(false)
{
    srand (time(NULL));  

    string tmp; 
    sprintf((char*)tmp.c_str(), "%d", score);
    string str_score =  tmp.c_str();

    title.setString(str_score);
    title.setFont(*pnt_font);
    title.setCharacterSize(86);
    title.setColor(Color(255,255,255,255));
    title.setStyle(Text::Bold);
    title.setPosition(Game::SCRN_WIDTH/2-3*title.getGlobalBounds().width,40);

    buffer.loadFromFile("data/eat.wav");      
    sound.setBuffer(buffer);    
}

void Play::loadFood()
{
    for( int i = 0; i < FOOD_AMOUNT ; i++)
    {
      if( i % 2)
        tab[i] = new ExtraFood(20,getRandomPosition());
      else
        tab[i] = new Food(20,getRandomPosition());
    }
}

void Play::drawFood()
{
    for( int i = 0; i < FOOD_AMOUNT; i++)
    {
      tab[i]->draw(*pnt_window);
    }
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

    for (int i = 0; i < FOOD_AMOUNT; ++i)
    {
      delete[] tab[i];
    }
}


void Play::init()
{
    snake = new Snake(20,getRandomPosition());
    loadFood();
}

void Play::updateScore()
{
    string tmp; 
    sprintf((char*)tmp.c_str(), "%d", score);
    string str_score = tmp.c_str();
    title.setString("Poziom " + str_score); 
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
                    {
                        title.setString("Pauza");
                        paused = true;
                    }
                     
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
  pnt_window->draw(title);
  snake->Render(*pnt_window);
  drawFood();
	pnt_window->display();
}


void Play::ifSnakeAteFood()
{
  	for( int i = 0; i < FOOD_AMOUNT; i++)
    {
        if(tab[i]->GetFoodBounds().intersects(snake->GetHeadFloatRect()))
        {
          sound.play();
          snake->AddBodyPart(tab[i]->getCurrentColor()); 
          food_respawn(tab[i]);
          levelUp();
        }
    } 
}

void Play::update()
{
     ifSnakeAteFood();
     updateScore();
     snake->Move();  
    
}

void Play::food_respawn(Food * food)
{
    Vector2f randomPosition;
  
    do
    {
      randomPosition = getRandomPosition(); 
      food->respawn(randomPosition);

    }while(snake->contains(food));



   
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
       title.setPosition(Game::SCRN_WIDTH/2-1.5*title.getGlobalBounds().width,40);
       title.setString(Game::getPlayerName() + " masz nowy record!"); 
       pnt_window->draw(title);
       pnt_window->display();
       sleep(seconds(2));
    }
    
}