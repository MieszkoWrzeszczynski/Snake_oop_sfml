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
 		Vector2f getRandomPosition();

	private:
		void render();
		int fraps;
		int  getEvents(Event & event);
		void ifSnakeAteFood();
		void update();
		void draw();
		void levelUp();
		int score;
		Text score_gui;
		void food_respawn(Snake * snake);
		Snake  * snake;
		Food   * food;	
		SoundBuffer buffer;
		Sound sound;
};
