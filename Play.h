#pragma once

#include "Status.h"
#include "Snake.h"
#include "Game.h"
#include "Food.h"
#include "Ranking.h"
#include <SFML/Audio.hpp>

using namespace sf;

class Play : public Status
{

	public:
		Play(int status_type, RenderWindow & window,std::string window_title,Font & font);
		~Play();
 		void init();
 		
	private:
		int score;
		int fraps;
		bool paused;

		Vector2f getRandomPosition();
		int  getEvents(Event & event);

		void checkScoreInRank();
		void updateScore();
		void ifSnakeAteFood();
		void update();
		void draw();
		void render();
		void levelUp();
		void food_respawn();
	
		Text title;
		Snake * snake;
		Food  * food;	
		SoundBuffer buffer;
		Sound sound;
		Ranking rank;
};
