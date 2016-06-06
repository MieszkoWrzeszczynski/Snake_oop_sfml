#pragma once

#include "Status.h"
#include "Snake.h"
#include "Game.h"
#include "Food.h"
#include "ExtraFood.h"
#include "Ranking.h"
#include <SFML/Audio.hpp>
#include <vector>

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
		static const int FOOD_AMOUNT = 5;

		Vector2f getRandomPosition();
		int  getEvents();

		void checkScoreInRank();
		void updateScore();
		void ifSnakeAteFood();
		void update();
		void draw();
		void render();
		void levelUp();
		void food_respawn(Food * food);
		void loadFood();
		void drawFood();
	
		Text title;
		Snake * snake;
		Food * tab[FOOD_AMOUNT];
		SoundBuffer buffer;
		Sound sound;
		Ranking rank;
};
