#pragma once
#include "Status.h"
#include "Snake.h"
#include "Game.h"
#include "Food.h"
#include <SFML/Audio.hpp>

class Play  : public Status
{

	public:
		Play(int status_type, RenderWindow & window,Font & font);
 		void init();

	private:
		void render();
		int  getEvents(Event & event);
		void ifSnakeAteFood();
		void update();
		void draw();
		void food_respawn(Snake & snake);
		Snake snake;
		Food  food;	
};
