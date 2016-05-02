#pragma once
#include "Status.h"
#include "Snake.h"
#include "Game.h"
#include "Food.h"
#include <SFML/Audio.hpp>

using namespace sf;

class Play : public Status
{

	public:
		Play(int id, RenderWindow & window,std::string window_title,Font & font);
		~Play();
 		void init();
 		void updateScore();

	private:
		void render();
		int  getEvents(Event & event);
		void ifSnakeAteFood();
		void update();
		void draw();
		int score;
		Text score_counter;
		void food_respawn(Snake * snake);
		Snake  * snake;
		Food   * food;	
		SoundBuffer buffer;
		Sound sound;
};
